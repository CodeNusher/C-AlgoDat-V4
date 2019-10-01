/*
 * versuch4.c
 *
 *  Created on: 28.09.2019
 *      Author: pliss
 *
 *      Mondlandung: Steuerung einer Landefähre mit Eingabe 0..9
 */


#include <stdio.h>
#define DT 1
#define FLUCHTHOEHE 100
#define F 500
#define FAEHRE 1000
#define FALLBESCH 1.6

int main(void){
	int schubstufe;
	float schub, a;
	float halt = 50., valt = -10.;
	float hneu, vneu;

	printf("Mondlandung"
			"\nBitte geben Sie jeweils eine Schubstufe von 0-9 an: ");
	printf("\nSchub: 0 -> akt. Hoehe: %.1f m, Geschwindigkeit: %.1f m/s: ", halt, valt);
	fflush(stdout);
	while((scanf("%d", &schubstufe) > 0) && (schubstufe >= 0 && schubstufe <= 9))
	{
		schub = F * schubstufe;
		a = (schub / FAEHRE) - FALLBESCH;
		vneu = valt + a * DT;
		hneu = halt + vneu * DT;
		printf("Schub: %d -> akt. Hoehe: %.1f m, Geschwindigkeit: %.1f m/s: ", schubstufe, hneu, vneu);
		fflush(stdout);
		valt = vneu;
		halt = hneu;

		if(hneu > FLUCHTHOEHE)
		{
			printf("\nByeBye!\n");
			fflush(stdout);
			break;
		}

		else if(hneu < 0.1)
		{
			if(vneu < 1.0 && vneu > -1.0)
			{
				printf("\nGewonnen!\n");
				fflush(stdout);
				break;
			}
			else
			{
				printf("\nCrash!\n");
				fflush(stdout);
			}
		}

	}
	/* für Test Consolen-Abbruch */
	/*
	printf("\nABBRUCH mit [j]: ");
	fflush(stdout);
	while((scanf("%s", &ch)) > 0){
		if(ch == 'j')
			break;
	}
	*/
	return 0;
}
