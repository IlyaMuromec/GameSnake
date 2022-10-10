
#pragma once

/*
* The module combines the Snake, Field and Food modules, establishes the interface between them
* and the rules of the game. For the convenience and efficiency of passing module data to functions,
* information about it is collected in the FIELD structure.
*/


struct GAME
{
	struct SNAKE mySnake;
	struct FOOD myFood;
	struct FIELD myField;
	int timeout;
	int game_on;
};

// Instantiating built-in structures, initializing game flag and step delay
void init_game(struct GAME& myGame);
// Game run loop
void exec_game(struct GAME& myGame);
// Filling in the coordinates of the field corresponding to the snake with its symbols
void set_snake(struct SNAKE& mySnake, struct FIELD& myField);
// Filling the field coordinates corresponding to the snake with whitespace characters
void clear_snake(struct SNAKE& mySnake, struct FIELD& myField);
// Filling in the coordinates of the field corresponding to the food with its symbol
void set_food(struct FOOD& myFood, struct FIELD& myField);
// Filling the corresponding food field coordinates with the empty field symbol
void clear_food(struct FOOD& myFood, struct FIELD& myField);
// Reading the code of the pressed key on the keyboard
bool handle_cmd(struct SNAKE& mySnake);
// Checking the exit of the snake out of the field 
bool check_snake(struct SNAKE& mySnake, struct FIELD& myField);
// Checking the coordinates of the snake head and food
bool check_food(struct SNAKE& mySnake, struct FOOD& myFood);
// Food is generated using the rand() function for horizontal and vertical coordinates.
void generate_food(struct SNAKE& mySnake, struct FOOD& myFood, struct FIELD& myField);
