#include <stdio.h>
#define VEL 100000 
#define BROJAC 65536

int analiza() {
	unsigned short niz1[VEL], brojaci[BROJAC] = {0}, max, broj = 0; // jer je to najmanji moguci broj na datom intervalu
	int i, j, k, suma = 0, ucitano;
	FILE *ulaz; 
	ulaz = fopen("brojevi.dat", "rb"); 
	if (!ulaz) {
		printf("Greska pri otvaranju datoteke brojevi.dat");
		return -1; 
	}
	ucitano = fread(niz1, sizeof(short), VEL, ulaz); 
	if (ferror(ulaz)) {
		printf("Greska pri citanju iz datoteke brojevi.dat.\n");
		printf("Ucitano je samo %d brojeva", ucitano); 
		fclose(ulaz); 
		return -1;
	}
	for (i = 0; i < ucitano; i++) {
		brojaci[niz1[i]]++; 
	}
	 
	// trazenje broja koji se najviše ponavlja
	max = brojaci[0];
	for (i = 0; i < BROJAC; i++) {
		if (brojaci[i] > max) {
			max = brojaci[i]; 
			broj = i; 
		}
	}
	
	// izbacivanje elemenata koji se ponavljaju
	for (i = 0; i < ucitano; i++ ) {; 
		for (j = i + 1; j < ucitano; j++) {
			if (niz1[i] == niz1[j]) {
				for (k = j; k < ucitano - 1; k++) {
					niz1[k] = niz1[k + 1];
				}
				ucitano--;
				j--;
			}
		}
	}
	
	// racunanje sume
	for (i = 0; i < ucitano; i++) {
		if (niz1[i] > broj) {
			suma += brojaci[niz1[i]]; 
		}
	}
	return suma; 
}

int main() {
	FILE* izlaz = fopen("brojevi.dat", "wb");
	fputc(0, izlaz);
	fputc(0, izlaz);
	fputc(1, izlaz);
	fputc(0, izlaz);
	fclose(izlaz);
	printf("%d", analiza());
	return 0;
}