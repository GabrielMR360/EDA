all:
	gcc -c src/bibliotecaABP.c -I include/ -o obj/bibliotecaABP.o
	gcc apps/main.c obj/* -I include/ -o bin/main

run:
	./bin/main

clean:
	rm bin/* obj/* 