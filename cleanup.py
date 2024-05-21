def fix_header_file(path):
    with open(path, 'r+') as file:
        flag = True
        lines = file.readlines()
        file.seek(0)
        file.truncate()
        for line in lines:
            if "struct" in line:
                flag = False
            if "#define" in line:
                flag = True
            if flag == True:
                file.write(line)

def fix_lib_file_0(path):
    with open(path, 'r+') as file:
        flag = False
        lines = file.readlines()
        file.seek(0)
        file.truncate()
        for idx, line in enumerate(lines):
            if idx != 0 and "int32" not in line and flag == False:
                file.write(line)
            if idx == 0:
                file.write("#include <stdint>")
            if flag == True:
                flag = False
            if "int32" in line:
                flag = True
