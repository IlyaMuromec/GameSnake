#pragma once

struct SNAKE
{
	int snake_size;
	int* snake_x;
	int* snake_y;
	int cur_dir;
};

void move_snake(struct SNAKE& mySnake);
void init_snake(struct SNAKE& mySnake, int max_size);
void grow_snake(struct SNAKE& mySnake);
void destroy_snake(struct SNAKE& mySnake);


