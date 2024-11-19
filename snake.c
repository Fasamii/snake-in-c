#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include "./typedef.h"
#include "./keylistener.h"

typedef struct {
	vecNode *snake;
	foodPos *food;
} canvas;

void moveSnake(char key) {

}

void render() {
}

void maintainFood() {}

char update(char status, canvas *myCanvas, char key) {
	moveSnake(key);
	maintainFood();
	render();
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
	char tmp_key;

	noBlock();

	while(status) {
		while (kb_hit()) {
			usleep(500);
			tmp_key = fgetc(stdin);
			if(tmp_key == 'w' || tmp_key == 'a' || tmp_key == 's' || tmp_key == 'd') {
				key = tmp_key;
			}
			if(key == 'q') { break; }
		}
		usleep(206500);
		status = update(status, myCanvas, key);
		printf("%c", key);
	}

	block();

	return freeGame();
}

