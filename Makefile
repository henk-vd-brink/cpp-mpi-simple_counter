all: build

build: simpleCounter

simpleCounter.o: simpleCounter.cpp
	mpicxx -I../../common/inc -o $@ -c $<

simpleCounter: simpleCounter.o
	mpicxx -o $@ $+
	mkdir -p bin
	mv $@ bin

run:
	mpiexec -np 1 ./bin/simpleCounter

clean:
	rm -f simpleCounter simpleCounter.o
	rm -rf bin

clobber: clean
