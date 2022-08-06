#include <stdio.h>
#include <stdlib.h>
 
void unesi(char *string, int vel)
{
    int i=0;
    do{
        *string++=getchar();
        i++;
        if(i==vel) break;
    }while(*(string-1)!='\n');
    *(string-1)='\0';
}
 
void funkcija(char *A,char *B, int duzina)
{
    int i=0,j=0,brojac=0,flag=0,br;
    while(*(A+i)!='\0')
    {
        if(*(A+i)==*(B+j))
       {
           while(*(B+j)==*(A+i))
            {brojac++;
             i++;
            j++;}
       }
       else if(*(B+j)=='\0')  {j=0; i++;}
       else if(brojac>=duzina) {flag=1; break;}
       else {j++; brojac=0;}
    }
    if(flag==1) printf("Imaju zajednicki string duzine %d",brojac);
    else printf("Nemaju zajednicki string >=duzina.");
 
}
 
int main()
{
    char A[100],B[100];
    int n;
    printf("Unesi prvi string: ");
    unesi(A,100);
    printf("Unesi drugi string: ");
    unesi(B,100);
    printf("Unesi duzinu podstringa: ");
    scanf("%d", &n);
    funkcija(A,B,n);
    return 0;
}
