/*#5 Napisati program koji računa potenciju nekog broja (kao pow funkcija iz „math.h“ 
biblioteke, samo što je ovdje ograničenje da eksponent mora biti prirodan broj). Baza i 
eksponent se unose sa tastature pri čemu baza može biti realnog tipa, dok je eksponent 
prirodan broj. Potrebno je obratiti pažnju na provjeru unosa podataka; treba posebno t
retirati slučajeve kada nije unesen broj i kada uneseni broj nije cjelobrojan kod unosa 
eksponenta!*/

#include <stdio.h>
int main(){
int ispravnibaza=0,ispravnieks=0,i,cijeli;
double baza=1,eks=0,rez=1;

printf("Unesite bazu: ");
ispravnibaza=scanf("%lf",&baza);
if(ispravnibaza!=1){
printf("Nije unesen broj!");
return 0;
}



printf("Unesite eksponent: ");
ispravnieks=scanf("%lf",&eks);
cijeli=(int)eks;

if(ispravnieks!=1){
printf("Nije unesen broj!");
return 0;
}
else if (eks-cijeli>0.0001){
    printf("Uneseni broj nije cjelobrojan!");
    return 0;
}


else if(eks==1)
printf("%g^%g = %g",baza,eks,rez);
else{
for(i=1;i<=eks;i++){
    rez=rez*baza;
}
printf("%g^%g = %g",baza,eks,rez);
}

return 0;
}
