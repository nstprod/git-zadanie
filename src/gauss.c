#include "gauss.h"
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    int i, j, k;
    for (i = 0; i < mat->c-1; i++){
	select_elem(i, mat, b);    
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

void select_elem(int i, Matrix *mat, Matrix *b) {
	double max = fabs(mat->data[i][i]);
	int max_elem = i;
	for(int j = i + 1; j <= mat-> c - 1; j++) {
		if (fabs(mat->data[j][i]) > max) {
			max = fabs(mat->data[j][i]);
			max_elem = j;
		}
	}
	if (i != max_elem)
		swap_rows(i, max_elem, mat, b);

}

void swap_rows(int i, int j, Matrix *mat, Matrix *b) {
	double tmp;
	for(int k = 0; k <= mat->c -1; k++) {
		tmp = mat->data[i][k];
		mat->data[i][k] = mat->data[j][k];
		mat->data[j][k] = tmp;
	}
	tmp = b->data[i][0];
	b->data[i][0] = b->data[j][0];
	b->data[j][0] = tmp;
}

