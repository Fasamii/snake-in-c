exe : main.o terminal.o
	gcc ./build/main.o ./build/terminal.o -o exe

main.o : src/main.c
	gcc -c src/main.c -o ./build/main.o

terminal.o : src/terminal.c
	gcc -c src/terminal.c -o ./build/terminal.o

clean :
	rm -f ./build/*
	rm -f exe
