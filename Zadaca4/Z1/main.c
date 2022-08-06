/*kopirana verzija sa zamgera 4.1. u 22.13*/
#include <stdio.h>
#include <math.h>

char* nadji_broj(char* string,double broj)
{
	int predznak=1,brojac=0,flag=0;
	double dec=0,krajnji=0,temp=0;
	char* pok;

	while(*string!='\0') {
		pok=string;
		if(*string=='-') predznak=-1;
		else if(*string==' ') {
			string++;
			continue;
		} else if(*string>='0' && *string<='9') {
			//poc=string;
			temp=0;
			dec=0;
			if(flag==0) {
				while(*string>='0' && *string<='9') {
					temp=temp*10+*string-'0';
					string++;
				}
			}
			if(*string=='.' && *(string+1)>='0' && *(string+1)<='9') {
				flag=1;
				string++;
			}
			if(flag==1) {
				flag=0;
				while(*string>='0' && *string<='9') {
					dec=dec*10+*string-'0';
					brojac++;
					string++;
				}
			}
			krajnji=(temp+(dec/pow(10,brojac)))*predznak;
			if(fabs(krajnji-broj)<0.0001) {
				if(krajnji<0)
					return --pok;/*ako je broj negativan, vrati na predznak minus*/
				else
					return pok;
			}
		} else {
			predznak=1,brojac=0,flag=0,krajnji=0;
		}
		string++;
	}
	return NULL;
}

char* nadji_zbir(char* s)
{
	char* pok=s;
	char* poc=s;
	int predznak=1,brojac=0,flag=0,i=0,j=0,trazeni=-1;
	double krajnji=0,temp=0,dec=0,niz[100];
	/*upisivanje svih brojeva iz stringa u niz*/
	while(*s!='\0') {
		if(*s=='-') predznak=-1;
		if((*s<'0' || *s>'9') && *s!='.') {
			s++;
			continue;
		}
		while((*s>='0' && *s<='9') || *s=='.') {
			if(*s>='0' && *s<='9' && flag!=1) {
				temp=temp*10+*s-'0';//pretvaranje char u double*/
				s++;
			} else if(*s=='.' && *(s+1)>='0' && *(s+1)<='9') {
				/*ako je iza tacke neki broj, pretvorimo i taj ostatak u double*/
				flag=1;
				s++;
			} else if(flag==1) {
				dec=dec*10+*s-'0';
				brojac++;
				s++;
			}
		}
		dec=dec/pow(10,brojac);
		krajnji=(temp+dec)*predznak;
		niz[i]=krajnji;/*popunjavamo niz brojevima iz stringa*/
		i++;
		/*resetujemo varijable*/
		temp=0,dec=0,krajnji=0,brojac=0,flag=0,predznak=1;
		s++;
	}
	//if(i==0) return NULL;
	/*poredjenje clanova double niza, trazenje prvog broja koji ispunjava uslov*/
	for(j=0; j<i-2; j++) {
		if(fabs(niz[j+2]-(niz[j]+niz[j+1]))<0.0001) {
			trazeni=j;
			break;
		}
	}
	if(trazeni==-1 || i<3) return NULL;/*nijedna trojka ne ispunjava uslov ili nedovoljno clanova*/
	/*pozovemo funkciju koja trazi broj u stringu*/
	poc=nadji_broj(pok,niz[trazeni]);
	return poc;
}

void razlike(char* s){
	int flag=0,brojac=0,flag2=0,brojac2=0;
	double prvi=0,drugi=0,predznak=1,temp=0,dec=0,predznak2=1,temp2=0,dec2=0;
	char* pok=s;
	char* q;
	pok=nadji_zbir(pok);
    q=pok;
	do{
	pok=nadji_zbir(pok);/*pozivamo prvu funkciju, tako da pokazivac s pokazuje na prvi broj u stringu
	koji zadovoljava uslov*/
	if(pok==NULL){
		break;
	}
	char* q=pok;
    while((*q>='0' && *q<='9') || *q=='.' || *q=='-'){
   	q++;
    }
   	/*sad pokazuje iza prvog broja*/
   	q++;
   	while((*q<'0' || *q>'9') && *q!='-')/*q pomaknemo na sljedeci broj*/
   	q++;
   	
		if(*pok=='-') {
		predznak=-1;
		pok++;
		}
		if(*q=='-'){
			predznak2=-1;
			q++;
		}
		if(*pok>='0' && *pok<='9') {
			temp=0;
			dec=0;
			if(flag==0) {
				while(*pok>='0' && *pok<='9') {
					temp=temp*10+*pok-'0';
					pok++;
				}
			}
			if(*pok=='.' && *(pok+1)>='0' && *(pok+1)<='9') {
				flag=1;
				pok++;
			}
			if(flag==1) {
				flag=0;
				while(*pok>='0' && *pok<='9') {
					dec=dec*10+*pok-'0';
					brojac++;
					pok++;
				}
			}
			prvi=(temp+(dec/pow(10,brojac)))*predznak;
}
		if(*q>='0' && *q<='9') {
			temp2=0;
			dec2=0;
			if(flag2==0) {
				while(*q>='0' && *q<='9') {
					temp2=temp2*10+*q-'0';
					q++;
				}
			}
			if(*q=='.' && *(q+1)>='0' && *(q+1)<='9') {
				flag2=1;
				q++;
			}
			if(flag2==1) {
				flag2=0;
				while(*q>='0' && *q<='9') {
					dec2=dec2*10+*q-'0';
					brojac2++;
					q++;
				}
			}
			drugi=(temp2+(dec2/pow(10,brojac2)))*predznak2;
}
printf("%g - %g = %g\n",prvi,drugi,(prvi-drugi));
predznak=1,predznak2=1,brojac=0,brojac2=0,flag=0,flag2=0,prvi=0,drugi=0;
}while(pok!=NULL && *q!='\0');
}

int main()
{
razlike("Od 3 broja u stringu, zbir -0.1 i 1.55 daje 1.25 ili 2.8?");
return 0;
}