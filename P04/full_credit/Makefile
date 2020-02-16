#Avinash Aryal
CXXFLAGS+= --std=c++17
all=test
test: test.o coin.o *h
	$(CXX) $(CXXFLAGS) -DLOGGER test.o coin.o -o test
test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS)  -DLOGGER -c test.cpp -o test.o
coin.o: coin.cpp *.h
	$(CXX) $(CXXFLAGS)  -DLOGGER -c coin.cpp -o coin.o


clean:
	rm -f *.e *.o *.gch ~* a.out main color
