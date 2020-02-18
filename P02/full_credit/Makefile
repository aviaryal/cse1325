#avinash aryal 1001727418

CXXXFLAGS = --std = c++17

all: main

main: main.o color.o
	$(CXX) $(CXXFLAGS) -DLOGGER main.o color.o -o main
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -DLOGGER -c main.cpp -o main.o
color.o: color.cpp
	$(CXX) $(CXXFLAGS) -DLOGGER -c color.cpp -o color.o
color.gch: color.h
	$(CXX) $(CXXFLAGS) -DLOGGER -c color.h -o color.gch
clean:
	rm -f *.o *.gch *~ main
