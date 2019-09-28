/*
 * versuch4.c
 *
 *  Created on: 28.09.2019
 *      Author: pliss
 *
 *      Mondlandung: Steuerung einer Landefähre mit Eingabe 0..9
 */


#include <stdio.h>
#define dt 1

int main(void){
	int schubstufe;
	float schub, a;
	float halt = 50., vneu = -10.;
	float hneu, valt;

	printf("Mondlandung"
			"\nBitte geben Sie jeweils eine Schubstufe von 0-9 an: ");
	fflush(stdout);
	while((scanf("%d", &schubstufe) > 0) && (schubstufe >= 0 && schubstufe <= 9)){
		schub = 500 * schubstufe;
		a = (schub / 1000) - 1,6;
		vneu = valt + a * dt;
		hneu = halt + vneu * dt;
	}

	return 0;
}
