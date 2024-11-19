#pragma once

// struct for snake body and head
typedef struct vecNode {
	int x;
	int y;
	struct vecNode *parent;
} vecNode;

// struct for food positions and quantity
typedef struct foodPos {
	int quantity;
	int *x;
	int *y;
} foodPos;


