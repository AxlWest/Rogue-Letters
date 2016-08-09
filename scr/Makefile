# The compiler (CXX) is using g++
CXX = g++

# CFLAGS will be options passed to the compiler
CXXFLAGS = -c -Wall
OBJS = Main.o Game.o

all: RogueLetters

RogueLetters: Main.o Game.o
	$(CXX) $(OBJS) -o ../RogueLetters
	
main.o: Main.cpp
	$(CXX) $(CXXFLAGS) Main.cpp
	
Game.o: Game.h Game.cpp
	$(CXX) $(CXXFLAGS) Game.h Game.cpp
	
clean:
	rm *o RogueLetters
