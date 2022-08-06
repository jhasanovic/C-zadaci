#include <stdio.h>
#include <math.h>

int main() {
    
	double a,b,h,suma,x,rez,temp;
	int n,koraci,i,brojac=0;
	printf("Unesite prvu tacku intervala: ");
	scanf("%lf",&a);
	if(a<1){
		printf("Nedozvoljena vrijednost! ");
		return 1;
	}
	printf("Unesite drugu tacku intervala: ");
	scanf("%lf",&b);
	if(b<a){
	printf("Nedozvoljena vrijednost! ");
	return 1;
    }
    else if(fabs(a-b)<.0001 || b-a>100){
    printf("Neispravan interval!");
    return 1;
    }
    
    else{
    printf("Unesite eksponent: ");
    scanf("%d",&n);
    if(n<-10 || n>10){
    	printf("Neispravan eksponent! ");
    	return 1;
    }
    printf("Unesite korak diskretizacije: ");
    scanf("%lf",&h);
    	
    printf("Korak    x            y = f(x)\n");
    printf("----------------------------------\n");
    
    temp=a;
    koraci=(b-a)/h;
    suma=0;
    for(i=1;i<=koraci;i++){
       x=a;
       brojac=0;
       rez=1;
       /*pow petlja*/
       while(n>0){
           rez*=x;
           n--;
           brojac++;/*n se cuva u varijabli brojac*/
       }
       suma+=rez; 
       n=brojac;
       a+=h;
    
    	
    	if(i<=4 && i!=koraci){
    	printf("%5d. %8f %15.5f\n",i,x,rez);
    	}
    	else if(i<=4 && i==koraci){
    	printf("%5d. %8f %15.5f\n",i,x,rez);
    	printf("\n");
    	}
    	else if(koraci>4 && i==5)
    	printf("(...)\n");
    	else if(i==koraci)
    	printf("%5d. %8f %15.5f\n",i,x,rez);
    
    }
    suma/=(1/h);
    printf("----------------------------------\n");
    printf("P(x^%d)[%g,%g]= %f (dx=%g)",n,temp,b,suma,h);
    }
	return 0;
}
