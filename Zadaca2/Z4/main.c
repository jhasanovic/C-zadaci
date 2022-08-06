#include <stdio.h>
#include <math.h>
int main() {
	double niz[25]={0},ukupno=0,kombinacija,mat[100][3];
	int i,j,n=0,racun[100],prvi,prekini=0,drugi,nema=0;
	
//unos cijena
for(i=1;i<=25;i++){
	scanf("%lf",&niz[i]);
	if(niz[i]<0) i--;
}

//unos kombinacija u matricu
for(i=1;i<=100;i++){
		printf("Unesite kombinaciju: ");
		scanf("%lf",&mat[i][1]);
		if(mat[i][1]<0.01){
		prekini=1;
		break;
		}
		scanf("%lf",&mat[i][2]);
		scanf("%lf",&mat[i][3]);
		prvi=(int)mat[i][1];
		drugi=(int)mat[i][2];
		if( mat[i][3]>=(niz[prvi]+niz[drugi]) || (mat[i][3]-(niz[prvi]+niz[drugi])<0.01)){
			printf("Neispravna kombinacija!");
			i--;
			printf("\n");
		}
	
		n++;
}
	


do{
	ukupno=0;
printf("Unesite racun: ");
//unos racuna
	for(i=1;i<=100;i++){
    scanf("%d",&racun[i]);

if(racun[i]==0){
break;
}

else if(racun[i]>25 || racun[i]<1){
	printf("Unos neispravan.");
	nema=1;

}
else if(niz[racun[i]]==0){
printf("Jelo nije u ponudi.");
nema=1;
}

if(racun[i]!=0){
	ukupno+=niz[racun[i]];
}

}
if(ukupno!=0){
	printf("Ukupan iznos racuna je: %.2f KM\n",ukupno);
	i=0;
}

}while(racun[1]!=0 || nema==1);

	return 0;
}
