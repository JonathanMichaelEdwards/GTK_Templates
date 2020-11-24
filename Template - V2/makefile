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
BUILD_APP        = "---------------------------------------------------------- Making Desktop Application ----------------------------------------------------------"
COMPLETE_MESSAGE_COMPILE = Successfully Compiled Program...
COMPLETE_MESSAGE_APP     = Successfully Built Desktop App...
CLEANED_MESSAGE          = Successfully Cleaned Project...



# Default target.
all: clean build/$(APP_NAME).exe
	@echo "\n\n"
	@echo $(BUILD_APP)
	@echo $(PRINT_BEGIN)
	cd app && python3.8 build.py $(APP_NAME) $(APP_ICON) \
	&& chmod +x $(APP_NAME).desktop
	@echo $(PRINT_END)
	@echo $(COMPLETE_MESSAGE_APP)



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
	@echo $(COMPLETE_MESSAGE_COMPILE)
	

# Clean Project
.PHONY: CleanProject
clean:
	@echo $(REMOVE_MESSAGE)
	@echo $(PRINT_BEGIN)
	cd build && rm -f *.o *.exe && \
	cd ../app && rm -f *.desktop
	@echo $(PRINT_END)
	@echo "$(CLEANED_MESSAGE) \n\n\n"
	@echo $(OBJ_MESSAGE)
	@echo $(PRINT_BEGIN)
	

.PHONY: CleanProject_2
clean_2:
	@echo $(REMOVE_MESSAGE)
	@echo $(PRINT_BEGIN)
	cd build && rm -f *.o *.exe && \
	cd ../app && rm -f *.desktop
	@echo $(PRINT_END)
	@echo $(CLEANED_MESSAGE)
	