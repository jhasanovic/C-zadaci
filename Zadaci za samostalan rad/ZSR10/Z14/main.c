/*#14 (II parcijalni ispit 2014/15; Završni ispit 2015/16; Zadaća 4, 2016/17) Dat je niz tačaka u 2D koordinatnom
sistemu pri čemu je svaka tačka opisana sa dvije koordinate koje su realni brojevi (pozitivni ili negativni).
Potrebno je napraviti funkciju obuhvat koja prima niz tačaka te iz njega izbacuje sve tačke koje se ne nalaze
unutar neke pravougaone površine. No ulaz u ovu funkciju je u formi stringa koji izgleda ovako:
"(0,-3.1),(-15.09,4),(2.,2),(-1.1,217)" (bez navodnika). U ovom stringu se ne nalaze razmaci, odnosno string se
sastoji isključivo od: cifara, znaka minus, zareza, tačke, otvorenih i zatvorenih malih zagrada. Unutar zagrada se
nalaze dva realna broja razdvojena zarezom. U sklopu broja se može nalaziti znak tačka koji predstavlja decimalnu
tačku, a ako se iza tačke ne nalazi cifra podrazumijeva se cifra nula. Ovakvi parovi koordinata se nalaze u
zagradama koje su razdvojene zarezom s tim što se nakon posljednjeg i prije prvog para ne nalazi znak zarez. Ako
primljeni string nije ispravno formatiran tj. ne zadovoljava bilo koji od nabrojanih uslova, funkcija treba da vrati
NUL pokazivač, no prazan string "" je ispravan string koji ne sadrži niti jednu tačku. Pretpostavite da se
svi realni brojevi mogu predstaviti tipom float (ovo ne morate provjeravati). Napisati funkciju obuhvat koja prima
ovako formiran C string i četiri realna broja x1,y1, x2 i y2 koji predstavljaju koordinate donjeg-lijevog i
gornjeg-desnog ugla pravougaonika, zatim string modificira tako da iz njega izbacuje tačke koje se ne
nalaze unutar pravougaonika, a da pri tome string ostaje ispravno formatiran kao u gornjem primjeru. Za elemente na
rubu pravougaonika se smatra da su unutar pravougaonika. Npr. za gornji string, ako su parametri -3, -3, 3, 3
funkcija treba modificirati primljeni string tako da on glasi:
"(2.,2)" (bez navodnika). Unutar pravougaonika (-3,-3) - (3,3) nalazi se tačka (2,2), a tačke (0,-3.1), (-15.09,4)
i (-1.1,217) se ne nalaze u njemu. Radi lakše upotrebe funkcija treba vraćati pokazivač na početak primljenog stringa.
Ako se niti jedna od tačaka ne nalazi u pravougaoniku, rezultat treba biti prazan string "". Kod poređenja realnih
brojeva koristiti ε = 0.0001. */

#include <stdio.h>
#include <stdlib.h>
#define eps 0.0001

char* obuhvat(char*tekst, double x1, double y1, double x2, double y2) //donji lijevi i gornjidesni
{
	char*krajprosle;

	char*s=tekst;
	//na broju
	double x=0,y=0;
	while(*s!='\0' ) {
		//  if(!((*s>=0 && *s<=9) || *s=='-' || *s=='.' || *s==',')) return 0;
		int imadec=0,predznak=1;
		char*poc;

		if(*s='(') {
			poc=s;
			s++;
		}
		x=0;
		double o=0.1;
		while(*s!=',') {
			//  if(!((*s>=0 && *s<=9) || *s=='-' || *s=='.' || *s==',')) return 0;

			if(*s=='-') {
				s++;
				predznak=-1;
			}
			if(*s=='.') {
				imadec=1;
				s++;
			}
			if(*s==',') break;


			if(imadec==0) {
				x=x*10+(*s-48);

			} else {
				x=x+(*s-48)*o;
				o=o/10;
			}

			s++;
		}
		x=x*predznak;
		imadec=0,predznak=1;
		s++;
		y=0;

		o=0.1;
		while(*s!=')') {

			if(*s=='-') {
				s++;
				predznak=-1;
			}
			if(*s=='.') {
				imadec=1;
				s++;
			}
			if(imadec==0) {
				y=y*10+(*s-48);

			} else {
				y=y+(*s-48)*o;
				o=o/10;
			}
			s++;
		}
		y=y*predznak;
		krajprosle=s;


		char*a=poc;
		int izb=0;
		if(y>y2 || y<y1|| x<x1 ||x>x2) {
			//izbacit
			izb=1;
			if(*(s+1)=='\0') {
				*(poc-1)='\0';
				return tekst;
			} else {
				char*hod=s+2;
				while(*hod!='\0') {
					*poc=*hod;
					poc++;
					hod++;
				}
				*poc='\0';

			}
		}
		if(izb) {
			s=a;
			s-=2;
		}
		s++;
		s++;
	}
	return tekst;
}

int main()
{

	char s[] = "(2.,2)";
	char* rez = obuhvat(s, -3, -3, 3, 3);
	printf("%s %s", rez, s);


	return 0;
}
