#include <stdio.h>

struct Student {
char ime[20], prezime[20];
int ocjene[50];
int br_ocjena;
};

int genijalci(struct Student Niz[],int n,double prosjek){
	int i=0,j=0,jel=0,t=0,zbir=0,izbaceni=0;
	
	for(i=0;i<n;i++){
		zbir=0;
		jel=0;
		for(t=0;t<50;t++){
			zbir+=Niz[i].ocjene[t];
		}
	jel=zbir/Niz[i].br_ocjena;
	if(jel<prosjek){
		for(j=i;j<n-1;j++){
			Niz[j]=Niz[j+1];
		}
		izbaceni++;
		n--;
		i--;
	}
	}
	//return izbaceni;
}
int main() {
      struct Student studenti[] = {

            {"Meho", "Behic", {10, 9}, 2},
            {"Meho", "Aehic", {10, 8}, 2},
            {"Meho", "Cehic", {10, 9, 8, 7, 6}, 5},
            {"Meho", "Dehic", {6, 9}, 2},
            {"Meho", "Zehic", {10}, 1},
            {"Meho", "Oehic", {10, 9, 9, 9}, 4}
        };
        
        int vel = sizeof studenti / sizeof studenti[0], i;
        vel = genijalci(studenti, vel, 9.);
        printf("Vel: %d\nStudenti:\n", vel);
        for (i = 0; i < vel; ++i)
            printf ("%s %s\n", studenti[i].prezime, studenti[i].ime);
	return 0;
}
