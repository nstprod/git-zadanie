#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    int i, j, k;
    for (i = 0; i < mat->c-1; i++){
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

