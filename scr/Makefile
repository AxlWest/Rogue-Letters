# The compiler (CXX) is using g++
CXX = g++

# CFLAGS will be options passed to the compiler
CXXFLAGS = -c -Wall
OBJS = Main.o Game.o Player.o InventorySlot.o

all: RogueLetters

RogueLetters: Main.o Game.o Player.o InventorySlot.o
	$(CXX) $(OBJS) -o ../RogueLetters
	
main.o: Main.cpp
	$(CXX) $(CXXFLAGS) Main.cpp
	
Game.o: Game.h Game.cpp
	$(CXX) $(CXXFLAGS) Game.h Game.cpp
	
Player.o:
	$(CXX) $(CXXFLAGS) Player.h Player.cpp
	
InventorySlot.o:
	$(CXX) $(CXXFLAGS) InventorySlot.h InventorySlot.cpp
	
	
.PHONY : clean
clean:
	rm ../RogueLetters
	rm $(OBJ) 
