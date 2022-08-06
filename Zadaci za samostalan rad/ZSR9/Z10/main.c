/*#10 Svaka registracijska oznaka vozila u BiH se sastoji od devet znakova (pet brojeva, dva slova i dvije crtice) u sljedećoj formi X00-X-000, gdje je X neko od velikih štampanih slova: A, E, J, K, M, O, T, a ostalo su brojevi iz skupa [0,9]. Napisati funkciju 
int generisi_tablice(const char *prethodna, char *nova)
koja prvo provjerava da li string prethodna predstavlja korektan format tablice. Ukoliko format nije korektan, funkcija treba vratiti -1 i završiti sa radom. U suprotnom, funkcija računa sljedeću registracijsku oznaku i upisuje vrijednost u string nova, te vraća vrijednost 1. 
Radi jednostavnosti pretpostavit ćemo da se uvijek generiše oznaka koja je naredna po poretku oznaka. Poredak registracijskih oznaka je određen prvo po leksikografskom poretku, a zatim se brojevi povećavaju po prirodnom poretku. Tako sljedeće tri registracijske oznake čine pravilan poredak:
E99-M-999
E00-O-000
E00-O-001
U slučaju da su sve registracije već generisane, odnosno string prethodna označava posljednju tablicu u poretku, funkcija treba vratiti vrijednost 0 i završiti sa radom.
*/
#include <stdio.h>
#include <string.h>
 
int generisi_tablice (const char *prethodna, char *nova)
{
    int i;
 
    for(i=0; i<9; i++) {
        if(i==0 || i==4) {
            if(prethodna[i]=='A' || prethodna[i]=='E' || prethodna[i]=='J' || prethodna[i]=='K' || prethodna[i]=='M' || prethodna[i]=='O' || prethodna[i]=='T') {
                *nova=prethodna[i];
            }else return -1;
        } else if((i>=1 && i<=2) || (i>=6 && i<=8)) {
            if(prethodna[i]>='0' && prethodna[i]<='9') {
                *nova=prethodna[i];
            } else return -1;
        } else if(i==3 || i==5) {
            if(prethodna[i]=='-') {
                *nova=prethodna[i];
            } else return -1;
        } else {
            return -1;
        }
        nova++;
    }
    *nova='\0';
    while(i!=0) {
        nova--;
        i--;
        if(i==3 || i==5) continue;
        else if(i==0 || i==4) {
            if(*nova=='A') {
                *nova='E';
                break;
            } else if(*nova=='E') {
                *nova='J';
                break;
            } else if(*nova=='J') {
                *nova='K';
                break;
            } else if(*nova=='K') {
                *nova='M';
                break;
            } else if(*nova=='M') {
                *nova='O';
                break;
            } else if(*nova=='O') {
                *nova='T';
                break;
            } else if(*nova=='T') {
                *nova='A';
                continue;
            }
        } else if((i>=1 && i<=2) || (i>=6 && i<=8)) {
            *nova+=1;
            if(*nova>='0' && *nova<='9') break;
            else {
                *nova='0';
                continue;
            }
        }
    }
    return 1;
}
 
int main()
{
    char tablica[15] = "A00!A-000";
    char nova[15];
    printf("%d ",generisi_tablice (tablica, nova));
    printf("%s", nova);
    return 0;
}