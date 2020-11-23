import os
import build


APP_NAME = "template"



def runProgram():
    """
    When the executable Desktop App is pressed in 
    the global System, e.g(can move the app program
    outside the project) the .out ELF program is run 
    as well as glade xml GUI code.
    """
    # Find the absolute path of the file
    _dir = os.path.dirname(os.path.abspath(__file__))
    buildFile = "{0}/{1}".format(_dir, build.BUILD_FILE)

    # Read and run link exe objects
    _file = open(buildFile, 'r')

    contents = _file.readlines()
    # dirExe = contents[4].strip("Exec=python3.8 ").strip("run.py\n")
    # appExe = contents[1].strip("Name=\n").replace(' ', '_')
    os.system("cd ../build && ../build/{0}.exe".format(APP_NAME))
    
    # Close file
    _file.close()


# Run script run.py
if __name__ == "__main__":
    # Run App
    runProgram()
