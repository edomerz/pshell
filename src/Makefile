IDIR = ../include

CC=gcc
CFLAGS=-g -std=c89 -ansi -Wall -Werror -pedantic -D_DEBUG -I$(IDIR)

ODIR=obj

LDIR = ../lib
LIBS=-L$(LDIR)

all:pshell_test

_DEPS = pshell.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = pshell_test.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

	
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

pshell_test: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)
.PHONY:clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
