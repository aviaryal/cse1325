
CXXFLAGS += -std=c++17

all: main.e

debug: CXXFLAGS += -g
debug: main.e

main.e: main.o customer.o store.o order.o desktop.o options.o *.h
	$(CXX) $(CXXFLAGS) main.o customer.o store.o order.o desktop.o options.o -o main.e
main.o: main.cpp *h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
store.o: store.cpp *h
		$(CXX) $(CXXFLAGS) -c store.cpp -o store.o
customer.o: customer.cpp *h
	$(CXX) $(CXXFLAGS) -c customer.cpp -o customer.o
order.o: order.cpp *h
	$(CXX) $(CXXFLAGS) -c order.cpp -o order.o
desktop.o: desktop.cpp *h
	$(CXX) $(CXXFLAGS) -c desktop.cpp -o desktop.o
options.o: options.cpp *h
	$(CXX) $(CXXFLAGS) -c options.cpp -o options.o



clean:
	-rm -f *.o *.e *.gch *~
