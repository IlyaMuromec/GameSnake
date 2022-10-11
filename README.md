# GameSnake
Snake is a simple console game where the player manipulates a growing line that becomes a primary obstacle to itself.

Functional requirements for the project:
- a change in the position of the snake on the field (movement) occurs after a certain period of time;
- to change the direction of movement of the snake, you can use the keyboard keys;
- if the snake's head collides with the field boundary, then the movement of the snake goes along the ring, i.e. it appears from the other (opposite) edge of the field;
- food for the snake appears on the field in a random place;
- if the snake manages to “eat” the food, then the length of the snake increases;
- the game ends if the snake "bites" itself or if the user himself decides to interrupt the execution.

The project was developed based on the procedural programming paradigm.

The result of the decomposition of the project is the list of modules: Main, Field, Snake, Food, Game.

Main. The basic module of the program. Serves to call initializing functions and start the program execution loop.

Field. The module contains information about the field in the form of a dynamic two-dimensional array. 
The dimension of the field is set at the beginning of the program execution by the user. 
The module provides functions to initialize and change the state of the field.

Snake. The module contains information about the snake in the form of an indexed dynamic array, i.e. 
the elements of the snake array are its coordinates in the Field. 
The module provides functions for initializing and changing the state of the snake.

Food. The module contains information about food coordinates, as well as an initialization function.

Game. The module combines the data of the Snake, Field and Food modules, establishes the interface between them and the rules of the game
