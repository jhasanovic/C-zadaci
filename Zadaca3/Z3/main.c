#include <stdio.h>

/*funkcija koja provjerava da li je broj Fibonaccijev*/
int je_li_Fibonaccijev_broj(int n)
{
	int prvi=1,drugi=1,sljedeci;
	if(n==prvi || n==drugi) return 1;
	sljedeci=prvi+drugi;
	while(sljedeci<=n) {
		if(n==sljedeci) return 1;
		prvi=drugi;
		drugi=sljedeci;
		sljedeci=prvi+drugi;
	}
	return 0;
}

int provjeri(int mat[100][100],int V)
{
	int i,j,niz[100]= {0},flag=1;
	for(i=0; i<V; i++) {
		for(j=0; j<100; j++) { /*j ide do 100 jer nije poznato koliko kolona matrica ima*/
			if(mat[i][j]<1 && mat[i][j]!=-1) {
				niz[i]=0;
				break;
			}
			if(mat[i][j]==-1) {
				niz[i]=1;
				break; /*prekidamo unutrasnju petlju*/
			}
		}
	}
	/*provjeravamo da li je svaki clan niza jednak 1, tj svaki red validan*/
	for(i=0; i<V; i++) {
		if(niz[i]!=1) {
			flag=0;
			break;
		}
	}
	if(flag==1) return 1;
	else return 0;
}

int fibonacci_matrica(int mat[100][100],int V)
{
	int i,j,fibo=1,provjera,provjera2;
	for(i=0; i<V; i++) {
		j=0;
		/*ako je red matrice prazan*/
		if(mat[i][0]==-1) {
			i++;
			continue;
		}
		/*ako red sadrzi samo jedan clan*/
		if(mat[i][0]!=-1 && mat[i][1]==-1) {
			provjera=je_li_Fibonaccijev_broj(mat[i][0]);
			if(provjera==0) fibo=0;
			else continue;
		}
		while(mat[i][j+2]!=-1) {
			provjera2=je_li_Fibonaccijev_broj(mat[i][j]);
			/*if(provjera2==0)
			fibo=0;*/
			if(provjera2==0 || mat[i][j+2]!=(mat[i][j+1]+mat[i][j]))
				fibo=0;/*kontrolnu varijablu postavimo na 0 ako je nadjen dio koji nije dio Fibonaccijevog niza*/
			j++;
		}

	}

	if(fibo==1) return 1;
	else return 0;
}

int main()
{
	int mat[100][100],v,i,j,x,y;
	do {
		printf("Unesite visinu matrice: ");
		scanf("%d",&v);
	} while(v<1);
	printf("Unesite matricu: ");
	for(i=0; i<v; i++) {
		for(j=0; j<100; j++) {
			scanf("%d",&mat[i][j]);
			if(mat[i][j]<=0 && mat[i][j]!=-1)/*ako je unesen broj manji od 1 ponoviti unos elementa*/
				j--;
			else if (mat[i][j]==-1)
				break;
		}
	}
	x=provjeri(mat,v);
	if(x==1)
		printf("\nMatrica je validna.");
	y=fibonacci_matrica(mat,v);
	if(y==1)
		printf("\nMatrica je Fibonacci matrica.");
	else printf("\nMatrica nije Fibonacci matrica.");
	return 0;
}