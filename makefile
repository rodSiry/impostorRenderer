SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)
LIBS=-lGL -lX11 -lGLU -lGLEW -lILU -lIL
CXXFLAGS=-g -std=c++11 -Wall -pedantic

all:main.o $(OBJ)
	g++ -o Programme $(LIBS) $^
%.o:%.cpp
	g++ -c $^ -I include -I /usr/include -o $@
