#pragma once
// basic structs for the program

// node...
typedef struct vec {
	int x;
	int y;
} vec;

// struct for containing snake
typedef struct vecNode {
	struct vecNode *parent;
	int x;
	int y;
} vecNode;

// struct for containing food in game
typedef struct vecList {
	int *x;
	int *y;
	int count;
} vecList;
