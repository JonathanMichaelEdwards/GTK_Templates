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
    # buildFile = "{0}/{1}".format(_dir, fileName)
    
    # # Read and run link exe objects
    # _file = open(fileName, 'r')
    
    # contents = _file.readlines()
    # # dirExe = contents[4].strip("Exec=python3.8 ").strip("run.py\n")
    # appExe = (contents[1].strip("Name=").replace(" ", "_")).strip('\n')
    os.system("cd {0} && ../build/{1}.exe".format(_dir.replace(" ", "\\ "), fileName.split('.')[0]))
    
    # Close file
    # _file.close()


# Run script run.py
if __name__ == "__main__":
    # Run App
    runProgram()
