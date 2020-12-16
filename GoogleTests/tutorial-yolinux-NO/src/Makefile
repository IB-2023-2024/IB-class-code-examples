CXX = g++
CXXFLAGS = -g
INCS = -I./
OBJS = Addition.o Multiply.o

exampleapp: ExampleApp.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -o exampleapp ExampleApp.cpp $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
	rm -rf *~ *.o exampleapp gmon.out
