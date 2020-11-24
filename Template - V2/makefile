#  ============================================================================
#  Author:       Jonathan Edwards
#  Date:         24/11/2020
#  Description:  Compiles and links all object files to create an ELF output 
#                file for Linux.
#  ============================================================================



# App details
APP_NAME = template
APP_ICON = folder.png


# Compiling and Linking Definitions
CC = g++
INCLUDES = -I./include
CFLAGS = -g -Wall -std=c++17 $(INCLUDES) -pthread
GTK_LIB = `pkg-config --cflags --libs gtk+-3.0` -rdynamic


# Printing pretty.
PRINT_BEGIN      = "==============================================================================================================================================="
PRINT_END        = "===============================================================================================================================================\n\n"
REMOVE_MESSAGE   = "-------------------------------------------------- Removing all object and executable files ---------------------------------------------------"
OBJ_MESSAGE      = "------------------------------------------------------------ Creating Object Files ------------------------------------------------------------"
LINK_OBJ_MESSAGE = "----------------------------------------------------------- Linkng all object files -----------------------------------------------------------"
COMPLETE_MESSAGE = Succesfully Compiled Program...



# Default target.
all: clean build/$(APP_NAME).exe
	@echo
	cd app && python3.8 build.py build $(APP_NAME) $(APP_ICON) && chmod +x $(APP_NAME).desktop


# Getting Object Name Automatically
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp, build/%.o, $(SOURCES))


build/%.o: src/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@ $(GTK_LIB) 
	


# Link Object Files
.PHONY: Link
build/$(APP_NAME).exe: $(OBJECTS)
	@echo $(PRINT_END)
	@echo $(LINK_OBJ_MESSAGE)
	@echo $(PRINT_BEGIN)
	$(CC) $^ -o $@ $(GTK_LIB) 
	@echo $(PRINT_END)
	@echo $(COMPLETE_MESSAGE)
	

# Clean Project
.PHONY: CleanProject
clean:
	@echo $(REMOVE_MESSAGE)
	@echo $(PRINT_BEGIN)
	cd build && rm -f *.o *.exe
	@echo $(PRINT_END)
	@echo $(OBJ_MESSAGE)
	@echo $(PRINT_BEGIN)
	
# cd app && python3.8 build.py remove
	