#pragma once

/*
* The module contains information about the field in the form of a dynamic two-dimensional array. 
* For the convenience and efficiency of passing module data to functions, 
* information about it is collected in a separate FIELD.
*/

struct FIELD
{
	int rows;
	int columns; 
	char* pfield;
	char** ppfield;
};

// Capturing memory for a dynamic array of a field and filling it with empty space characters
void init_field(struct FIELD& myField); 
// Filling a field with white space characters
void clear_field(struct FIELD& myField);
// Displaying a snake on the screen
void print_field(struct FIELD& myField);
// Freeing memory from a dynamic array
void destroy_field(struct FIELD& myField);


