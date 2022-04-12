all:
	gcc -c src/bibliotecaABP.c -I include/ -o obj/bibliotecaABP.o
	gcc app/main.c obj/* -I include/ -o bin/main.exe

run:
	./bin/main.exe

clean:
	rm bin/* obj/* 