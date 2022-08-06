#include <stdio.h>

int main() {
	int n,i,j;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	
	if(n%2==0 && n>=4 && n<=100){
	for(i=0;i<n;i++){
		for(j=0;j<2*n;j++){
			/*horizontalne linije pravougaonika*/
			if(i==0 || i==n-1)
			printf("+");
			/*vertikalne linije pravougaonika*/
			else if(j==0 || j==2*n-1)
			printf("+");
			/*lijeva strana poklopca kao glavna dijagonala*/
			else if(i==j && i<=(n/2)-1)
			printf("+");
			/*desna strana poklopca kao sporedna dijagonala*/
			else if(i+j==2*n-1 && i<=(n/2)-1)
			printf("+");
			/*horizontalna linija poklopca*/
			else if(i==n/2-1 && j>=i && j<=n+n/2)
			printf("+");
			else 
			printf(" ");
		}
		printf("\n");
	}	
		
	}
	else
	printf("Broj je van trazenog opsega.");
	return 0;
}
