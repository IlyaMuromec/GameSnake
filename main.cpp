
#include "const.h"
#include "field.h"
#include "snake.h"
#include "food.h"
#include "game.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include "winconsole.h"

int main()
{	
	srand(time(0)); //
	struct GAME myGame;
	init_game(myGame);
	generate_food(myGame.mySnake, myGame.myFood, myGame.myField);
	system("cls");
	print_field(myGame.myField);

	exec_game(myGame);

	destroy_snake(myGame.mySnake);
	destroy_field(myGame.myField);
}

