/*#8 Napisati funkciju int NZD (int a, int b) koja vraća najveći zajednički djelilac brojeva a i b. 
Npr. NZD (8, 12) je 4, NZD (6, 366) je 6. Napomena: funkcija je jako kratka ako se koristi rekurzija.*/
#include <stdio.h>

int NZD(int a,int b){
	if(b==0)return a;
	a=a%b;
	return NZD(b,a);
}
int main() {
	int y,a,b;
	printf("Unesite brojeve a i b: ");
	scanf("%d %d",&a,&b);
	y=NZD(a,b);
	printf("%d",y);
	return 0;
}
