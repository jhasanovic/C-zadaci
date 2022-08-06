/*#22 Napisati program koji od korisnika traži unos n matrica (n nije veći od 10) formata p × q (ni p i q nisu veći
od 5). Nakon toga program treba ispisati sume elemenata za sve matrice i onu matricu koja ima najveću sumu elemenata
(4 mjesta širine). */

#include <stdio.h>
 
int main() {
    int n,p,q;
    int i,j,k;
    int nizmatrica[10][5][5];
    int suma[10]={0};
    int max,maxi=0;
    do {
    printf("Unesite broj matrica: ");
    scanf ("%d",&n);
    if (n>10 || n<=0) printf ("Broj matrica mora biti u opsegu [1,10]\n");
    } while (n>10 || n<0);
    do {
        printf ("Unesite dimenzije matrice (p q): ");
        scanf ("%d %d",&p,&q);
        if (p>5 || q>5 || p<0 || q<0) printf ("p i q moraju biti u opsegu [1,5]\n");
    } while (p>5 || q>5 || p<0 || q<0);
    for (i=0; i<n; i++) {
        printf ("Matrica br. %d\n",i+1);
        for (j=0; j<p; j++) {
            printf ("%d. red: ",j+1);
            for (k=0; k<q; k++) {
                scanf ("%d",&nizmatrica[i][j][k]);
            }
        }
        printf("\n");
    }
   
    for (i=0; i<n; i++) {
        for (j=0; j<p; j++) {
            for (k=0; k<q; k++) {
                suma[i]=suma[i]+nizmatrica[i][j][k];
            }
        }
    }
    max=suma[0];
    for (i=0; i<n; i++) {
        if (suma[i]>max) {
            max=suma[i];
            maxi=i;
        }
    }
        printf ("\nSume za sve matrice, format \"matrica: suma\":\n");
    for (i=0; i<n; i++) {
        if (i<n-1)  printf ("%d: %d, ",i+1,suma[i]);
        else printf ("%d: %d",i+1,suma[i]);
    }
    printf ("\nMatrica s najvecom sumom:\n");
    for (i=0; i<p; i++) {
        for (j=0; j<q; j++) {
            printf("%4d",nizmatrica[maxi][i][j]);
        }
        printf("\n");
    }
    return 0;
}