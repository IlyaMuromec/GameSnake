
#include "const.h"
#include "snake.h"

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

void destroy_snake(struct SNAKE& mySnake)
{
	delete[] mySnake.snake_x;
	delete[] mySnake.snake_y;
}


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

void grow_snake(struct SNAKE& mySnake)
{
	mySnake.snake_size++;

	mySnake.snake_x[mySnake.snake_size - 1] = mySnake.snake_x[mySnake.snake_size - 2];
	mySnake.snake_y[mySnake.snake_size - 1] = mySnake.snake_y[mySnake.snake_size - 2];

}

