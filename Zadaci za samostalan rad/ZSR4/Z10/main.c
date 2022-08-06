/*#10 (Zadaća 1, 2014/15) Fibonaccijev niz brojeva je niz u kojem nakon dvije početne vrijedosti (jedinice),
svaki sljedeći broj je jednak zbiru dva prethodnika. Napisati program koji će ispisati prvih n Fibonaccijevih 
brojeva, gdje se n unosi sa tastature. */

#include <stdio.h>
int main()
{
    int i, n, prvi = 0, drugi = 1, sljedeci;
    printf("Unesite n: ");
    scanf("%d", &n);
    if(n<0){
    printf("Neispravan unos");
    return 0;
    }
    printf("Prvih %d Fibonaccijevih brojeva: ",n);
    for (i = 1; i <= n; ++i)
    {
        printf("%d ", drugi);
        sljedeci = prvi + drugi;
        prvi = drugi;
        drugi = sljedeci;
    }
    return 0;
}
