#include <stdio.h>
#include <stdlib.h>
struct Grad{
char naziv[30];
int br_stanovnika;
};
 
int ucitaj(struct Grad * gradovi,int n)
{
    FILE *ulaz;
    int i=0;
    ulaz=fopen("gradovi.txt","r");
    if(!ulaz){
        printf("NIJE SE MOGLO UCITATI");
        exit(1);
    }
    char znak;
 
while (fscanf(ulaz,"%30s%d%\n",gradovi[i].naziv,&gradovi[i].br_stanovnika)==2&& i<n)
        i++;
       
        fclose(ulaz);
       
        return i;
 
}
 
void zapisi(struct Grad *gradovi,int n,int x)
{
    FILE *izlaz;
    izlaz=fopen("izlaz.txt","w");
    if(!izlaz){
        printf("NIJE SE MOGLO UCITATI");
        exit(1);
    }
    int i=0;
    for(i=0;i<n;i++)
    {
        if(gradovi[i].br_stanovnika>x)
        fprintf(izlaz,"%-30s\n",gradovi[i].naziv);
    }
    fclose(izlaz);
   
   
   
}
 
void ispis(struct Grad *gradovi,int n,char x)
{
    int i=0;
    for(i=0;i<n;i++){
        if(gradovi[i].naziv[0]==x){
            printf("%-30s\n",gradovi[i].naziv);
            printf("\n");
        }
       
    }
}
int main() {
    struct Grad gradovi[100];
    int br_gradova = ucitaj(gradovi, 100);
    printf("Broj gradova: %d\n", br_gradova);
    if (br_gradova > 0) {
        printf("Prvi grad: %s (%d)\n", gradovi[0].naziv, gradovi[0].br_stanovnika);
    }
    zapisi(gradovi, br_gradova, 100000);
    ispis(gradovi, br_gradova, 'A');
    return 0;
}