all:demo
	g++ -std=c++11 -o demo main.o super.o
CPPFLAGS = -O2 -std=c++11 -Wall
super.o:super.h
main.o:super.h
demo:main.o super.o super.h
clean:
	@echo"CLEAN...""
	-rm *.o 
