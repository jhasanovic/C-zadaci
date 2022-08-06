#include <stdio.h>

int main() {
double prvi_t,drugi_t,prisustvo_t,zadace_t,zavrsni_t, 
prvi_b,drugi_b,prisustvo_b,zadace_b,zavrsni_b,
prvi_m,drugi_m,prisustvo_m,zadace_m,zavrsni_m,
bodovi_b=0,bodovi_m=0,bodovi_t=0;
int flag_t=0,flag_b=0,flag_m=0,ocjena_t=0,ocjena_b=0,ocjena_m=0;

//unos bodova za Tarika
printf("Unesite bodove za Tarika:\n");
printf("I parcijalni ispit: ");
scanf("%lf",&prvi_t);
if(prvi_t<0 || prvi_t>20){
    printf("Neispravan broj bodova");
    return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf",&drugi_t);
if(drugi_t<0 || drugi_t>20){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Prisustvo: ");
scanf("%lf",&prisustvo_t); 
if(prisustvo_t<0 || prisustvo_t>10){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%lf",&zadace_t);
if(zadace_t<0 || zadace_t>10){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf",&zavrsni_t);
if(zavrsni_t<0 || zavrsni_t>40){
    printf("Neispravan broj bodova");
    return 0;
}
//unos bodova za Bojana
printf("Unesite bodove za Bojana:\n");
printf("I parcijalni ispit: ");
scanf("%lf",&prvi_b);
if(prvi_b<0 || prvi_b>20){
    printf("Neispravan broj bodova");
    return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf",&drugi_b);
if(drugi_b<0 || drugi_b>20){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Prisustvo: ");
scanf("%lf",&prisustvo_b);
if(prisustvo_b<0 || prisustvo_b>10){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%lf",&zadace_b);
if(zadace_b<0 || zadace_b>10){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf",&zavrsni_b);
if(zavrsni_b<0 || zavrsni_b>40){
    printf("Neispravan broj bodova");
    return 0;
}
//unos bodova za Mirzu
printf("Unesite bodove za Mirzu:\n");
printf("I parcijalni ispit: ");
scanf("%lf",&prvi_m);
if(prvi_m<0 || prvi_m>20){
    printf("Neispravan broj bodova");
    return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf",&drugi_m);
if(drugi_m<0 || drugi_m>20){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Prisustvo: ");
scanf("%lf",&prisustvo_m);
if(prisustvo_m<0 || prisustvo_m>10){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%lf",&zadace_m);
if(zadace_m<0 || zadace_m>10){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf",&zavrsni_m);
if(zavrsni_m<0 || zavrsni_m>40){
    printf("Neispravan broj bodova");
    return 0;
}


//ukupni bodovi
bodovi_t=prvi_t+drugi_t+prisustvo_t+zadace_t+zavrsni_t;
bodovi_b=prvi_b+drugi_b+prisustvo_b+zadace_b+zavrsni_b;
bodovi_m=prvi_m+drugi_m+prisustvo_m+zadace_m+zavrsni_m;
if(bodovi_t>=55)
flag_t=1;
if(bodovi_b>=55)
flag_b=1;
if(bodovi_m>=55)
flag_m=1;

//razvrstavanje po ocjenama
if(bodovi_t>=55 && bodovi_t<65)
ocjena_t=6;
else if (bodovi_t>=65 && bodovi_t<75)
ocjena_t=7;
else if (bodovi_t>=75 && bodovi_t<85)
ocjena_t=8;
else if (bodovi_t>=85 && bodovi_t<92)
ocjena_t=9;
else if (bodovi_t>=92 && bodovi_t<=100)
ocjena_t=10;

if(bodovi_b>=55 && bodovi_b<65)
ocjena_b=6;
else if (bodovi_b>=65 && bodovi_b<75)
ocjena_b=7;
else if (bodovi_b>=75 && bodovi_b<85)
ocjena_b=8;
else if (bodovi_b>=85 && bodovi_b<92)
ocjena_b=9;
else if (bodovi_b>=92 && bodovi_b<=100)
ocjena_b=10;

if(bodovi_m>=55 && bodovi_m<65)
ocjena_m=6;
else if (bodovi_m>=65 && bodovi_m<75)
ocjena_m=7;
else if (bodovi_m>=75 && bodovi_m<85)
ocjena_m=8;
else if (bodovi_m>=85 && bodovi_m<92)
ocjena_m=9;
else if (bodovi_m>=92 && bodovi_m<=100)
ocjena_m=10;

//provjera koliko studenata je polozilo
if(flag_t==1 && flag_b==1 && flag_m==1)
printf("Sva tri studenta su polozila.\n");
else if(flag_t==0 && flag_b==0 && flag_m==0)
printf("Nijedan student nije polozio.\n");
else if((flag_t==1 && flag_b==1 && flag_m==0)|| (flag_t==1 && flag_b==0 && flag_m==1)||(flag_t==0 && flag_b==1 && flag_m==1))
printf("Dva studenta su polozila.\n");
else if((flag_t==1 && flag_b==0 && flag_m==0)|| (flag_t==0 && flag_b==1 && flag_m==0)||(flag_t==0 && flag_b==0 && flag_m==1))
printf("Jedan student je polozio.\n");

//ako su sva tri polozila, provjeravamo da li su ocjene iste
if(flag_t==1 && flag_b==1 && flag_m==1){
    if(ocjena_t==ocjena_m && ocjena_t==ocjena_b && ocjena_m==ocjena_b)
    printf("Sva tri studenta imaju istu ocjenu.");
    if(ocjena_t!=ocjena_m && ocjena_t!=ocjena_b && ocjena_b!=ocjena_m)
    printf("Svaki student ima razlicitu ocjenu.");
    else
    printf("Dva od tri studenta imaju istu ocjenu.");
    
}


	return 0;
}
