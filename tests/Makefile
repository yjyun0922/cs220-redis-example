CC = gcc 
CFLAGS = -fPIC -Wall -Wextra -O2 -g -I../hiredis/
LDFLAGS = -L../hiredis/
RM = rm -f
LDLIBS = -l:libhiredis.a

SRCS = test-hgetset.c
OBJS = $(SRCS:.c=.o)
BIN = test-hgetset

.PHONY: all
all: ${BIN}

polygon.o: polygon.c

$(BIN): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o$@ $(LDLIBS) 

.PHONY: clean
clean:
	-${RM} ${OBJS} ${BIN}

