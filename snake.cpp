
#include "const.h"
#include "snake.h"

// Capturing memory for dynamic arrays of coordinates of the snake horizontally and vertically 
// with dimension max_size=(columns-2)*rows, setting the snake to its initial position
void init_snake(struct SNAKE& mySnake, int max_size)
{
	mySnake.snake_x = new int[max_size];
	mySnake.snake_y = new int[max_size];
	mySnake.snake_size = 3;
	mySnake.cur_dir = RIGHT;

	for (int i = 0; i < mySnake.snake_size; i++)
	{
		mySnake.snake_x[i] = mySnake.snake_size - 1 - i;
		mySnake.snake_y[i] = 0;
	}
}

// Freeing memory from under dynamic arrays of snake coordinates
void destroy_snake(struct SNAKE& mySnake)
{
	delete[] mySnake.snake_x;
	delete[] mySnake.snake_y;
}

// Snake step.For the head of the snake, new coordinates are set, 
// located on the next field in the direction of its movement.
// All i - th coordinates of the tail are assigned the values of(i + 1) coordinates
void move_snake(struct SNAKE& mySnake)
{
	for (int i = 1; i < mySnake.snake_size; i++)
	{
		mySnake.snake_x[mySnake.snake_size-i] = (mySnake.snake_x[mySnake.snake_size-i-1] );
		mySnake.snake_y[mySnake.snake_size-i] = (mySnake.snake_y[mySnake.snake_size-i-1] );
	} 
	
	if (mySnake.cur_dir == RIGHT)
	{
		mySnake.snake_x[0]++;
	}
	else if (mySnake.cur_dir == LEFT)
	{
		mySnake.snake_x[0]--;
	}
	else if (mySnake.cur_dir == UP)
	{
		mySnake.snake_y[0]--;
	}
	else //(cur_dir == DOWN)
	{
		mySnake.snake_y[0]++;
	}
}

// Increasing the size of the snake by one, while the head of the snake is assigned new coordinates
// with the tail position unchanged. The new last element of the tail is copied from the penultimate
void grow_snake(struct SNAKE& mySnake)
{
	mySnake.snake_size++;

	mySnake.snake_x[mySnake.snake_size - 1] = mySnake.snake_x[mySnake.snake_size - 2];
	mySnake.snake_y[mySnake.snake_size - 1] = mySnake.snake_y[mySnake.snake_size - 2];

}

