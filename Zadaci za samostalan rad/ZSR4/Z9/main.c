/*#9 Prepravite prethodni zadatak tako da iscrtava hipotetsko triangularno BGA kolo. Trougao se može nalaziti 
u bilo kojem uglu, ali radi prakse se preporučuje da se pokuša uraditi za sve uglove; kasnije će biti lakše 
ovladati npr. matricama. Osim toga izvodi su zamijenjeni tako da se kreće od < a ne >. */

#include <stdio.h>

int main(){

int i,j,n;
printf("Unesite N, dimenziju BGA kola: ");
scanf("%d",&n);

for(i=0;i<=n+1;i++){
for(j=0;j<=2*n+4;j++){
if((i==0 && j==0) || (i==0 && j==2*n+4) || (i==n+1 && j==0) || (i==n+1 && j==2*n+4))
printf("+");
else if(j==0)
printf("|");
else if(j==2*n+4 && i%2==1)
printf(">");
else if(j==2*n+4 && i%2==0)
printf("<");
else if(i==0 || i==n+1)
printf("-");
else if(j==1 || j==2*n+3 || j%2==0 || i>j)
printf(" ");
else //if(j>2 && j<2*n+2 && i<=j){
    //if(i%2==1 && (i+j)%2==0)
    printf("o");
    //else if(i%2==0 && (i+j)%2==1)
    //printf("o");
//}
//else
//printf(" ");

}
printf("\n");
}

return 0;
}

