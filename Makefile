bin/main: src/*.c
	mkdir bin
	gcc -o bin/main -Wall src/*.c
