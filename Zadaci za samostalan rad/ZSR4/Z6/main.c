/*#6 Prepravite prethodni program tako da može računati potenciju broja čak i kada je
eksponent negativan broj (ali i dalje cijeli broj). */

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
else if(eks<0){
    for(i=1;i<=-eks;i++){
    rez=rez*baza;
}
rez=1/rez;
printf("%g^%g = %g",baza,eks,rez);
}
else{
for(i=1;i<=eks;i++){
    rez=rez*baza;
}
printf("%g^%g = %g",baza,eks,rez);
}

return 0;
}


