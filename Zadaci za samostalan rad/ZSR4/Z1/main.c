/*#1 Napisati program koji računa proizvod svih prirodnih parnih brojeva do broja n 
(uključivo) koji se unosi sa tastature. Ukoliko uneseni broj nije prirodan, 
program treba da ispiše grešku i završi sa radom. */

#include <stdio.h>

int main(){
int proizvod=1,i,n;
    printf("Unesite n: ");
scanf("%d",&n);
	if(n==1)
	proizvod=0;
	else{
for(i=2;i<=n;i++){
	if(i%2==0)
proizvod=proizvod*i;
}
}
if(n>0){
printf("\nProizvod je: %d",proizvod);
}
else
printf("\nBroj nije prirodan");
return 0;
}
