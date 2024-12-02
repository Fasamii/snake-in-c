#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "./typedef.h"
#include "./terminal.h"

void maintain_food(vecList *foods, vecNode *snake, vec win_size) {}
void update(vec win_size, vecNode *snake, vecList *foods) {}
void foo() { 
	close_term();
	exit(0);
}

int main(void) {
	
	int food_quant = 3;
	int scale = 2;
	vec win_size = get_term_size();

	vecNode *snake = malloc(sizeof(vecNode));
	snake->parent = NULL;
	snake->x = (int) win_size.x / 2;
	snake->y = (int) win_size.y / 2;

	vecList *foods = malloc(sizeof(vecList));
	foods->count = 0;
	foods->x = malloc(food_quant * sizeof(int));
	foods->y = malloc(food_quant * sizeof(int));
	maintain_food(foods, snake, win_size);

	init_term();
	listen_for_close(foo);
	printf("\e[2J\e[H");
	fflush(stdout);
	
	bool dead = false;
	char move = 'd';
	
	while(!dead)	{
		usleep(500000);
		move = parse_input(move);
		printf("<|\e[38;5;2mwhile loop\e[0m|> >==< <|move -> %c|>\n", move);
		if(move == 'q') { break; }
		update(win_size, snake, foods);
	}
	printf("<| close |>");	
	close_term();
	return 0;
}
