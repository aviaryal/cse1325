#Avinash Aryal
SRC1 = main.cpp
SRC2 = cart.cpp
SRC3 = items.cpp

OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
OBJ3 = $(SRC3:.cpp=.o)

EXE = $(SRC1:.cpp=.e)

HFILES = cart.h items.h
CFLAGS =  --std=c++17
debug: CFLAGS += -g
debug:$(EXE)


all : $(EXE)

$(EXE): $(OBJ1) $(OBJ2) $(OBJ3)
	g++ $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) -o $(EXE)

$(OBJ1) : $(SRC1) $(HFILES)
	g++ -c $(CFLAGS) $(SRC1) -o $(OBJ1)

$(OBJ2) : $(SRC2) $(HFILES)
	g++ -c $(CFLAGS) $(SRC2) -o $(OBJ2)

$(OBJ3) : $(SRC3) $(HFILES)
	g++ -c $(CFLAGS) $(SRC3) -o $(OBJ3)


clean:
	rm -f *.e *.o *.gch ~* a.out main color
