/*#3 Napisati program koji računa stepene unesenog (realnog) broja i ispisuje ih 
tako da je je prvih 5 stepena poravnato udesno, a drugih 5 ulijevo. 
Program računa stepene broja (do 10. stepena) i ispisuje ih na 20 mjesta širine 
(ne računajući „^“ prefiks), zaokruženo na 5 decimalnih mjesta, poravnatih kako je iznad opisano.*/

#include <stdio.h>
#include <math.h>

int main() {
	double broj;
	printf("Unesite broj: ");
	scanf("%lf",&broj);
	
	printf("^ 1: %20.5f\n",broj);
	printf("^ 2: %20.5f\n",pow(broj,2));
	printf("^ 3: %20.5f\n",pow(broj,3));
	printf("^ 4: %20.5f\n",pow(broj,4));
	printf("^ 5: %20.5f\n",pow(broj,5));
	printf("^ 6: %-20.5f\n",pow(broj,6));
	printf("^ 7: %-20.5f\n",pow(broj,7));
	printf("^ 8: %-20.5f\n",pow(broj,8));
	printf("^ 9: %-20.5f\n",pow(broj,9));
	printf("^ 10: %-20.5f\n",pow(broj,10));
	return 0;
}
