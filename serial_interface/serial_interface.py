'''
Application developed by Luca Pezzarossa
for the course 02203 - Design of Digital Systems
at the Technical University of Denmark.

Version 1.0 - 2017

To report bugs, contact: lpez@dtu.dk

This application allows the download and the upload of a
P2-type PGM image of size 352x288 pixels using the serial
port.
--------------------------------------------------------------------------
Copyright 2017 Luca Pezzarossa

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
--------------------------------------------------------------------------
'''

from appJar import gui
import sys
import glob
import serial
import re
from PIL import Image, ImageTk
import tkinter as tk
import time
import threading
import numpy as np
import cv2
import struct

################################################################################
# Configuration constants
testChar = b't'
testCharAns = b'y'
downloadChar = b'w'
uploadChar = b'r'
clearChar = b'c'
setDownChar = b's'
setUpChar = b'u'
startAccChar = b'm'

################################################################################
# Variables
download_image = b'0'
upload_image = b'0'
donwload_size = 0
upload_size = 40
result = ""

download_progress = 0
upload_progress = 0

fig_d_app = None
fig_u_app = None
help_app = None

current_port = ""

serial_available = False  # If false, the list of serials is empty
serial_free = True

###########################################################
help_text = """Serial interface help

-Purpose
This application allows the download and the upload of a
P2-type PGM image of size 352x288 pixels using the serial
port.

-Usage
The application is divided into 3 section: 1) Setup serial
connection to the FPGA board, 2) Download image to the
FPGA board, and 3) Upload image from the FPGA board. The
functionality of these three sections is explained in
the following.

1) Setup serial connection to the FPGA board:
In this section you can setup the connection to the FPGA
board. The FPGA board needs to be connected and the FPGA
needs to be configured in order for the application be
able to interact with the serial port.

All the serial ports are listed in the drop-menu at the
top of this section. By pressing the button 'Refresh list'
you can update the entries of the list in case you connect
new devices.

Once you have selected the serial port of your board you
can test if the FPGA board is connected to the selected
serial port by pressing the button 'Test port'.

By pressing the button 'Clear entire memory content' you
can clear the entire FPGA board memory content (reset all
entries to 0).

2) Download image to the FPGA board:
In this section you can open a PGM image by pressing the
button 'Open...' and download it to the FPGA board by
pressing the button 'Download image'. The download takes
about 7 seconds and the status is shown in the progress
bar.

By pressing the button 'Show image', you can see a preview
of the download image. The button 'Reset' of this section
resets only this section of the application.

3) Upload image from the FPGA board:
In this section you can upload a PGM image form the FPGA
board by pressing the button 'Upload image' and save it to
a file by pressing the button 'Save...'. The upload takes
about 7 seconds and the status is shown in the progress
bar.

By pressing the button 'Show image', you can see a preview
of the uploaded image. The button 'Reset' of this section
resets only this section of the application.

-License
Copyright 2017 Luca Pezzarossa

Licensed under the Apache License, Version 2.0
(the "License"); you may not use this file except in
compliance with the License. You may obtain a copy of
the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on
an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied. See the License for the
specific language governing permissions and limitations
under the License.
"""

about_text = """Application developed by Luca Pezzarossa
for the course 02203 - Design of Digital Systems
at the Technical University of Denmark.

Version 1.0 - 2017

To report bugs, contact: lpez@dtu.dk

Copyright 2017 Luca Pezzarossa under the Apache License,
Version 2.0 (see help for details).

The GUI was developed using appJar."""

################################################################################
# This function returns the list of all available serial ports.


def serial_ports():
    global serial_available
    global serial_free
    serial_free = False
    #global serial_available
    """ Lists serial port names

        :raises EnvironmentError:
            On unsupported or unknown platforms
        :returns:
            A list of the serial ports available on the system
    """
    if sys.platform.startswith('win'):
        ports = ['COM%s' % (i + 1) for i in range(256)]
    elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
        # this excludes your current terminal "/dev/tty"
        ports = glob.glob('/dev/tty[A-Za-z]*')
    elif sys.platform.startswith('darwin'):
        ports = glob.glob('/dev/tty.*')
    else:
        app.errorBox("Error!", "Unsupported or unknown platform.")
        result = ["-No serial ports available-"]
        serial_available = False
        serial_free = True
        return result

    result = []
    for port in ports:
        try:
            s = serial.Serial(port)
            s.close()
            result.append(port)
        except (OSError, serial.SerialException):
            pass
    if len(result) == 0:
        result = ["-No serial ports available-"]
        serial_available = False
    else:
        serial_available = True
    serial_free = True
    return result


def resetDownload(button):
    global download_image
    global download_progress
    download_image = b'0'
    download_progress = 0
    app.setEntry("entry_d1", "Select PGM image to download.",
                 callFunction=False)
    return


def resetUpload(button):
    global upload_image
    global upload_progress
    upload_image = b'0'
    upload_progress = 0
    app.setEntry(
        "entry_u1", "Select where to save the uploaded PGM image.", callFunction=False)
    return


def openDownloadFile(button):
    download_file = app.openBox(title="Open PGM image", dirName=None, fileTypes=[
                                ('images', '*.pgm')], asFile=False)
    if download_file != "":
        try:
            with open(download_file, "r") as f:
                file_content = f.readlines()
            f.close()
        except Exception as e:
            app.errorBox("Error!", "The selected file cannot be opened.")
            return
        file_content = ''.join(file_content)
        file_content = re.sub('#.*?\n', ' ', file_content)
        file_content = re.sub('#.*? ', ' ', file_content)
        file_content = file_content.replace('\n', ' ')
        file_content = re.sub('\s\s+', ' ',  file_content)
        file_content_list = file_content.split(" ")
        file_content = None
        while '' in file_content_list:
            file_content_list.remove('')

        # we start with correctness checks
        if (len(file_content_list) != 101380):
            app.errorBox("Error!", "The size of the PGM image is not correct.")
            return
        if (file_content_list[0] != "P2"):
            app.errorBox("Error!", "The selected file is not a P2 PGM image.")
            return
        if (file_content_list[1] != "352" or file_content_list[2] != "288"):
            app.errorBox("Error!", "The size of the PGM image is not 352x288.")
            return
        if (file_content_list[3] != "255"):
            app.errorBox(
                "Error!", "The maximum range of the PGM image is not 255.")
            return
        for i in range(4, len(file_content_list)):
            if (int(file_content_list[i]) > 255):
                app.errorBox(
                    "Error!", "The PGM image contains values that exceed 255.")
                return
        del file_content_list[0]
        del file_content_list[0]
        del file_content_list[0]
        del file_content_list[0]

        # the PGM image is corret and can be loaded
        file_content_list_int = [int(p) for p in file_content_list]
        global download_image
        download_image = bytes(file_content_list_int)

        app.setEntry("entry_d1", download_file, callFunction=False)
        return
    else:
        return

def openDownloadFile2(button):
    download_file = app.openBox(title="Open PNG image", dirName=None, fileTypes=[
                                ('images', '*.png')], asFile=False)
    if download_file != "":
        image = cv2.imread(download_file)
        gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        gray = cv2.resize(gray, (28,28)).astype(np.float32)/255
        input = np.reshape(gray, (1,1,28,28))
        global download_image
        global donwload_size
        download_image = input.tobytes()
        donwload_size = len(download_file)
        app.setEntry("entry_d1", download_file, callFunction=False)
        return
    else:
        return

def saveUploadFile(button):
    global upload_image
    upload_file = app.saveBox(title="Save PGM image", dirName=None, fileName="PGM_image.pgm",
                              fileExt=".pgm", fileTypes=[('images', '*.pgm')], asFile=False)
    if upload_file != "":
        try:
            with open(upload_file, "w") as f:
                f.write("P2\n# Uploaded PGM image\n352 288\n255\n")
                for i in range(0, len(upload_image)):
                    f.write(str(int(upload_image[i])) + '\n')
            f.close()
        except Exception as e:
            app.errorBox("Error!", "The selected file cannot be opened.")
            return
        app.setEntry("entry_u1", upload_file, callFunction=False)
        return
    else:
        return


def showDownloadImage(button):
    global fig_d_app
    global download_image
    if fig_d_app is not None:
        fig_d_app.destroy()
        fig_d_app = None
    fig_d_app = tk.Toplevel()
    fig_d_app.title("Show download image")
    fig_d_app.resizable(False, False)
    image_file = Image.frombytes('L', (352, 288), download_image, 'raw')
    photo_image = ImageTk.PhotoImage(image_file)
    label = tk.Label(fig_d_app, image=photo_image)
    label.pack()
    fig_d_app.mainloop()
    return

def showDownloadImage2(button):
    cv2.imshow("Image", download_image)
    return

def showUploadImage(button):
    global fig_u_app
    global upload_image
    if fig_u_app is not None:
        fig_u_app.destroy()
        fig_u_app = None
    fig_u_app = tk.Toplevel()
    fig_u_app.title("Show upload image")
    fig_u_app.resizable(False, False)
    image_u_file = Image.frombytes('L', (352, 288), upload_image, 'raw')
    photo_u_image = ImageTk.PhotoImage(image_u_file)
    label = tk.Label(fig_u_app, image=photo_u_image)
    label.pack()
    fig_u_app.mainloop()
    return


def showHelp():
    global help_app
    if help_app is not None:
        help_app.destroy()
        help_app = None
    help_app = tk.Toplevel()  # tk.Tk()#gui("Show figure")#S, "500x500")
    help_app.title("Serial interface help")
    help_app.resizable(False, False)
    S = tk.Scrollbar(help_app)
    T = tk.Text(help_app, height=25, width=60)
    S.pack(side=tk.RIGHT, fill=tk.Y)
    T.pack(side=tk.LEFT, fill=tk.Y)
    S.config(command=T.yview)
    T.config(yscrollcommand=S.set)
    T.insert(tk.END, help_text)
    T.configure(state="disabled")
    help_app.mainloop()
    return


def bottom_press(button):
    if button == "Help":
        showHelp()
        return
    if button == "About":
        app.infoBox("About", about_text)
        return
    if button == "Exit":
        app.stop()
        return
    return


def refreshSerialListTh():
    global serial_free
    serial_free = False
    app.changeOptionBox("list_serial_s", ["-Refreshing list...-"])
    serial_ids = serial_ports()
    app.changeOptionBox("list_serial_s", serial_ids)
    app.setEntry(
        "entry_s1", "Test if the FPGA board is connected to this serial port.", callFunction=False)
    serial_free = True
    return


def refreshSerialList(button):
    serTh = threading.Thread(target=refreshSerialListTh)
    serTh.daemon = True
    serTh.start()
    return

def runAccSerial():
    global serial_free
    serial_free = False
    try:
        if not(serial_available):
            app.errorBox("Error!", "No serial ports available.")
        else:
            testSerial_cnt = 10
            while(not(testSerial())):
                testSerial_cnt = testSerial_cnt - 1
                if testSerial_cnt == 0:
                    break
                time.sleep(0.1)
            if testSerial():
                ser = serial.Serial(port=app.getOptionBox("list_serial_s"), baudrate=115200,
                                    bytesize=8, parity='N', stopbits=1, timeout=None, xonxoff=0, rtscts=0)
                ser.reset_input_buffer()
                ser.reset_output_buffer()
                ser.write(startAccChar)
                ser.close()             # close port
            else:
                app.errorBox(
                    "Error!", "Impossible to communicate with the FPGA board on the selected serial port.")
    except:
        app.errorBox(
            "Error!", "Impossible to communicate on the selected serial port.")
    serial_free = True
    return

def downloadSerialTh():
    global download_progress
    global download_image
    global donwload_size
    download_progress = 0
    global serial_free
    serial_free = False
    # time.sleep(10)
    try:
        if not(serial_available):
            app.errorBox("Error!", "No serial ports available.")
        else:
            testSerial_cnt = 10
            while(not(testSerial())):
                testSerial_cnt = testSerial_cnt - 1
                if testSerial_cnt == 0:
                    break
                time.sleep(0.1)
            if testSerial():
                ser = serial.Serial(port=app.getOptionBox("list_serial_s"), baudrate=115200,
                                    bytesize=8, parity='N', stopbits=1, timeout=None, xonxoff=0, rtscts=0)
                ser.reset_input_buffer()
                ser.reset_output_buffer()
                ser.write(setDownChar)
                ser.write(donwload_size.to_bytes(1, 'big'))
                ser.reset_input_buffer()
                ser.reset_output_buffer()
                ser.write(downloadChar)
                for i in range(0, donwload_size):
                    ser.write(download_image[i * donwload_size:(i + 1) * donwload_size])
                    download_progress = int(100 * (i / (donwload_size - 1)))
                ser.close()             # close port
            else:
                app.errorBox(
                    "Error!", "Impossible to communicate with the FPGA board on the selected serial port.")
    except:
        app.errorBox(
            "Error!", "Impossible to communicate on the selected serial port.")
    serial_free = True
    return


def clearMemoryTh():
    global serial_free
    serial_free = False
    try:
        if not(serial_available):
            app.errorBox("Error!", "No serial ports available.")
        else:
            testSerial_cnt = 10
            while(not(testSerial())):
                testSerial_cnt = testSerial_cnt - 1
                if testSerial_cnt == 0:
                    break
                time.sleep(0.1)
            if testSerial():
                ser = serial.Serial(port=app.getOptionBox("list_serial_s"), baudrate=115200,
                                    bytesize=8, parity='N', stopbits=1, timeout=None, xonxoff=0, rtscts=0)
                ser.reset_input_buffer()
                ser.reset_output_buffer()
                ser.write(clearChar)
                time.sleep(1)
                ser.close()             # close port
            else:
                app.errorBox(
                    "Error!", "Impossible to communicate with the FPGA board on the selected serial port.")
    except:
        app.errorBox(
            "Error!", "Impossible to communicate on the selected serial port.")
    serial_free = True
    return


def uploadSerialTh():
    global upload_progress
    global upload_image
    upload_progress = 0
    global serial_free
    serial_free = False
    try:
        if not serial_available:
            app.errorBox("Error!", "No serial ports available.")
        else:
            testSerial_cnt = 10
            while(not(testSerial())):
                testSerial_cnt = testSerial_cnt - 1
                if testSerial_cnt == 0:
                    break
                time.sleep(0.1)
            if testSerial():
                ser = serial.Serial(port=app.getOptionBox("list_serial_s"), baudrate=115200,
                                    bytesize=8, parity='N', stopbits=1, timeout=1, xonxoff=0, rtscts=0)
                ser.reset_input_buffer()
                ser.reset_output_buffer()
                ser.write(setUpChar)
                ser.write(donwload_size.to_bytes(1, 'big'))                
                ser.reset_input_buffer()
                ser.reset_output_buffer()
                ser.write(uploadChar)
                # reading from serial
                upload_image_size = 0
                read_data = ser.read(20)
                upload_image_tmp = bytearray(b'')
                if len(read_data) == 0:
                    # i did timeout
                    app.errorBox(
                        "Error!", "No data were received on the selected serial port.")
                else:
                    while (len(read_data) != 0 and upload_image_size < upload_size):
                        upload_image_tmp.extend(read_data)
                        upload_image_size = upload_image_size + len(read_data)
                        upload_progress = int(
                            99 * (upload_image_size / upload_size))
                        read_data = ser.read(upload_size)
                    upload_progress = 100
                    # I need to do some checks
                    if len(upload_image_tmp) < upload_size:
                        app.errorBox(
                            "Error!", "No enough data were received on the selected serial port.")
                        upload_image = bytes(b'0')
                    elif len(upload_image_tmp) > upload_size:
                        app.errorBox(
                            "Error!", "Too much data were received on the selected serial port.")
                        upload_image = bytes(upload_image_tmp)
                    else:
                        upload_image = bytes(upload_image_tmp)
                ser.close()             # close port
            else:
                app.errorBox(
                    "Error!", "Impossible to communicate with the FPGA board on the selected serial port.")
    except:
        app.errorBox(
            "Error!", "Impossible to communicate on the selected serial port.")
    serial_free = True
    #data = [upload_image[i:i+4] for i in range(0, len(upload_image), 4)]
    print(upload_image)
    
    app.setMessage("msg_u1", "test")
    return


def updateMeters():
    app.setMeter("meter_d1", download_progress)
    app.setMeter("meter_u1", upload_progress)
    return


def downloadSerial(button):
    dwTh = threading.Thread(target=downloadSerialTh)
    dwTh.daemon = True
    dwTh.start()
    return


def uploadSerial(button):
    upTh = threading.Thread(target=uploadSerialTh)
    upTh.daemon = True
    upTh.start()
    return


def clearMemory(button):
    clTh = threading.Thread(target=clearMemoryTh)
    clTh.daemon = True
    clTh.start()
    return


def testSerial():
    ser = serial.Serial(port=app.getOptionBox("list_serial_s"), baudrate=115200,
                        bytesize=8, parity='N', stopbits=1, timeout=0.5, xonxoff=0, rtscts=0)
    ser.reset_input_buffer()
    ser.reset_output_buffer()
    ser.write(testChar)
    s = ser.read(1)
    ser.reset_input_buffer()  # flush input buffer, discarding all its contents
    # flush output buffer, aborting current output and discard all that is in buffer
    ser.reset_output_buffer()
    ser.close()             # close port
    if s == testCharAns:
        return True
    else:
        return False


def testSerialButton(button):
    testTh = threading.Thread(target=testSerialTh)
    testTh.daemon = True
    testTh.start()
    return


def testSerialTh():
    global serial_free
    serial_free = False
    try:
        if not serial_available:
            app.setEntry(
                "entry_s1", "Impossible to test. No serial ports available.", callFunction=False)
        else:
            app.setEntry("entry_s1", "Testing...", callFunction=False)
            testSerial_cnt = 10
            while(not(testSerial())):
                testSerial_cnt = testSerial_cnt - 1
                if testSerial_cnt == 0:
                    break
                time.sleep(0.1)
            if testSerial():
                app.setEntry(
                    "entry_s1", "The FPGA board is connected to this serial port.", callFunction=False)
            else:
                app.setEntry(
                    "entry_s1", "The FPGA board is NOT connected to this serial port.", callFunction=False)
    except:
        app.errorBox(
            "Error!", "Impossible to communicate on the selected serial port.")
        app.setEntry(
            "entry_s1", "Test if the FPGA board is connected to this serial port.", callFunction=False)
    serial_free = True
    return


def updateTestLabel():
    global current_port
    if current_port != app.getOptionBox("list_serial_s"):
        app.setEntry(
            "entry_s1", "Test if the FPGA board is connected to this serial port.", callFunction=False)
        current_port = app.getOptionBox("list_serial_s")
    return


def updateEnableDisable():
   ## if len(download_image) != 101376:
   ##     download_image_exists = False
   ## else:
    download_image_exists = True
    if len(upload_image) != 101376:
        upload_image_exists = False
    else:
        upload_image_exists = True

    # Start
    # Serial list
    if (serial_available and serial_free):
        app.enableOptionBox("list_serial_s")
    else:
        app.disableOptionBox("list_serial_s")
    # Button: Test
    if serial_available and serial_free:
        app.enableButton("button_s2")
    else:
        app.disableButton("button_s2")
    # Button: Refresh
    if serial_free:
        app.enableButton("button_s1")
    else:
        app.disableButton("button_s1")
    # Button: Open
    if serial_free:
        app.enableButton("button_d1")
    else:
        app.disableButton("button_d1")
    # Button: Download
    if serial_available and serial_free and download_image_exists:
        app.enableButton("button_d3")
    else:
        app.disableButton("button_d3")
    # Button: Download Show
    if serial_free and download_image_exists:
        app.enableButton("button_d2")
    else:
        app.disableButton("button_d2")
    # Button: Download Reset
    if serial_free:
        app.enableButton("button_d4")
    else:
        app.disableButton("button_d4")
    # Button: Upload
    if serial_available and serial_free:
        app.enableButton("button_u3")
    else:
        app.disableButton("button_u3")
    # Button: Run acc show
    if serial_free and serial_free:
        app.enableButton("button_u2")
    else:
        app.disableButton("button_u2")
    # Button: Upload Reset
    if serial_free:
        app.enableButton("button_u4")
    else:
        app.disableButton("button_u4")
    # Button: Clear content
    if serial_available and serial_free:
        app.enableButton("button_g1")
    else:
        app.disableButton("button_g1")
    return

################################################################################
# Serial App in Python


# create a GUI variable called app
app = gui("Serial interface")  # S, "500x500")
app.setFont(10)
# app.setIcon(fileName)
app.setSticky("ew")

row = -1

# Setup serial section
row = row + 1
app.addLabel("label_s_title",
             "Setup serial connection to the FPGA board", row, 0, 4)
app.setLabelAlign("label_s_title", "left")

row = row + 1
app.addLabel("label_s1", "Serial port:", row, 0)
app.setLabelAlign("label_s1", "right")
app.addOptionBox("list_serial_s", ["-No serial ports available-"], row, 1, 2)
app.addNamedButton("Refresh list", "button_s1", refreshSerialList, row, 3)

row = row + 1
app.addLabel("label_s2", "Test serial port:", row, 0)
app.setLabelAlign("label_s2", "right")
app.addEntry("entry_s1", row, 1, 2)
app.setEntry(
    "entry_s1", "Test if the FPGA board is connected to this serial port.", callFunction=False)
app.disableEntry("entry_s1")
app.addNamedButton("Test port", "button_s2", testSerialButton, row, 3)

# Row 0
row = row + 1
app.addLabel("label_g1", "Other:", row, 0)
app.setLabelAlign("label_g1", "right")
app.addNamedButton("Clear entire memory content",
                   "button_g1", clearMemory, row, 1, 4)

# Download section
row = row + 1
app.addHorizontalSeparator(row, 0, 4)
row = row + 1
app.addLabel("label_d_title", "Download image to the FPGA board", row, 0, 4)
app.setLabelAlign("label_d_title", "left")

# Row 0
row = row + 1
app.addLabel("label_d1", "Image to download:", row, 0)
app.setLabelAlign("label_d1", "right")
app.addEntry("entry_d1", row, 1, 2)
app.setEntryWidth("entry_d1", 60)
app.setEntry("entry_d1", "Select PGN image to download.", callFunction=False)
app.disableEntry("entry_d1")
app.addNamedButton("Open...", "button_d1", openDownloadFile2, row, 3)

# Row 1
row = row + 1
app.addLabel("label_d2", "Actions:", row, 0)
app.setLabelAlign("label_d2", "right")
app.addNamedButton("Download image", "button_d3", downloadSerial, row, 1)
app.addNamedButton("Show image", "button_d2", showDownloadImage2, row, 2)
app.addNamedButton("Reset", "button_d4", resetDownload, row, 3)

# Row 2
row = row + 1
app.addLabel("label_d3", "Download status:", row, 0)
app.setLabelAlign("label_d3", "right")
app.addMeter("meter_d1", row, 1, 3)

# Upload section
row = row + 1
app.addHorizontalSeparator(row, 0, 4)
row = row + 1
app.addLabel("label_u_title", "Upload image from the FPGA board", row, 0, 4)
app.setLabelAlign("label_u_title", "left")
# Row 0
row = row + 1
app.addLabel("label_u2", "Actions:", row, 0)
app.setLabelAlign("label_u2", "right")
app.addNamedButton("Upload image", "button_u3", uploadSerial, row, 1)
app.addNamedButton("Run Accelerator", "button_u2", runAccSerial, row, 2)
app.addNamedButton("Reset", "button_u4", resetUpload, row, 3)

# Row 2
row = row + 1
app.addLabel("label_u3", "Upload status:", row, 0)
app.setLabelAlign("label_u3", "right")
app.addMeter("meter_u1", row, 1, 3)

# Row 0
row = row + 1
app.addLabel("label_u1", "Results:", row, 0)
app.setLabelAlign("label_u1", "right")
app.addMessage("msg_u1", "")

# Bottom line
row = row + 1
app.addHorizontalSeparator(row, 0, 4)

# Bottom buttons
row = row + 1
app.addButtons(["Help", "About", "Exit"], bottom_press, row, 0, 4)

refreshSerialList(None)
app.registerEvent(updateMeters)
app.registerEvent(updateTestLabel)
app.registerEvent(updateEnableDisable)

app.setResizable(False)

app.setLogLevel("ERROR")

# start the GUI
app.go()
