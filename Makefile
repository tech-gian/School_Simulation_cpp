# paths
MODULES =
INCLUDE =
INPUT   =

# compiler
CC = g++

# Compile options
CXXFLAGS = -Wall -Werror -g

# Files .o
OBJS = main.o School.o

# Executable file
EXEC = main

# Arguments
ARGS = 5 1 2 3 4

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)

valgrind: $(EXEC)
	valgrind ./$(EXEC) $(ARGS)
