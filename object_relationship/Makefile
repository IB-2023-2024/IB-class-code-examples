# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author F. de Sande
# @date Nov 29 2023
# @brief Makefile for these examples
# 
# @see https://www.gnu.org/software/make/
# @see http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CXX = g++						# The C++ compiler command
CXXFLAGS = -std=c++17  -O0		# The C++ compiler options (preserve debug symbols and No optimization)
LDFLAGS =						# The linker options (if any)

# The all target builds all of the programs handled by the makefile.
# This target has the dependency chain:
#     all -> hello -> hello.o -> hello.cc
all: access_specifiers adding_functionality baseball_player calling_base_function change_access_level deleted employee hiding_functionality inheritance_chain order_of_construction public_inheritance redefining_function

# The hello_world target builds the hello_world executable.
hello_world: hello_world.o
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
		rm -f access_specifiers adding_functionality baseball_player calling_base_function change_access_level deleted employee hiding_functionality inheritance_chain order_of_construction public_inheritance redefining_function
	rm -f a.out *.o *~ basura b i
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;

push:
	git pull 
	git add . 
	git commit -m "Code Fixings" 
	git push
