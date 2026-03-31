all: bin/ cpu mem

clean:
	rm -f test
	rm -rf bin/

bin/:
	mkdir -p bin

cpu: bin/ cpu.c common.h
	gcc -o bin/cpu cpu.c -Wall

mem: bin/ mem.c common.h
	gcc -o bin/mem mem.c -Wall

threads: bin/ threads.c common.h common_threads.h
	gcc -o bin/threads threads.c -Wall -pthread

io: bin/ io.c
	gcc -o bin/io io.c -Wall
