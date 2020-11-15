TARGET = app/Code_Manager.out

# Definitions.
CC = gcc
CFLAGS = -g -Wall -std=c99 -I./include -pthread
GTK_LIB = `pkg-config --cflags --libs gtk+-3.0` -rdynamic


# Default target.
all: $(TARGET)

# Compile: create object files from C source files.
app/optManage.o: src/optManage.c include/optManage.h
	$(CC) -c $(CFLAGS) $< -o $@ $(GTK_LIB) 

# Link: create ELF output file from object files.
$(TARGET): app/optManage.o
	$(CC) $^ -o $@ $(GTK_LIB) 
	cd app && python3.6 build.py build && chmod +x app/*.desktop


# Target: Clean Project.
.PHONY: cleanProject
clean:
	-rm -f app/*.o $(TARGET) 
	cd app && python3.6 build.py remove
	