# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author F. de Sande
# @date 17 Jun 2020
# @brief Header / Source files Separation
# 
# @see https://www.gnu.org/software/make/
# @see https://stackoverflow.com/questions/4349553/multiple-source-files-in-c-how-exactly-do-makefiles-work


# The name of the target program
TARGET  = myprog

# Select Compiler and flags
CC=g++
CFLAGS=-std=c++14 -g -Wall   # Compiler options (C++14, preserve debug symbols and warn all)


SRC = $(wildcard *.cc)
OBJ = $(SRC:.cc=.o)

# Special include directories
INCLUDE = -I.

# Special libraries (none for now)
LIB =

$(TARGET): main.o tools.o
	$(CC) -o $@ $^ $(LIB)

main.o: main.cc
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

tools.o: tools.cc tools.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)
	rm -f *~
