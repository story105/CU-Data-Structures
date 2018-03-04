BUILD_FLAGS = -W -Wall -pedantic
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: Main.exe

Header.o: Makefile Header.h HeaderCPP.cpp
	$(CC) $(BUILD_FLAGS) -c HeaderCPP.cpp -o HeaderCPP.o

Main.exe: Makefile Header.o
	$(CC) $(BUILD_FLAGS) Header.o main.cpp  -o Main.exe

clean:
	$(RM) $(EXES) $(OBJECTS)
