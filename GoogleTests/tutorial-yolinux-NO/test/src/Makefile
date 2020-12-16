CXX = g++
#CXXFLAGS = -g -L/opt/gtest/lib -lgtest -lgtest_main -lpthread
CXXFLAGS = -g -L/usr/local/lib -lgtest -lgtest_main -lpthread
#INCS = -I./ -I../../src -I/opt/gtest/include
INCS = -I./ -I../../src -I/usr/local/include

OBJS = ../../src/Addition.o Addition_Test.o ../../src/Multiply.o Multiply_Test.o

testAll: $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCS) -o testAll  Main_TestAll.cpp $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
	rm -rf testAll *~ *.o testAll.xml
