/*Napisati funkciju min_pravougaonik koja prima niz vrijednosti tipa struct Tacka proizvoljne dužine, a vraća 
vrijednost tipa struct Pravougaonik. Vraćeni pravougaonik treba biti najmanji mogući pravougaonik koji sadrži sve
tačke navedene u primljenom nizu. Smatra se da pravougaonik sadrži tačku ako se tačka nalazi unutar ili na rubu 
pravougaonika.*/

#include <stdio.h>

struct Tacka {
	double x,y;
};

struct Pravougaonik {
	struct Tacka dolje_lijevo;
	struct Tacka gore_desno;
};

struct Tacka unos_tacke()
{
	struct Tacka t;
	scanf("%lf %lf",&t.x,&t.y);
	return t;
}

struct Pravougaonik min_pravougaonik(struct Tacka NizTacaka[],int n)
{
	struct Pravougaonik p;
	double x_min,y_min,x_max,y_max;
	int i;

	x_min=NizTacaka[0].x;
	y_min=NizTacaka[0].y;
	x_max=NizTacaka[0].x;
	y_max=NizTacaka[0].y;

	/*pronalazak koordinata najmanje i najvece tacke*/
	for(i=0; i<n; i++) {
		if(NizTacaka[i].x<x_min)
			x_min=NizTacaka[i].x;
		if(NizTacaka[i].y<y_min)
			y_min=NizTacaka[i].y;
		if(NizTacaka[i].x>x_max)
			x_max=NizTacaka[i].x;
		if(NizTacaka[i].y>y_max)
			y_max=NizTacaka[i].y;
	}
	p.dolje_lijevo.x=x_min;
	p.dolje_lijevo.y=y_min;
	p.gore_desno.x=x_max;
	p.gore_desno.y=y_max;

	return p;
}

int main()
{
	struct Tacka NizTacaka[1000];
	struct Pravougaonik p;
	int n=0,i=0;
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		printf("Unesite koordinate x i y tacke %d: ",i+1);
		NizTacaka[i]=unos_tacke();
	}
	p=min_pravougaonik(NizTacaka,n);
	printf("Minimalni pravougaonik za ove tacke ima uglove: \n(%g,%g) - (%g,%g)",p.dolje_lijevo.x,p.dolje_lijevo.y,
	       p.gore_desno.x,p.gore_desno.y);
	return 0;
}
