/*#9 Napisati funkciju int string2double(const char* string, double *broj) koja proslijeđeni string pretvara u realan
broj. Prvo je potrebno provjeriti da li je string korektnog formata (da se sastoji od dva niza cifara razdvojenih
tačkom), a zatim izračunati i na memorijsku lokaciju na koju pokazuje parametar broj upisuje vrijednost koja je
reprezentovana stringom. Ako je format stringa pogrešan, funkcija treba vratiti vrijednost 0, a ako je format
korektan, funkcija treba da vrati 1. Primjer:
double d;
int a = string2double("123.123", &d);
treba da u varijablu d pohranjuje vrijednost 123.123, a u varijablu a vrijednost 1.*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int string2double(const char* string, double* broj)
{
	const char* p=string;
	int predznak=1,brojac=0,flag=0,korektan=0;
	double krajnji=0,temp=0,dec=0;
	/*prvo provjeriti jel ispravan format stringa*/
	
		/*upisivanje svih brojeva iz stringa u niz*/
		while(*string!='\0') {
			if(*string=='-') predznak=-1;
			if((*string<'0' || *string>'9') && *string!='.') {
				string++;
				continue;
			}
			while((*string>='0' && *string<='9') || *string=='.') {
				if(*string>='0' && *string<='9' && flag!=1) {
					temp=temp*10+*string-'0';//pretvaranje char u double*/
					string++;
				} else if(*string=='.' && *(string+1)>='0' && *(string+1)<='9') {
					/*ako je iza tacke neki broj, pretvorimo i taj ostatak u double*/
					flag=1;
					string++;
				} else if(flag==1) {
					dec=dec*10+*string-'0';
					brojac++;
					string++;
				}
			}
			dec=dec/pow(10,brojac);
			krajnji=(temp+dec)*predznak;
			*broj=krajnji;
		}
//ako je string bio korektan vrati 1, u suprotnom 0
		return 1;
	}

	int main() {
		double d;
		int a = string2double("123.123", &d);
		printf("%g\n",d);
		printf("%d",a);
		return 0;
	}
