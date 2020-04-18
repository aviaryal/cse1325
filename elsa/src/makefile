
CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
all: main.e

debug: CXXFLAGS += -g
debug: main.e

main.e: main.o customer.o store.o order.o desktop.o options.o mainwin.o entryDialog.o ram.o *.h
	$(CXX) $(CXXFLAGS) main.o customer.o store.o order.o desktop.o options.o mainwin.o entryDialog.o ram.o $(GTKFLAGS) -o main.e
main.o: main.cpp *h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o
mainwin.o: mainwin.cpp *h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
entryDialog.o: entryDialog.cpp *h
	$(CXX) $(CXXFLAGS) -c entryDialog.cpp $(GTKFLAGS) -o entryDialog.o
store.o: store.cpp *h
		$(CXX) $(CXXFLAGS) -c store.cpp  -o store.o
customer.o: customer.cpp *h
	$(CXX) $(CXXFLAGS) -c customer.cpp -o customer.o
order.o: order.cpp *h
	$(CXX) $(CXXFLAGS) -c order.cpp -o order.o
desktop.o: desktop.cpp *h
	$(CXX) $(CXXFLAGS) -c desktop.cpp -o desktop.o
options.o: options.cpp *h
	$(CXX) $(CXXFLAGS) -c options.cpp -o options.o
ram.o: ram.cpp *h
	$(CXX) $(CXXFLAGS) -c ram.cpp -o ram.o


clean:
	-rm -f *.o *.e *.gch *~
