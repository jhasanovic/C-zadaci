#include <stdio.h>

int main() 
{
	int i,j,n,x,y;
	do{
	printf("Unesite dimenziju: ");
	scanf("%d",&n);
	if(n==-1){
		printf("Zavrsio!");
		return 0;
	}
	
	printf("Unesite (x y): ");
    scanf("%d %d",&x,&y);
	
	if(x<-2*n-1 || x>2*n+1 || y>n+1 || y<-n-1)
	{
	printf("Koordinate izvan opsega!");
	return 0;
	}
	else
	{
	for(i=n+1;i>=-n-1;i--)
	{
		for(j=-2*n-1;j<2*n;j++)
		{
		    if(i==0 && j==-1)
		    printf("+");
		    if(i==0 && j==2*n-1)
		    printf(">");
		    if(i==0 && j==-2*n-1)
		    printf("<");
		    if(j==0 && i==n+1)
		    printf("^");
		    if(j==0 && i==-n-1)
		    printf("v");
		    if(j==0 && i!=n+1 && i!=0 && i!=-n-1)
		    printf("|");
		    if(i==0 && j!=-2*n-2  && j!=2*n && j!=2*n-1)
		    printf("-");
		    else if(j==x && i==y)
		    printf("x");
		    else
		    printf(" ");
			
		}
		printf("\n");
	}

	}
	
	}while(n!=-1);
	return 0;
}

