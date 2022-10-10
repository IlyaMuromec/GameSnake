#pragma once

/*
* The module contains information about the snake in the form of an index dynamic array. 
* For the convenience and efficiency of passing module data to functions, 
* information about it is collected in the SNAKE structure.
*/

struct SNAKE
{
	int snake_size;
	int* snake_x;
	int* snake_y;
	int cur_dir;
};
// Snake step.For the head of the snake, new coordinates are set, 
// located on the next field in the direction of its movement.
// All i - th coordinates of the tail are assigned the values of(i + 1) coordinates
void move_snake(struct SNAKE& mySnake);

// Capturing memory for dynamic arrays of coordinates of the snake horizontally and vertically 
// with dimension max_size=(columns-2)*rows, setting the snake to its initial position
void init_snake(struct SNAKE& mySnake, int max_size);

// Increasing the size of the snake by one, while the head of the snake is assigned new coordinates
// with the tail position unchanged. The new last element of the tail is copied from the penultimate
void grow_snake(struct SNAKE& mySnake);

// Freeing memory from under dynamic arrays of snake coordinates
void destroy_snake(struct SNAKE& mySnake);


