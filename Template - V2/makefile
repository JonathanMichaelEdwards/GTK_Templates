#  ============================================================================
#  Author:       Jonathan Edwards
#  Date:         14/11/2020
#  Description:  Compiles and links all object files to create an ELF output 
#                file for Linux.
#  ============================================================================



# # App Name
# TARGET = main



# # Compiling and Linking Definitions.
# CC = g++ $(INCLUDES)
# CFLAGS = -g -Wall -std=c++11
# INCLUDES = -I./../include
# OPENGL_LIB = -lGL -lGLU -lGLEW -lglut
# exe = -no-pie  # changes (x-libshare -> x-executable)

# # Getting Object Name Automatically.
# SOURCES_LOCATION  = ../src
# SOURCES = $(wildcard $(SOURCES_LOCATION)/*.cpp)
# OBJECTS = $(patsubst $(SOURCES_LOCATION)/%.cpp, %.o, $(SOURCES))


# # Printing pretty.
# PRINT_BEGIN      = "======================================================================================================================"
# PRINT_END        = "======================================================================================================================\n\n"
# REMOVE_MESSAGE   = "-------------------------------------- Removing all object and executable files --------------------------------------"
# LINK_NAN_MESSAGE = "------------------------------------------ Creating non linked object files ------------------------------------------"
# LINK_OBJ_MESSAGE = "-------------------------------- Linkng all object files to create an executable file --------------------------------"
# COMPLETE_MESSAGE = Succesfully Compiled Program...



# Definitions.
CC = g++
INCLUDES = -I./include -I./include/Dialog -I./include/Create_Project
CFLAGS = -g -Wall -std=c++17 $(INCLUDES) -pthread
GTK_LIB = `pkg-config --cflags --libs gtk+-3.0` -rdynamic


# Default target.
all: template.exe
# cd app && python3.6 build.py build && chmod +x app/*.desktop


# Compile: create object files from C source files.
app/main.o: src/main.c
	$(CC) -c $(CFLAGS) $< -o $@ $(GTK_LIB) 

app/manager.o: src/manager.c
	$(CC) -c $(CFLAGS) $< -o $@ $(GTK_LIB) 



# Link: create ELF output file from object files.
template.exe: app/main.o app/manager.o
	$(CC) -no-pie $^ -o $@ $(GTK_LIB) 
	

# Target: Clean Project.
.PHONY: cleanProject
clean:
	cd app && rm -f *.o *.out
# cd app && python3.6 build.py remove
	





# # Default target.
# all: clean $(TARGET)
# 	@echo $(COMPLETE_MESSAGE)


# # Compile: create object files from C source files.
# %.o: $(SOURCES_LOCATION)/%.cpp
# 	$(CC) -c -o $@ $< $(CFLAGS)


# # Link: create ELF output file from object files.
# $(TARGET): $(OBJECTS)
# 	@echo $(PRINT_END)
# 	@echo $(LINK_OBJ_MESSAGE)
# 	@echo $(PRINT_BEGIN)
# 	$(CC) $(exe) -o $@ $^ $(OPENGL_LIB) 
# 	@echo $(PRINT_END)
	

# # Target: Clean Project.
# .PHONY: cleanProject
# clean:
# 	@echo $(REMOVE_MESSAGE)
# 	@echo $(PRINT_BEGIN)
# 	-rm -f *.o main
# 	@echo $(PRINT_END)
# 	@echo $(LINK_NAN_MESSAGE)
# 	@echo $(PRINT_BEGIN)