# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author F. de Sande
# @date 8 Jun 2020
# @brief A Makefile example for HelloWorld program
# 
# @see https://www.gnu.org/software/make/
# @see http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CXX = g++						# The C++ compiler command
CXXFLAGS = -std=c++17  -O0		# The C++ compiler options (preserve debug symbols and No optimization)
LDFLAGS =						# The linker options (if any)

# The all target builds all of the programs handled by the makefile.
# This target has the dependency chain:
#     all -> hello -> hello.o -> hello.cc
all: calculator change_1 change_2 change_3 const_member_functions constructor constructor_example constructor_initializations date_class date_struct default_constructor1 default_constructor2 destructor_example1 destructor_example2 employee_class fibonacci_class friend_function_example getters_setters initializer_list instance_creation int_array_class-bad int_array_class-good Matrix member_initializers move_constructor move_copy_operators move_error move_example static_local_variable static_member_function static_members static_members_utility stl_objects struct_example this_example1 this_example2 this_example3 type_member vector2

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
		rm -f calculator change_1 change_2 change_3 const_member_functions constructor constructor_example constructor_initializations date_class date_struct default_constructor1 default_constructor2 destructor_example1 destructor_example2 employee_class fibonacci_class friend_function_example getters_setters initializer_list instance_creation int_array_class-bad int_array_class-good Matrix member_initializers move_constructor move_copy_operators move_error move_example static_local_variable static_member_function static_members static_members_utility stl_objects struct_example this_example1 this_example2 this_example3 type_member vector2
	rm -f a.out *.o *~ basura b i
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;

push:
	git pull 
	git add . 
	git commit -m "Code Fixings" 
	git push
