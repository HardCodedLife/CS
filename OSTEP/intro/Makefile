all: bin/ cpu mem

clean:
	rm -f test cpu mem
	rm -rf bin/

bin/:
	mkdir -p bin

cpu: bin/ cpu.c common.h
	gcc -o bin/cpu cpu.c -Wall

mem: bin/ mem.c common.h
	gcc -o bin/mem mem.c -Wall
