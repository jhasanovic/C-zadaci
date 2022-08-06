/*#4 Napisati program koji računa sumu svih prostih brojeva do broja n (uključivo). 
Pored toga, program treba da ispisuje te (proste) brojeve, svaki u novom redu. 
Zabranjeno je korištenje biblioteka osim „stdio.h“ biblioteke. Također je zabranjeno 
koristiti pomoćne funkcije (odnosno, jedina funkcija koja smije biti u programu je main.*/
#include <stdio.h>

int main() {
	int i,j,n,prost,suma=0;
	printf("Unesite n: ");
	scanf("%d",&n);
	
	for(i=2;i<=n;i++){
		prost=1;
		for(j=2;j<=i/2;j++){
			if(i%j==0){
			prost=0;
			break;
			}
		}
		if(prost)
		printf("%d\n",i);
	
	if(prost)
	suma+=i;
	}
	
	printf("Suma je: %d",suma);
	return 0;
}
