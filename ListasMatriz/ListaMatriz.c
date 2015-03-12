#include <stdlib.h>

// Nodo Fila -> Nodo columna -> dato

struct lista {
	int row;
	struct lista *column;
};

struct matriz {
	int c, r; // column | row;
	int dato;
	struct matriz *next;
	struct matriz *prev;
};


typedef struct matriz matriz;

void initMatrix(matriz **matrix) {
	*matrix = NULL;
}

void insertValue(matriz **matrix, int column, int row, int value) {
	matriz *newValue;
	newValue = malloc(sizeof(matriz));

	newValue->c = column;
	newValue->r = row;
	newValue->dato = value;
	newValue->next = *matrix;
	newValue->prev = &matrix;
	
	*matrix = newValue;
}

void showExactValue(matriz *matrix, int column, int row) {
	matriz *aux;
	for (aux = matrix; aux != NULL; aux = aux->next) {
		if (aux->c == column && aux->r == row)
			printf("%d\n", aux->dato);
	}
}

int main() {

	matriz *matrix;

	initMatrix(&matrix);

	insertValue(&matrix, 3, 3, 3);
	insertValue(&matrix, 4, 3, 2);
	
	showExactValue(matrix, 3, 3);
	showExactValue(matrix, 4, 3);

	getch();
	return 0;
}