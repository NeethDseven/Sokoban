
EXEC = Sokoban


CC = gcc


CFLAGS = -Wall -Wextra -g


OBJ = main.o interaction.o


$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ)


main.o: main.c  
	$(CC) $(CFLAGS) -c main.c

interaction.o: interaction.h interaction.c
	$(CC) $(CFLAGS) -c interaction.c

clean:
	rm -f $(OBJ) $(EXEC)


cleanobj:
	rm -f $(OBJ)