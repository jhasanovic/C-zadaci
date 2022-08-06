/*#12 Napisati program sličan prethodnom, samo se ovaj put pretvaraju stepeni iz decimalnog formata u 
cjelobrojne stepene, minute i sekunde. Korisnik unosi stepene kao realan broj. Iako izgleda jako slično 
prethodnom zadatku, pristup za računanje je potpuno drugačiji.*/
#include <stdio.h>
#include <math.h>
int main() {
	double stepeni,cijeli,minute,sekunde,ostatak,minute2;
	printf("Unesite stepene: ");
	scanf("%lf",&stepeni);
	cijeli=(int)stepeni;
	ostatak=stepeni-cijeli;
	minute=(ostatak*60);
	minute2=(int)minute;
	sekunde=(int)((minute-minute2)*60);
	printf("%g = %g^ %g' %g''",stepeni,cijeli,minute2,sekunde);
	return 0;
}
