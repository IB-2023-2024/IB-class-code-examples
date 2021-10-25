CC = g++
CFLAGS = -Wall -std=c++14

all: blah

blah: blah.o

# Define a pattern rule that compiles every .c file into a .o file
%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm -f *.o *~ blah
