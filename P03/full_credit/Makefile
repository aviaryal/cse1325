#avinash aryal 1001727418

CXXXFLAGS = --std = c++17

all: main

main: main.o color.o
	$(CXX) $(CXXFLAGS) main.o color.o -o main
main.o: main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
color.o: color.cpp 
	$(CXX) $(CXXFLAGS) -c color.cpp -o color.o
color.gch: color.h
	$(CXX) $(CXXFLAGS) -c color.h -o color.gch
clean:
	rm -f *.o *.gch *~ main


