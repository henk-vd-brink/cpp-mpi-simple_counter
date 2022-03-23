all: build

build: simpleCounter

simpleCounter.o: simpleCounter.cpp
	mpicxx -I../../common/inc -o $@ -c $<

simpleCounter: simpleCounter.o
	mpicxx -o $@ $+
	mkdir -p bin
	mv $@ bin

run:
	mpiexec --hostfile clusterfile -np 2 ./bin/simpleCounter

clean:
	rm -f simpleCounter simpleCounter.o
	rm -rf bin

clobber: clean
