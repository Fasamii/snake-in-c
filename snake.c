#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include "./typedef.h"
#include "./keylistener.h"
#include <sys/ioctl.h>

typedef struct {
	vecNode *snake;
	foodPos *food;
} canvas;

void moveSnake(char key) {

}

void render() {
	struct winsize win_size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win_size);
	printf("<x --> %i> <y --> %i>\n", win_size.ws_row, win_size.ws_col);
}

void maintainFood() {}

char update(char status, canvas *myCanvas, char key) {
	moveSnake(key);
	maintainFood();
//	render();
	return status;
}

int freeGame() {
	return 1;
}

int main(void) {
	int width = 20;
	int height = 20;
	int foodQuantity = 3;

	vecNode *snake = malloc(sizeof(vecNode));
	snake->parent = NULL;
	snake->x = (int) width / 2;
	snake->y = (int) height / 2;

	foodPos *food = malloc(sizeof(foodPos));
	food->x = malloc(foodQuantity * sizeof(int));
	food->y = malloc(foodQuantity * sizeof(int));
	food->quantity = 0;

	canvas *myCanvas = malloc(sizeof(canvas));
	myCanvas->snake = snake;
	myCanvas->food = food;
	
	char status = 'r';
	char key;
	char move;

	tergame();
	printf("\033[2J\033[H");
	fflush(stdout);

	while(status) {
		while(kb_hit()) {
			key = fgetc(stdin);
			if(key == 'w' || key == 's' || key == 'a' || key == 'd') {
				move = key;
				printf("move -> %c\n",move);
			}
		}
		status = update(status, myCanvas, key);
		if(key == 'q') { break; }
		usleep(500);
	}

	close_tergame();

	return freeGame();
}

