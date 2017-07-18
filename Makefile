AM_CFLAGS := -g -Wall -O2

CC        := gcc
CFLAGS    := $(AM_CFLAGS)

LD        := gcc

APPS      := ptr2arr
OBJS      := $(APPS).o
SRCS      := $(APPS).c

bsearch: bsearch.o
	$(LD) $(AM_CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr $(APPS) *.o *.out
