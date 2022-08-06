/*#23 (Zadaća 2, 2016/17; I parcijalni ispit 2015/16) U matematici je poznat pojam Teplicove matrice. Teplicova
matrica je matrica kod koje su svi elementi na glavnoj dijagonali međusobno jednaki, ali su i na svakoj dijagonali
koja je paralelna sa glavnom dijagonalom svi elementi također međusobno jednaki.
Također su poznate Cirkularne matrice. Cirkularna matrica je matrica kod koje svaki red ima iste elemente kao red
iznad pomaknute za jedno mjesto u desno, pri čemu element koji je u prethodnom redu bio posljednji u sljedećem
postaje prvi. Možemo zaključiti da je svaka cirkularna matrica ujedno i Teplicova, dok obrnuto ne važi.*/
#include <stdio.h>
#include <math.h>

int main()
{
	int i=0,j=0,m=0,n=0,teplicova=1,cirkularna=1;
	double mat[100][100];
	do {
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if(!(m>0 && m<=100) || !(n>0 && n<=100))
			printf("Pogresan unos!\n");
	} while(!(m>0 && m<=100) || !(n>0 && n<=100));

	/*unos matrice*/
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%lf",&mat[i][j]);
		}
	}
	/*provjera za Teplicovu*/
	for(i=0; i<m-1; i++) {
		for(j=0; j<n-1; j++) {
			if(fabs(mat[i][j]-mat[i+1][j+1])>0.0001) {
				teplicova=0;
				break;
			}
		}
		if(teplicova==0)
			break;
	}

	/*provjera za cirkularnu*/
	for(i=1; i<m; i++) {
		for(j=0; j<n; j++) {
			if(j==0) {
				if(fabs(mat[i][j]-mat[i-1][n-1])>0.0001) {
					cirkularna=0;
					break;
				}
			} else {
				if(fabs(mat[i][j]-mat[i-1][j-1])>0.0001) {
					cirkularna=0;
					break;
				}
			}
			if(cirkularna==0)
				break;
		}
	}
	if(cirkularna==1)
		printf("Matrica je cirkularna");
	else if(teplicova==1)
		printf("Matrica je Teplicova");
	else
		printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
