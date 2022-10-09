#pragma once

struct FIELD
{
	int rows;
	int columns;
	char* pfield;
	char** ppfield;
};

//extern char field[columns];

void init_field(struct FIELD& myField);

void clear_field(struct FIELD& myField);

void print_field(struct FIELD& myField);

void destroy_field(struct FIELD& myField);


