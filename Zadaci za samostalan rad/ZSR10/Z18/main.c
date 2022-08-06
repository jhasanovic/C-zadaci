/*ALGORITMI SA NIZOVIMA*/

//1)ubacivanje u niz
for (i=0; i<n; i++) {
if (uslov) {
for (j=n; j>i; j--)
niz[j] = niz[j-1];
n++;
niz[i] = ubaceni;
}
}

//2.1)izbacivanje iz niza(bez ocuvanja redoslijeda)
for (i=0; i<n; i++) {
if (niz[i] % 2 != 0) {
niz[i] = niz[n-1];
n--;
i--;
}
}

//2.2)izbacivanje iz niza(sa ocuvanjem redoslijeda)
for (i=0; i<n; i++) {
if (niz[i] % 2 != 0) {
for (j=i; j<n-1; j++) {
niz[j] = niz[j+1];
}
n--;
i--;
}
}

//3)maksimum
max = niz[0];
for (i=1; i<BROJ_EL; i++) {
if (niz[i] > max)
max = niz[i];
}

//4)minimum
min = niz[0];
for (i=1; i<BROJ_EL; i++) {
if (niz[i] < min)
min = niz[i];
}

//5)histogram
for (i=0; i<n; i++)
brojaci[niz[i]]++;

//6)max i min pojavljivanje
maxi = 0;
mini = -1;
for (i=0; i<=100; i++) {
if (brojaci[i] > brojaci[maxi]) {
maxi = i;
}
if (brojaci[i] > 0 && (mini == -1 || brojaci[i] < brojaci[mini]) {
mini = i;
}
}

//7)sortiranje niza
for (i=0; i<n; i++) {
min=i;
for (j=i+1; j<n; j++) {
if (niz[j] < niz[min])
min = j;
}
temp = niz[i];
niz[i] = niz[min];
niz[min] = temp;
}

/*ALGORITMI S MATRICAMA*/
//1)suma elemenata na glavnoj dijagonali
#include <stdio.h>
 #define SIRINA 5
 int main() {
 int i, j, suma=0, mat[SIRINA][SIRINA];
 for (i=0; i<SIRINA; i++)
 for (j=0; j<SIRINA; j++)
 scanf("%d", &mat[i][j]);
 for (i=0; i<SIRINA; i++)
 for (j=0; j<SIRINA; j++)
 if (i==j)
 suma += mat[i][j];

 printf("Suma elemenata na glavnoj dijagonali je %d\n", suma);
 return 0;
}

//2)izbacivanje kolone
/* Izbacivanje kolone maxk */
	for (i=0; i<visina; i++)
		matrica[i][maxk] = matrica[i][sirina-1];
	sirina--;


