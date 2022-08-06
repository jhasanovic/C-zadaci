#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

/*funkcija za unos matrica*/
void unesi(double mat[100][100],int m,int n)
{
	int i,j;
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%lf",&mat[i][j]);
		}
	}
}

/*funkcija za prebacivanje 2D niza u obicni niz*/
void matrica_u_niz(double mat[100][100],double niz[10000],int m,int n)
{
	int i,j,k=0;
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			niz[k]=mat[i][j];
			k++;
		}
	}
}

/*funkcija za sortiranje niza u rastucem poretku*/
void sortiraj(double niz[10000],int k)
{
	int i,j,min;
	double temp;
	for(i=0; i<k; i++) {
		min=i;
		for(j=i+1; j<k; j++) {
			if(niz[j]<niz[min])
				min=j;
		}
		temp=niz[i];
		niz[i]=niz[min];
		niz[min]=temp;
	}
}

int matrice_permutacija(double A[100][100],double B[100][100],double C[100][100],int M,int N)
{
	int i,vel,flag=1;
	double niza[10000],nizb[10000],nizc[10000];/*jer matrice mogu imati max 100*100 clanova*/

	/*prebacivanje 2D nizova u obicne*/
	matrica_u_niz(A,niza,M,N);
	matrica_u_niz(B,nizb,M,N);
	matrica_u_niz(C,nizc,M,N);

	/*sortiranje nizova u rastucem poretku*/
	vel=M*N;
	sortiraj(niza,vel);
	sortiraj(nizb,vel);
	sortiraj(nizc,vel);

	/*poredjenje matrica*/
	for(i=0; i<vel; i++) {
		if(fabs(niza[i]-nizb[i])<EPSILON && fabs(niza[i]-nizc[i])<EPSILON && fabs(nizb[i]-nizc[i])<EPSILON)
			flag=1;
		else { /*ako sva tri clana nisu jednaka, prekinuti petlju*/
			flag=0;
			break;
		}
	}
	if(flag==1) return 1;
	else return 0;
}

int main()
{
	int v,s,rezultat;
	double a[100][100],b[100][100],c[100][100];
	printf("Unesite dimenzije matrica: ");
	scanf("%d %d",&v,&s);
	unesi(a,v,s);
	unesi(b,v,s);
	unesi(c,v,s);
	rezultat=matrice_permutacija(a,b,c,v,s);
	printf("%d",rezultat);
	return 0;
}