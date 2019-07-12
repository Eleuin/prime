CC	= gcc

SRC	= $(wildcard *.c)
OBJ	= $(SRC:.c=.o)
DEP	= $(SRC:.c=.d)
EXE	= prime

CFLAGS	= -std=c99 -pedantic -Wall
LDFLAGS = -lm

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJ) $(DEP)
	rm -rf $(EXE)
