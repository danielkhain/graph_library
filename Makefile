CC=g++ -g -Wall -std=c++17

# List of source files for your thread library
GRAPH_SOURCES=Graph.cpp

# Generate the names of the thread library's object files
GRAPH_OBJS=${GRAPH_SOURCES:.cpp=.o}

all: Graph.o app infection

# Compile an application program
app: test.cpp Graph.o
	${CC} -o $@ $^ -ldl

infection: infection_propagation.cpp Graph.o
	${CC} -o $@ $^ -ldl



# Generic rules for compiling a source file to an object file
%.o: %.cpp
	${CC} -c $<
%.o: %.cc
	${CC} -c $<

clean:
	rm -f ${GRAPH_OBJS} app infection
