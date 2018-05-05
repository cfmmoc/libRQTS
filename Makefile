CC = gcc
CFLAGS = -O2 -fPIC
LDFLAGS = -shared

all: libRQTS.so
.PHONY : all

clean:
	rm -f *.o
	rm -f *.so
.PHONY : clean

lreq.o: lreq.cpp lreq.h
	$(CC) $(CFLAGS) -o lreq.o -c lreq.cpp

neig.o: neig.cpp neig.h
	$(CC) $(CFLAGS) -o neig.o -c neig.cpp

rqts.o: rqts.cpp rqts.h
	$(CC) $(CFLAGS) -o rqts.o -c rqts.cpp

libRQTS.so: lreq.o neig.o rqts.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o libRQTS.so lreq.o neig.o rqts.o

