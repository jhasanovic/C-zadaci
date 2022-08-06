#include <stdio.h>
#include <math.h>
int main() {
	char spol;
	int ulaz,kg,sedmicno=0,sedmice=0;
	double visina,obim,masa,rfm_m,rfm_z,bmi,novi_bmi;
	
	do{
	printf("Unesite spol (mM/zZ), visinu (u cm), obim struka (u cm), tezinu (u kg): ");
	scanf(" %c %lf %lf %lf",&spol,&visina,&obim,&masa);
	if((visina<100 || visina>220) || (obim<40 || obim>200) || (masa>200))
	printf("\nGreska u unosu atributa.\n");
	else if (spol!='M' && spol!='m' && spol!='Z' && spol!='z')
	printf("\nGreska u unosu za spol.\n");
	}while((spol!='M' && spol!='m' && spol!='Z' && spol!='z') || (visina<100 || visina>220) || (obim<40 || obim>200) || (masa>200));

    do{
   	printf("Odaberite zeljenu opciju za trening:\n");
	printf("[1] Joga\n");
	printf("[2] Joga PLUS\n");
	printf("[3] Cardio\n");
	printf("[4] Super cardio\n");
	printf("[5] Total Body\n");
	printf("[6] Body Builder\n");
	printf(">> ");
	scanf("%d",&ulaz);
	if(ulaz<1 || ulaz>6)
	printf("Greska u odabiru opcija.\n");
    }while(ulaz<1 || ulaz>6);
    
    do{
	printf("Unesite broj kilograma za koliko zelite smanjiti svoju masu (1-10): ");
	scanf("%d",&kg);
	if(kg<1 || kg>10)
	printf("Greska u unosu za kilazu. Ocekivane vrijednosti: (1-10).");
    }while(kg<1 || kg>10);
    
    bmi=masa/pow(visina/100,2);
	novi_bmi=(masa-kg)/pow(visina/100,2);
	if((novi_bmi<18.5 && ulaz!=1 && ulaz!=2) || (bmi<18.5 && ulaz!=1 && ulaz!=2)){
	printf("Odabrani program nije preporucen uz predate podatke.");
	return 0;
	}
	else if(bmi<18.5)
	printf("Vas BMI iznosi: %.2f (nizak).\n",bmi);
	else if(bmi>=18.5 && bmi<25)
	printf("Vas BMI iznosi: %.2f (normalan).\n",bmi);
	else if(bmi>=25 && bmi<30)
	printf("Vas BMI iznosi: %.2f (povisen).\n",bmi);
	else if(bmi>=30)
	printf("Vas BMI iznosi: %.2f (visok).\n",bmi);
	
	rfm_m=64-(20*visina/obim);
	rfm_z=76-(20*visina/obim);
	if(spol=='m' || spol=='M')
	printf("Vas RFM iznosi: %.2f %%.\n",rfm_m);
	else
	if(spol=='z' || spol=='Z')
	printf("Vas RFM iznosi: %.2f %%.\n",rfm_z);
	
	if(ulaz==1)
	sedmicno=1000;
	else if(ulaz==2)
	sedmicno=1500;
	else if(ulaz==3)
	sedmicno=2000;
	else if(ulaz==4)
	sedmicno=2500;
	else if(ulaz==5 || ulaz==6)
	sedmicno=3000;

	sedmice=(7000*kg)/sedmicno;
	if(bmi>=18.5)
	printf("Minimalni broj sedmica za treniranje: %d.",sedmice);
	return 0;
}
