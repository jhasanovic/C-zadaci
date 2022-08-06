/*#9 Napisati program koji od korisnika traži unos 10 prirodnih brojeva, te parne brojeve ispisuje 
desno poravnate, a neparne lijevo poravnate. Ispis je potrebno vršiti na 15 mjesta širine, 
pri čemu kod parnih brojeva prazna mjesta treba ispuniti nulama.*/

#include <stdio.h>

int main() {
	int a,b,c,d,e,f,g,h,i,j;
	printf("Unesite 10 prirodnih brojeva: ");
	scanf("%d %d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);
	if(a%2==0) printf("%015d\n",a); else printf("%-015d\n",a);
	if(b%2==0) printf("%015d\n",b); else printf("%-015d\n",b);
	if(c%2==0) printf("%015d\n",c); else printf("%-015d\n",c);
	if(d%2==0) printf("%015d\n",d); else printf("%-015d\n",d);
	if(e%2==0) printf("%015d\n",e); else printf("%-015d\n",e);
	if(f%2==0) printf("%015d\n",f); else printf("%-015d\n",f);
	if(g%2==0) printf("%015d\n",g); else printf("%-015d\n",g);
	if(h%2==0) printf("%015d\n",h); else printf("%-015d\n",h);
	if(i%2==0) printf("%015d\n",i); else printf("%-015d\n",i);
	if(j%2==0) printf("%015d\n",j); else printf("%-015d\n",j);
	return 0;
}
