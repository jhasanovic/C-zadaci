/*#11 Koristeći isključivo pokazivaču aritmetiku napisati funkciju max_el koja vraća pokazivač na najveći elemenat u 
nizu. Prototip funkcije izgleda ovako: int *max_el(int *p1, int *p2)
Paziti da ova funkcija ne vrati „viseći“ pokazivač tj. pokazivač na neku varijablu koja prestaje postojati u funkciji!*/

#include <stdio.h>

int* max_el(int* p1,int* p2){
 int* pok=p1;
 int max=*p1;
 while(p1<p2){
  if(*p1>max){
   max=*p1;
   pok=p1;
  }
  p1++;
 }
 return pok;
}

int* min_el(int* p1,int* p2){
 int* pok=p1;
 int min=*p1;
 while(p1<p2){
  if(*p1<min){
   min=*p1;
   pok=p1;
  }
  p1++;
 }
 return pok;
}
int main(){
 int niz[7] = {1, 2, 9, 8, 4, 0, 1};
    int *p = max_el(niz, niz + 7);
    int *q = min_el(niz, niz + 7);
    printf("Maksimalni element niza je %d, a minimalni %d.",*p,*q);
 return 0;
}