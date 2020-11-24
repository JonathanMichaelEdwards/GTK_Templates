import sys
import os



def genApp(appName, iconName):
    """
    Link output files and programs together.
    Append and link the App directory.
    """
    createApp = open("{0}.desktop".format(appName), 'w')

    createApp.write(
        "[Desktop Entry]\n" +
        "Name={0}\n".format(appName) +
        "Type=Application\n"  +
        "Terminal=false\n"    +
        "Exec=python3.8 {0}/run.py\n".format(os.getcwd().replace(" ", "\\ ")) +
        "Icon={0}/../graphics/images/{1}\n".format(os.getcwd(), iconName)
    )


    # Close all files
    createApp.close()



# Run script build.py
if __name__ == "__main__":   
    genApp(sys.argv[1], sys.argv[2])  # Generate Desktop App