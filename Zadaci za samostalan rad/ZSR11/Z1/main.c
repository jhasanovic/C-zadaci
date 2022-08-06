/*Napisati funkciju pod imenom izbaci_pravougle koja prima niz trouglova i iz njega izbacuje sve pravougle 
trouglove bez promjene redoslijeda. Napravite i glavni program koji omogućuje testiranje ispravnog rada ove 
funkcije.*/

#include <stdio.h>
#include <math.h>

struct Tacka {
	int x,y;
};

struct Trougao {
	struct Tacka A,B,C;
};

struct Tacka unos_tacke()
{
	struct Tacka t;
	scanf("%d,%d",&t.x,&t.y);
	return t;
}

struct Trougao unesi_trougao()
{
struct Trougao tr;
tr.A=unos_tacke();
tr.B=unos_tacke();
tr.C=unos_tacke();

return tr;
}

int izbaci_pravougle(struct Trougao NizTrouglova[],int n){
	int i=0,j=0,flag;
	double a=0,b=0,c=0;
	for(i=0;i<n;i++){
		flag=0;
		/*provjera da li je trougao pravougli*/
		a=sqrt(pow(NizTrouglova[i].A.x-NizTrouglova[i].B.x,2)+pow(NizTrouglova[i].A.y-NizTrouglova[i].B.y,2));
		b=sqrt(pow(NizTrouglova[i].B.x-NizTrouglova[i].C.x,2)+pow(NizTrouglova[i].B.y-NizTrouglova[i].C.y,2));
		c=sqrt(pow(NizTrouglova[i].C.x-NizTrouglova[i].A.x,2)+pow(NizTrouglova[i].C.y-NizTrouglova[i].A.y,2));
		
		if(fabs(a-sqrt(pow(b,2)+pow(c,2)))<0.0001) flag=1;
		else if(fabs(b-sqrt(pow(a,2)+pow(c,2)))<0.0001) flag=1;
		else if(fabs(c-sqrt(pow(b,2)+pow(a,2)))<0.0001) flag=1;
		
		if(flag==1){/*jeste pravougli,izbaci ga iz niza*/
		for(j=i;j<n-1;j++) NizTrouglova[j]=NizTrouglova[j+1];
			n--;
			i--;
		}
		
	}
	return n;
}
int main()
{
	struct Trougao NizTrouglova[5];
    int i, n = 5;
   
    printf("Unesite trouglove.");
    for ( i = 0; i < 5; i++ ) {
        printf("\nTrougao %d.: ", i+1);
        NizTrouglova[0] = unesi_trougao();
    }
   
    printf("\nIzbaceno je %d trouglova.", n - izbaci_pravougle( NizTrouglova, n ));
   
    return 0;
}