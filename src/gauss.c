#include "gauss.h"
#include <math.h> // dla funkcji fabs
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    int i, j, k;
    for (i = 0; i < mat->c-1; i++){
    	select_pivot(i, mat, b);
    	double pivot = mat->data[i][i];
    	if (pivot == 0)
    		return 1;
    	for (j = i+1; j < mat->r; j++){
    		double zero_el = mat->data[j][i];
    		double skalar = zero_el / pivot;
    		b->data[j][0]=b->data[j][0] - skalar * b->data[i][0];
    		for (k=i; k < mat->c; k++){
	    		mat->data[j][k]=mat->data[j][k] - skalar * mat->data[i][k];
	    	}
    	}
    }
	return 0;
}

void select_pivot(int i, Matrix *mat, Matrix *b){
	double max = fabs(mat->data[i][i]);
	int i_max = i;
	for (int j = i+1; j<mat->r; j++){
		if (fabs(mat->data[j][i]) > max){
			max = fabs(mat->data[j][i]);
			i_max = j;
		}
	}
	if (i != i_max)
		swap_rows(i, i_max, mat, b);
}

void swap_rows(int i, int i_max, Matrix *mat, Matrix *b){
	double tmp;
	int k;
	for (k=0;k<mat->c;k++){
		tmp = mat->data[i][k];
		mat->data[i][k] = mat->data[i_max][k];
		mat->data[i_max][k] = tmp;
	}
	tmp = b->data[i][0];
	b->data[i][0] = b->data[i_max][0];
	b->data[i_max][0] = tmp;
}