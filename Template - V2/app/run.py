import sys
import os
import glob



def runProgram():
    """
    When the executable Desktop App is pressed in 
    the global System, e.g(can move the app program
    outside the project) the .exe ELF program is run 
    included with glade (xml) GUI code.
    """
    # Find the absolute path of the file
    _dir = os.path.dirname(os.path.abspath(__file__))
    fileName = glob.glob(f"{_dir}/*.desktop")[0].split('/')[-1]

    os.system("cd {0} && ../build/{1}.exe".format(_dir.replace(" ", "\\ "), fileName.split('.')[0]))


# Run script run.py
if __name__ == "__main__":
    runProgram()
