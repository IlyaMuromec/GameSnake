
#include "const.h"
#include "snake.h"
#include "field.h"
#include "food.h"
#include "game.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
#include "winconsole.h"

void init_game(struct GAME& myGame)
{
	init_field(myGame.myField);
	init_snake(myGame.mySnake, (myGame.myField.columns - 2) * myGame.myField.rows);
	init_food(myGame.myFood);

	myGame.timeout = 250;
	myGame.game_on = 1;
}

void exec_game(struct GAME& myGame)
{
	while (myGame.game_on)
	{
		Sleep(myGame.timeout);
		setCursorPosition(0, 0);
		myGame.game_on = handle_cmd(myGame.mySnake);
		clear_snake(myGame.mySnake, myGame.myField);
		move_snake(myGame.mySnake);
		myGame.game_on = check_snake(myGame.mySnake, myGame.myField);
		if (check_food(myGame.mySnake, myGame.myFood))
		{
			grow_snake(myGame.mySnake);
			generate_food(myGame.mySnake, myGame.myFood, myGame.myField);
		}
		set_snake(myGame.mySnake, myGame.myField);
		set_food(myGame.myFood, myGame.myField);
		print_field(myGame.myField);
	}
}

void set_snake(struct SNAKE& mySnake, struct FIELD& myField)
{

	for (int i = 1; i < mySnake.snake_size; i++)
	{
		myField.ppfield[mySnake.snake_y[i]][mySnake.snake_x[i] + 1] = tail_symbol; // print tail
	}
	
	myField.ppfield[mySnake.snake_y[0]][mySnake.snake_x[0] + 1] = head_symbol; // print head
}

void clear_snake(struct SNAKE& mySnake, struct FIELD& myField)
{
	for (int i = 0; i < mySnake.snake_size; i++)
	{
		myField.ppfield[mySnake.snake_y[i]][mySnake.snake_x[i] + 1] = field_symbol;
	}
	myField.ppfield[mySnake.snake_y[0]][mySnake.snake_x[0] + 1] = field_symbol;
}

void set_food(struct FOOD& myFood, struct FIELD& myField)
{
	myField.ppfield[myFood.food_y][myFood.food_x + 1] = food_symbol;
}

void clear_food(struct FOOD& myFood, struct FIELD& myField)
{
	myField.ppfield[myFood.food_y][myFood.food_x + 1] = field_symbol;
}

bool handle_cmd(struct SNAKE& mySnake)
{
	char change_dir = '0';
	if (_kbhit())
	{
		change_dir = _getch();
		if (change_dir == ARROW)
		{
			change_dir = _getch();
			if ((change_dir == RIGHT || change_dir == LEFT) && (mySnake.cur_dir == UP || mySnake.cur_dir == DOWN))
			{
				mySnake.cur_dir = change_dir;
			}
			if ((change_dir == UP || change_dir == DOWN) && (mySnake.cur_dir == RIGHT || mySnake.cur_dir == LEFT))
			{
				mySnake.cur_dir = change_dir;
			}
		}
	}
	return change_dir != ESC;
}


bool check_snake(struct SNAKE& mySnake, struct FIELD& myField)
{
	mySnake.snake_x[0] = (mySnake.snake_x[0] + 1) ? mySnake.snake_x[0] : (myField.columns - 3);
	mySnake.snake_x[0] = mySnake.snake_x[0] % (myField.columns - 2);
	mySnake.snake_y[0] = (mySnake.snake_y[0] + 1) ? mySnake.snake_y[0] : (myField.rows - 1);
	mySnake.snake_y[0] = mySnake.snake_y[0] % myField.rows;

	bool flag=1;
	for (int i = 1; i < mySnake.snake_size; i++)
	{
		if (mySnake.snake_x[0] == mySnake.snake_x[i] && mySnake.snake_y[0] == mySnake.snake_y[i])
		{
			flag = 0;
			break;
		}
	};
	return flag;
}

void generate_food(struct SNAKE& mySnake, struct FOOD& myFood, struct FIELD& myField)
{
	bool flag=true;
	int combo;
	while(flag)
	{
		flag = false;
		myFood.food_y = std::rand() % (myField.rows);
		myFood.food_x = std::rand() % (myField.columns - 2);
		
		for (int i = 0; i < mySnake.snake_size; i++)
		{
			if (mySnake.snake_x[i] == myFood.food_x && mySnake.snake_y[i] == myFood.food_y)
			{
				flag = true;
				break;
			}
		}
	}
}

bool check_food(struct SNAKE& mySnake, struct FOOD& myFood)
{
	return (mySnake.snake_x[0] == myFood.food_x && mySnake.snake_y[0] == myFood.food_y);
}