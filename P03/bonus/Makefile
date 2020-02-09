#Avinash Aryal
SRC1 = main.cpp
SRC2 = color.cpp 
OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
EXE = $(SRC1:.cpp=.e)

HFILES = color.h
DEBUGS=-g
CFLAGS =  --std=c++17

all : $(EXE)
 
$(EXE): $(OBJ1) $(OBJ2) 
	g++ $(CFLAGS) $(OBJ1) $(OBJ2) -o $(EXE) 

$(OBJ1) : $(SRC1) $(HFILES)
	g++ -c $(CFLAGS) $(SRC1) -o $(OBJ1)
	
$(OBJ2) : $(SRC2) $(HFILES)
	g++ -c $(CFLAGS) $(SRC2) -o $(OBJ2) 

clean:
	rm -f *.e *.o *.gch ~* a.out main color



