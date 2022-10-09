
#pragma once

struct GAME
{
	struct SNAKE mySnake;
	struct FOOD myFood;
	struct FIELD myField;
	int timeout;
	int game_on;
};

void init_game(struct GAME& myGame);
void exec_game(struct GAME& myGame);
void set_snake(struct SNAKE& mySnake, struct FIELD& myField);
void clear_snake(struct SNAKE& mySnake, struct FIELD& myField);
void set_food(struct FOOD& myFood, struct FIELD& myField);
void clear_food(struct FOOD& myFood, struct FIELD& myField);

bool handle_cmd(struct SNAKE& mySnake);

bool check_snake(struct SNAKE& mySnake, struct FIELD& myField);
bool check_food(struct SNAKE& mySnake, struct FOOD& myFood);

void generate_food(struct SNAKE& mySnake, struct FOOD& myFood, struct FIELD& myField);
