PROGNAME=solve
FILES=main.cpp repeats.cpp sudoku.cpp uniqueness.cpp consistency.cpp
OBJS=$(FILES:.cpp=.o)
CXX=g++
CFLAGS=-c -Wall -Wextra -g
LDFLAGS=-Wall -Wextra -g

$(PROGNAME): $(OBJS)
	$(CXX) $(LDFLAGS) $(LIBS) $(OBJS) -o $(PROGNAME)

%.o: %.cpp
	$(CXX) $(CFLAGS) $<

clean:
	rm -f *.o *.d *~ core.*

