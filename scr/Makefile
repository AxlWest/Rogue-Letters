# The compiler (CXX) is using g++
CXX = g++ -lncurses

# CFLAGS will be options passed to the compiler
CXXFLAGS = -c -Wall
OBJS = Main.o Game.o Player.o InventorySlot.o Draw.o Level.o Enemy.o

all: RogueLetters

RogueLetters: Main.o Game.o Player.o InventorySlot.o Draw.o Level.o Enemy.o
	$(CXX) $(OBJS) -g -o ../RogueLetters -lncurses	#Use this line insted to enable debugging
	#$(CXX) $(OBJS) -o ../RogueLetters -lncurses
	
main.o: Main.cpp
	$(CXX) $(CXXFLAGS) Main.cpp
	
Game.o: Game.h Game.cpp
	$(CXX) $(CXXFLAGS) Game.h Game.cpp
	
Player.o:
	$(CXX) $(CXXFLAGS) Player.h Player.cpp
	
InventorySlot.o:
	$(CXX) $(CXXFLAGS) InventorySlot.h InventorySlot.cpp
	
Draw.o:
	$(CXX) $(CXXFLAGS) Draw.h Draw.cpp
	
Level.o:
	$(CXX) $(CXXFLAGS) Level.h Level.cpp
	
Enemy.o:
	$(CXX) $(CXXFLAGS) Enemy.h Enemy.cpp 
	
.PHONY: clean

clean:
	rm ../RogueLetters
	rm -f $(OBJS) *.o *.gch
	
