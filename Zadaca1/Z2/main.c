#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	
	double p1,p2,q1,q2,r1,r2,d,a,d_po_xosi,d_po_yosi,h,x,y,rx,ry,x1,x2,y1,y2;
	do{
	printf("Unesite koordinate centra kruznice A: ");
	scanf("%lf %lf",&p1,&q1);
	printf("Unesite poluprecnik kruznice A: ");
	scanf("%lf",&r1);
	printf("Unesite koordinate centra kruznice B: ");
	scanf("%lf %lf",&p2,&q2);
	printf("Unesite poluprecnik kruznice B: ");
	scanf("%lf",&r2);
	if(r1<0 || r2<0)
	printf("Neispravni ulazni podaci.\n");
	}while(r1<0 || r2<0);/*Ogranicenje na parametre*/
	
	/*d je udaljenost izmedju centara kruznica*/
	d=sqrt((p2-p1)*(p2-p1)+(q2-q1)*(q2-q1));
	
	if(fabs(p1-p2)<EPSILON && fabs(q1-q2)<EPSILON && fabs(r1-r2)<EPSILON)
	printf("Kruznice su identicne.");
	
	else if(d<fabs(r1-r2))
	printf("Jedna kruznica je sadrzana u drugoj.");
	
	/*slucajeve sijeku se i dodiruju se pod jedan uvjet*/
	else if(d-(r1+r2)<EPSILON){
	{
	d_po_xosi=p2-p1;
	d_po_yosi=q2-q1;
	/*a je udaljenost od centra kruznice A do prave koja prolazi kroz tacke presjeka kruznica*/
	a=(r1*r1-r2*r2+d*d)/(2*d);
	x=p1+((d_po_xosi*a)/d);
	y=q1+((d_po_yosi*a)/d);
	/*h je visina trougla (na stranicu d) sa stranicama d,r1,r2*/
	h=sqrt((r1*r1-a*a)); 
	rx=-d_po_yosi*(h/d);
	ry=d_po_xosi*(h/d);
	
	x1=x+rx;
	y1=y+ry;
	x2=x-rx;
	y2=y-ry;
	}
	
	if(fabs(x1-x2)<EPSILON && fabs(y1-y2)<EPSILON)
	printf("Kruznice se dodiruju u tacki (%.2f,%.2f).",x1,y1);
	
	else
	printf("Kruznice se sijeku u tackama (%.2f,%.2f) i (%.2f,%.2f).",x1,y1,x2,y2);
	}

    else if(d>r1+r2){
	printf("Kruznice se ne sijeku.");
    }
    
	return 0;
}
