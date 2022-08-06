/*#8 Napišite program koji će iscrtavati BGA kolo. Korisnik unosi broj n, koji predstavlja 
broj pinova (lopticâ, predstavljenih znakom „o“) u jednom redu i jednoj koloni BGA kola. 
Broj n mora biti u granicama [1, 35]. Pinove BGA kola staviti u okvir (po dva razmaka sa 
lijeve i desne strane okvira), koji ima izvode za daljnju ugradnju na desnoj strani. 
Izvodi su sastavljeni od „>“ i „<“ znakova.*/

#include <stdio.h>

int main(){

int i,j,n;
printf("Unesite N, dimenziju BGA kola: ");
scanf("%d",&n);

for(i=0;i<=n+1;i++){
for(j=0;j<=2*n+4;j++){
if((i==0 && j==0) || (i==0 && j==2*n+4) || (i==n+1 && j==0) || (i==n+1 && j==2*n+4))
printf("+");
else if(j==0)
printf("|");
else if(j==2*n+4 && i%2==1)
printf(">");
else if(j==2*n+4 && i%2==0)
printf("<");
else if(i==0 || i==n+1)
printf("-");
else if(j==1 || j==2 || j==2*n+4 || j==2*n+3 || j%2==0)
printf(" ");
else
printf("o");
}
printf("\n");
}



return 0;
}

