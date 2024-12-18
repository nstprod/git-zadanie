#ifndef _GAUSS_H
#define _GAUSS_H

#include "mat_io.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b);

void select_elem(int i, Matrix *mat, Matrix *b);

void swap_rows(int i, int j, Matrix *mat, Matrix *b);

#endif
