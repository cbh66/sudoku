PROGNAME=solve
FILES=main.cpp uniqueness.cpp sudoku.cpp consistency.cpp span.cpp set.cpp permutation.cpp
OBJS=$(FILES:.cpp=.o)
DEPENDENCIES=$(FILES:.cpp=.d)

CXX=g++
CFLAGS=-c -Wall -Wextra -g
LDFLAGS=-Wall -Wextra -g
LIBS=

all: $(PROGNAME) $(DEPENDENCIES)

-include $(DEPENDENCIES)

$(PROGNAME): $(OBJS)
	$(CXX) $(LDFLAGS) $(LIBS) $(OBJS) -o $(PROGNAME)

%.o: %.cpp %.d
	$(CXX) $(CFLAGS) $<

# makes dependencies you can use, so you know to recompile when a header changes
%.d: %.cpp
	$(CXX) $(CFLAGS) -MM $*.cpp > $*.d

clean:
	rm -f *.o *.d *~ core.* $(PROGNAME)

