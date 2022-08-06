#include <stdio.h>

int main() {
	int c=0,b=0,v=0,s=0,p=0,ukupno=0,max=0;
	double postotak;
	char boja;
	printf("Unesite vozila: ");
	do{
	scanf("%c",&boja);
	if(boja=='c' || boja=='C')
	c++;
	else if(boja=='b' || boja=='B')
	b++;
	else if(boja=='v' || boja=='V')
	v++;
	else if(boja=='s' || boja=='S')
	s++;
	else if(boja=='p' || boja=='P')
	p++;
	if(boja!='C' && boja!='c' && boja!='b' && boja!='B' && boja!='v' && boja!='V' && boja!='s' && boja!='S' 
	&& boja!='p' && boja!='P' && boja!='K' && boja!='k')
	printf("Neispravan unos\n");
	if(boja=='K' || boja=='k')
	break;
	}while(boja!='K');
	ukupno=c+b+v+s+p;
	//svi slucajevi kad je max=c,prioritet, c veci ili jednak
    if(s>=v && s>=p && s>c && s>b)
	max=s;
    else if(b>c && b==s && b>v && b>p)
	max=b;
	else if(b>c && b>s && b==v && b>p)
	max=b;
	else if(b>c && b>s && b>v && b==p)
	max=b;
	else if(s==b && c<s && s>v && s>p)
	max=b;
	else if(s>b && c<s && s==v && s>p)
	max=s;
	else if(s>b && c<s && s>v && s==p)
	max=s;
	else if(v==b && v>s && c<v && v>p)
	max=b;
	else if(v>b && v==s && c<v && v>p)
	max=s;
	else if(v>b && v>s && c<v && v==p)
	max=v;
	else if(p==b && p>s && p>v && c<p)
	max=b;
	else if(p>b && p==s && p>v && c<p)
	max=s;
	else if(p>b && p>s && p==v && c<p)
	max=v;
	else if(b>c && b==s && b==v && b==p)
	max=b;
	else if(v==b && v==s && c<v && v==p)
	max=b;
	else if(v>b && v==s && c==v && v==p)
	max=s;
	else if(p==b && p==s && p==v && c<p)
	max=b;
	else if(b>c && b>s && b>v && b>p)
	max=b;
	else if(s>b && c<s && s>v && s>p)
	max=s;
	else if(v>b && v>s && c<v && v>p)
	max=v;
	else if(p>b && p>s && p>v && c<p)
	max=p;
	else if(c>=b && c>=s && c>=v && c>=p)
	max=c;
	else if(b>=c && b>=s && b>=v && b>=p)
	max=c;
	else if(s>=c && s>=b && s>=v && s>=p)
	max=c;
	else if(v>=c && v>=b && v>=s && v>=p)
	max=c;
	else if(p>=c && p>=b && p>=s && p>=v)
	max=c;
	
	


	
	if(ukupno==0)
	postotak=0;
	else
	postotak=(double)max*100/ukupno;
	printf("Ukupno evidentirano %d vozila.\n",ukupno);
	if(max==c)
	printf("Najpopularnija boja je crna (%.2f%%).",postotak);
	else if(max==v)
	printf("Najpopularnija boja je crvena (%.2f%%).",postotak);
	else if(max==b)
	printf("Najpopularnija boja je bijela (%.2f%%).",postotak);
	else if(max==s)
	printf("Najpopularnija boja je siva (%.2f%%).",postotak);
	else if(max==p)
	printf("Najpopularnija boja je plava (%.2f%%).",postotak);
	return 0;
}
