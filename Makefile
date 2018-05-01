CC=g++
CFLAGS=-Wall
OBJS=main.o
PROG=game
LIBDIR=/usr/local/lib
INCDIR=/usr/include
LDFLAGS=-L$(LIBDIR)
INCFLAG=-I$(INCDIR)
LDLIBS= -lsfml-graphics -lsfml-window -lsfml-system

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS) $(INCFLAG)

main.o: main.cpp

clean:
		rm -f *~ *.o $(PROG) core a.out
