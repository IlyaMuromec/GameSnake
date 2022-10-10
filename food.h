#pragma once

/*
* The module contains information about food coordinates. 
* For the convenience and efficiency of passing module data to functions, 
* information about it is collected in the FOOD structure.
*/

struct FOOD
{
	int food_x;
	int food_y;
};

// Initializing food coordinates
void init_food(struct FOOD& myFood);


