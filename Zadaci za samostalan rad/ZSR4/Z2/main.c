/*#2 Napisati program koji računa sumu kvadrata prirodnih brojeva manjih ili jednakih 
broju n koji se unosi sa tastature. Ukoliko korisnik unese broj koji nije prirodan, 
program treba ispisati grešku „Broj nije prirodan!“ i završiti sa radom. 
Ukoliko uopšte ne bude unesen broj (nego npr. slovo ili riječ), program treba ispisati 
poruku „Nije unesen broj!“ i završiti sa radom.#include <stdio.h>*/

#include <stdio.h>

int main(){
int suma=0,i,n=0,uspjesni;
    printf("Unesite n: ");
uspjesni=scanf("%d",&n);
for(i=1;i<=n;i++){
suma=suma+i*i;
}

if(uspjesni!=1)
printf("\nNije unesen broj!");

else if(n<=0)
printf("\nBroj nije prirodan!");


else if(uspjesni==1){
printf("\nSuma je: %d",suma);
}




return 0;
}