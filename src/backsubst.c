#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int i, j;
	int row = mat->r;
	int collumn = mat->c;

	if(row != collumn) {
		return 2;
	}

	for(i = row - 1; i >= 0; i--) {
		double value = b->data[i][0];
		for(j = i + 1; j <= collumn - 1; j++) {
			value -= mat->data[i][j] * x->data[j][0];
		}
		if (mat->data[i][i] == 0) {
			return 1;
		}
		x->data[i][0] = value / mat->data[i][i];
	}
	return 0;
}


