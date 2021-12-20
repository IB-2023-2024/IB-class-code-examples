# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author F. de Sande
# @date 10 Dec 2020
# @brief A Makefile for the Persona class code
# 

CXX = g++						                              # The C++ compiler command
CXXFLAGS = -std=c++17 -g -Wall -pedantic -Weffc++ # The C++ compiler options (C++14, preserve debug symbols and warn all)
LDFLAGS =						                              # The linker options (if any)

# The all target builds all of the programs handled by the makefile.
all: persona_main

persona_main: persona.o persona_main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Indicate that the all and clean targets do not
# correspond to actual files.
.PHONY: all clean

# The following rule is effectively built into make and
# therefore need not be explicitly specified:
# hello_world.o: hello_world.cc
#
	$(CXX) $(CXXFLAGS) -c $<

# The clean target removes all of the executable files
# and object files produced by the build process
# We can use it for additional housekeeping purposes
clean :
	rm -f *.o persona_main doc
	rm -rf *~ basura b i
	rm -rf a.out
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;
