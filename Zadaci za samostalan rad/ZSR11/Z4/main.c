#include <stdio.h>

struct Kompleksni{
	double Re,Im;
};

int izbaci_prvi_kvadrant(struct Kompleksni Niz[],int n){
	int i=0,j=0,izbaceni=0;
	for(i=0;i<n;i++){
		if(Niz[i].Re>0 && Niz[i].Im>0){
			for(j=i;j<n-1;j++){
				Niz[j]=Niz[j+1];
			}
			izbaceni++;
				n--;
				i--;
		}
	}
	return izbaceni;
}

int main() {
struct Kompleksni Niz[5]={{1,2},{-7,3},{8,-1},{2,1},{9,7}};
int izbaceni=-546;
izbaceni=izbaci_prvi_kvadrant(Niz,5);
printf("%d",izbaceni);
	return 0;
}
