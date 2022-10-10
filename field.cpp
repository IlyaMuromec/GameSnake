
#include "const.h"
#include "field.h"
#include <iostream>

// An auxiliary pointer to a dynamic array of size columns*rows
char* pfield;
// Pointer to elements of a dynamic two-dimensional array with columns as columns and rows as rows
char** ppfield;

// Filling a field with white space characters
void clear_field(struct FIELD& myField)
{
	for (int i = 0; i < myField.rows; i++)
	{
		myField.ppfield[i][0] = border_symbol;
		for (int j = 1; j < myField.columns-1; j++)
		{
			myField.ppfield[i][j] = field_symbol;
		}
		myField.ppfield[i][myField.columns - 1] = border_symbol;
	}
}

// Displaying a snake on the screen
void print_field(struct FIELD& myField)
{
	for (int i = 0; i < myField.columns; i++)
	{
		printf("%c", border_symbol);
	}
	printf("\n");

	for (int i = 0; i < myField.rows; i++)
	{
		for (int j = 0; j < myField.columns; j++)
		{
			printf("%c", myField.ppfield[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < myField.columns; i++)
	{
		printf("%c", border_symbol);
	}
}

// Capturing memory for a dynamic array of a field and filling it with empty space characters
void init_field(struct FIELD& myField)
{
	std::cout << "Snake\nInput number of rows:";
	std::cin >> myField.rows;
	std::cout << "Input number of columns:";
	std::cin >> myField.columns;

	myField.pfield = new char[myField.rows * myField.columns];
	myField.ppfield = new char*[myField.rows];
	for (int i = 0; i < myField.rows; i++)
	{
		myField.ppfield[i] = myField.pfield + i * myField.columns;
	}

	clear_field(myField);
}

// Freeing memory from a dynamic array
void destroy_field(struct FIELD& myField)
{
	delete[] myField.pfield;
	delete[] myField.ppfield;
}
