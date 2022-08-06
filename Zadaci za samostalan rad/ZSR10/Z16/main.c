/*#16 Na predavanjima i u tutorijalu 10 data je funkcija zamijeni1 koja sva pojavljivanja cifre 1 zamjenjuje sa
rječju "jedan" . Sada prepravite tu funkciju u funkciju zamijeni_broj. Funkcija treba primati string i jednu
vrijednost tipa int koja predstavlja cifru koja se zamjenjuje. Primljenu cifru treba zamijeniti njenim imenom (0
sa "nula", 1 sa "jedan", 2 sa "dva" itd.)*/

#include <stdio.h>

void unesi(char niz[], int velicina)
{
char znak = getchar();
if(znak=='\n') znak = getchar();
int i=0;
while(i<velicina-1 && znak != '\n'){
niz[i]=znak;
i++;
znak=getchar();
}
niz[i]='\0';
}

char* zamijeni_broj(char* s, int broj)
{
char* niz[]= {"nula","jedan","dva","tri","cetiri","pet","sest","sedam","osam","devet"};
int duzina[]={3,4,2,2,5,2,3,4,3,4};
int i;
char* poc=s;
while(*s!='\0') {
if (*s==broj+'0'){
char* kraj=s;
while (*kraj!='\0') kraj++;
while (kraj>s){
*(kraj+duzina[broj]) = *kraj;
kraj--;
 
}
for(i=0;i<=duzina[broj];i++){
*s++=niz[broj][i];
}
s--;
 
}
s++;
}
return poc;
}
int main()
{
char tekst[100];
int broj;
printf("Unesite broj: ");
scanf("%d",&broj);
printf("Unesite tekst: ");
unesi(tekst,100);
printf("Nakon zamjene: %s", zamijeni_broj(tekst,broj));
 
return 0;
}