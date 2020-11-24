import sys
import os

# Defines
# BUILD_FILE = "app.txt"
# ICON_FILE_NAME = 

# # Usable Icons
# dirIcons = "Icon=graphics/{0}/images".format(os.getcwd())
# icon1 = "{0}/{1}\n".format(dirIcons, ICON_FILE_NAME)


# def getNameOfApp(_file):
#     """
#     Get the name of the app from the file.
#     return -> (fileRead, fRead, appName)
#     """
#     fileRead = open(_file, 'r')
#     fRead = fileRead.readlines()
#     appName = fRead[1].strip("Name=\n")

#     return (fileRead, fRead, appName)


def genApp(appName, iconName):
    """
    Link output files and programs together.
    Append and link the App directory.
    """
    # appExists = False
    # (fileRead, fRead, appName) = getNameOfApp(BUILD_FILE)


        
    createApp = open("{0}.desktop".format(appName), 'w')


    _dir = os.getcwd().replace(" ", "\\ ")
    createApp.write(
        "[Desktop Entry]\n" +
        "Name={0}\n".format(appName) +
        "Type=Application\n"  +
        "Terminal=false\n"    +
        "Exec=python3.8 {0}/run.py\n".format(_dir) +
        "Icon={0}/../graphics/images/{1}".format(_dir, iconName)
    )



    # defaultFile = open(BUILD_FILE, 'w')

    # createFile(fRead, createApp, defaultFile)


    # Close all files
    createApp.close()
    
    
def createFile(fRead, createApp, defaultFile):
    """
    Append and Write new content to existing/valid 
    files.
    """ 
    # Write to files
    runCmd = "Exec=python3.8 {0}/run.py\n".format(os.getcwd().replace(" ", "\\ "))
    files = [createApp, defaultFile]
    for _file in files:
        _file.writelines(fRead)
        _file.write(runCmd)
        _file.write(icon1)


def remFile():
    """
    Remove all App's in directory.
    """
    cmd = "rm *.desktop"
    os.system(cmd)


def resetFile():
    """
    Reset the BUID File to it's default settings.
    """
    (fileR, contents, _) = getNameOfApp(BUILD_FILE)
    fileW = open(BUILD_FILE, 'w')

    # Write the default settings
    fileW.writelines(contents[:4])

    # Close all files
    fileW.close()
    fileR.close()


# Run script build.py
if __name__ == "__main__":
    if sys.argv[1] == "build":      # Generate Desktop App
        genApp(sys.argv[2], sys.argv[3])
    elif sys.argv[1] == "remove":   # Remove Desktop App
        remFile()
        resetFile()
