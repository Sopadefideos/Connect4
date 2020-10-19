CC= g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS = -Wall -g -std=c++11
EXEC = conecta4
DEPS = game.h board.h state.h random.hpp catch.hpp
OBJS = game.o board.o state.o main.o
SRCS =  $(OBJS:.o=.cpp)

.PHONY: all clean doc

random: agent_random.o random.hpp state.o
	$(CC) agent_random.o state.o $(LIBS) -o random

alfaBeta: minMaxAlfaBeta.o state.o
	$(CC) minMaxAlfaBeta.o state.o $(LIBS) -o alfaBeta

minMax: minMax.o state.o
	$(CC) minMax.o state.o $(LIBS) -o minMax

all: $(EXEC) random minMax alfaBeta

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -g $< -o $@

$(EXEC):  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(EXEC)

clean:
	$(RM) $(EXEC) $(EXEC).o $(OBJS) agent_random.o state.o tests.o tests-main.o minMaxAlfaBeta.o minMax.o random alfaBeta minMax

doc: $(SRCS)
	doxygen
