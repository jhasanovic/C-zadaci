#include <stdio.h>

int main() {
	char pol;
	double visina_cm,visina_inc,razlika,idealna,trenutna;
	printf("Unesite pol (M/Z): ");
	scanf("%c",&pol);
	printf("Unesite visinu (u cm): ");
	scanf("%lf",&visina_cm);
	printf("Unesite trenutnu tezinu: ");
	scanf("%lf",&trenutna);
	
	visina_inc=visina_cm/2.54;
	
	if(pol=='M')
	idealna=50+2.3*(visina_inc-60);
	else if(pol=='Z')
    idealna=45.5+2.3*(visina_inc-60);
    
    if(idealna-trenutna<3 && idealna-trenutna>-3)
    printf("Vasa tezina je uredu");
    else if(idealna-trenutna>=3){
    	razlika=idealna-trenutna;
    printf("Potrebno je da se ugojite %g kilograma",razlika);
    }
    else if(idealna-trenutna<-3){
    	razlika=trenutna-idealna;
    printf("Potrebno je da smrsate %g kilograma",razlika);
    }
  
    
	return 0;
}
