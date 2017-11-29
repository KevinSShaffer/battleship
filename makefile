.SUFFIXES : .cc
.SUFFIXES : .c
.SUFFIXES : .cpp

INCDIR = -std=c++11
LIBDIR =

CC = g++

CXXFLAGS = -g

LIBS = -lm

OBJS = main.o player.o board.o grid.o position.o shot.o ship.o exceptions.o str_func.o game.o csv_reader.o

TARGET = battleship

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBDIR) $(LIBS)

.cc.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<

.c.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<

.cpp.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<

clean:
	rm -f $(OBJS) $(TARGET) core


