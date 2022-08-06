#include <stdio.h>

int main() {
	int krekeri;
	double pas,macka,kornjaca,meso,ostalo,h,m,d;
	printf("Unesite trenutno vrijeme (hh:mm): ");
	scanf("%lf:%lf",&h,&m);
	printf("Unesite redni broj dana u sedmici: ");
	scanf("%lf",&d);
	
	if(h>=0 && h<8)
	printf("Ljubimci ne smiju jesti prije 8:00h!");
	else{
		if(h<18){
		pas=(h+m+d)/34;
		meso=pas/3;
		ostalo=pas-meso;
		printf("Pas ce pojesti %.2fkg hrane, od toga %.2fkg mesa i %.2fkg ostale hrane.\n",pas,meso,ostalo);
		}
		else{
		krekeri=d*7;
		printf("Pas ce dobiti %d kreker/a.\n",krekeri);
		}
		macka=(2*h)/40+d/7;
		printf("Macka ce pojesti %.2fkg hrane.\n",macka);
		kornjaca=(7+h)/(d+154);
		printf("Kornjaca ce pojesti %.2fkg hrane.\n",kornjaca);
		if(d==4)
		printf("Kornjaca ce dobiti i kalcij posto je cetvrtak.\n");
		}
	
	
	return 0;
}
