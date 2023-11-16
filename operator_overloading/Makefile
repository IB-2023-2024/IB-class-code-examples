# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author F. de Sande
# @date Nov 16 2023
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
all: arithmetic_over_friend copy_assignment_operator copy_constructor custom_operator initializations operator_overloading_array10 operator_overloading_complex operator_overloading_vector2D operators_with_member_functions overloaded_comparison_friend overloaded_comparison_normal overloaded_unary point_input point_output_overload point_output_print

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
		rm -f arithmetic_over_friend copy_assignment_operator copy_constructor custom_operator initializations operator_overloading_array10 operator_overloading_complex operator_overloading_vector2D operators_with_member_functions overloaded_comparison_friend overloaded_comparison_normal overloaded_unary point_input point_output_overload point_output_print
	rm -f a.out *.o *~ basura b i
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;

push:
	git pull 
	git add . 
	git commit -m "Code Fixings" 
	git push
