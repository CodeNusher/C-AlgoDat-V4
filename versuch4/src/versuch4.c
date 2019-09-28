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
	float halt = 50., valt = -10.;
	float hneu, vneu;

	printf("Mondlandung"
			"\nBitte geben Sie jeweils eine Schubstufe von 0-9 an: ");
	fflush(stdout);
	while((scanf("%d", &schubstufe) > 0) && (schubstufe >= 0 && schubstufe <= 9)){
		schub = 500 * schubstufe;
		a = (schub / 1000) - 1.6;
		printf("\nSchub: %d -> akt. Hoehe: %.1f m, Geschwindigkeit: %.1f m/s: ", schubstufe, halt, valt);

		vneu = valt + a * dt;
		hneu = halt + vneu * dt;
		valt = vneu;
		halt = hneu;
		if(hneu <= 100){

			fflush(stdout);
			if(hneu <= 0.1 && hneu >= 0){
				if(vneu < 0.1){
					printf("\nGewonnen!\n");
				}
				else{
					printf("\nCRASH!\n");
					fflush(stdout);
				}
			}
			else if(hneu < 0.0){
				printf("\nCrash!\n");
				fflush(stdout);
			}
		}
		else{
			printf("\nByeBye!\n");
			fflush(stdout);
		}
	}

	return 0;
}
