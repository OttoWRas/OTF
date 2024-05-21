with open("./host/include/tvmgen_default.h", 'r+') as file:
    count = 0
    flag = True
    lines = file.readlines()
    file.seek(0)
    for line in lines:
        if "struct" in line:
            flag = False
        if "#define" in line and :
            flag = True
        if flag == True:
                flag = True
                file.write(line)
            else:
                file.write(line)

def clean_lib_file(path):
    return