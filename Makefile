exe : snake.o keylistener.o 
	gcc ./build/snake.o ./build/keylistener.o -o exe

snake.o : snake.c
	gcc -c snake.c -o ./build/snake.o

keylistener.o : keylistener.c
	gcc -c keylistener.c -o ./build/keylistener.o

clean :
	rm -f ./build/*
	rm -f exe
