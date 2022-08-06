/*#13 (Završni ispit 2015/16; Zadaća 4, 2016/17) Napisati funkciju sa prototipom: char* izbaci_najcescu(char* s)
Funkcija treba iz primljenog stringa koji predstavlja neki tekst izbaciti riječ koja se u tekstu ponavlja najviše
puta. Treba izbaciti sva ponavljanja te riječi u stringu. Riječ se definiše kao niz velikih i malih slova. Tako npr.
tekst "auto-stop" posmatramo kao dvije riječi jer se u sredini nalazi znak minus koji nije slovo. Funkcija ne treba
praviti razliku između velikih i malih slova. Funkcija treba vratiti pokazivač na početak primljenog stringa radi
lakšeg lančanog pozivanja. Ukoliko se u tekstu nalazi više riječi koje se ponavljaju isti broj puta, funkcija treba
izbaciti onu od najčešćih riječi koja je najbliža početku stringa. Prilikom izbacivanja riječi ne treba izbacivati
okolne razmake i ostale znakove. Ukoliko primljeni string ne sadrži niti jednu riječ funkcija ne treba uraditi ništa.
Pri rješavanju zadatka nije dozvoljeno koristiti funkcije iz biblioteka string.h , stdlib.h kao ni funkcije sprintf i
sscanf iz biblioteke stdio.h.*/
#include <stdio.h>

char* izbaci_najcescu(char* s)
{
    char *pocRijeci, *p, *krajRijeci, *pom, *pompr, *adr;
    if (!imaLiRijeci(s)) return s;
    p = s;
    /*Ovim dijelom koda sam pronasao najcescu rijec i stavio pokazivac na njeno prvo slovo i znak poslije njenog zadnjeg slova*/
    pocRijeci = dajNajcescuRijec(s);
    pom = pocRijeci;
    while (daLiJeSlovo(*pom))
        pom++;
    krajRijeci = pom;
    s = krajRijeci;
    /*Ako je rijec zadnja ovaj while se sigurno nikad nece izvrsiti jer ce biti *s = '\0' */
     while (*s != '\0')
     {
         /*Uvijek postavljam pokazivac pompr na poc rijeci i pomijeram ga kako bi mogao porediti najcescu rijec sa ostalim rijecima*/
         pompr = pocRijeci;
         while (!daLiJeSlovo(*s))
         {
             if (*s == '\0') break;
             s++;
         }
         if (*s == '\0') break;
         /* Kada dodjem do rijeci trebam znati gdje je njen pocetak ( a to ce mi omoguciti pokazivac pom )
            jer u slucaju da je ista rijec kada je izbacim samo cu vratiti s na pom i tako cu osigurati
            da se s vrati za onoliko mjesta koliko je rijec duga */
         pom = s;
         /* Pomijeram pompr (pomocni pokazivac na pocetak rijeci) i s sve dok su rijeci iste*/
         while (daLiJeSlovo(*s) && (*pompr == *s || *pompr == *s +32 || *pompr == *s - 32))
         {
             pompr++;
             s++;
         }
         /* Sada testiram sve moguce vrste prekida kada do njih dodje, a mora doci ako se desava ova petlja */
         /* case 1: ako je *pompr = neki znak i *s = neko slovo znaci da rijeci nisu iste i s treba pomijerat sve dok je na toj rijeci
            primjer : jaStuK +- jASTukLTI*/
         if (!daLiJeSlovo(*pompr) && daLiJeSlovo(*s))
         {
             while (daLiJeSlovo(*s))
                s++;
             continue;
         }
         /* case 2: ako *pompr = slovo ALI *s = slovo i pritom slova nisu ista desava se isto sto i gore tako da je ovo dupliranje koda
         primjer : jasTUK +- jasLLk  */
         else if (daLiJeSlovo(*pompr) && daLiJeSlovo(*s))
         {
             while (daLiJeSlovo(*s))
                s++;
             continue;
         }
         /*Ako je *pompr = slovo ali *s = neki znak znaci da to nije ta rijec i treba o5 krenuti od pocetka petlje
         primjer : jAStuk +- ja\lt */
         else if (daLiJeSlovo(*pompr) && !daLiJeSlovo(*s))
            continue;
        /* Ako dodje do ovog slucaja znaci da su rijeci iste i da su oba pokazivaca dosla do znaka i da drugu rijec treba izbaciti */
        else
        {
            /* Posto cu pom koristiti da cuvam adresu na koju cu vratiti s kada izbacim rijec treba mi pomocni pokazivac
                (u ovom slucaju adr ) koji ce da se "proseta" kroz petlju */
            adr = pom;
            while (*s != '\0')
            {
                *adr = *s;
                adr++;
                s++;
            }
            while (*adr != '\0')
                *adr++ = '\0';
            adr = '\0';
            s = pom;
        }
     }
     /* Ako je bila jedna rijec u stringu, while gore se nece desiti, ako ih je bilo vise istih, sve "kopije" su obrisane i ostala je jedna.
        Sada treba tu jednu izbaciti a pocRijeci pokazuje na nju */
    if (*krajRijeci == '\0')
        while (*pocRijeci != '\0')
        *pocRijeci++ = '\0';
    else
    {
        while (*krajRijeci != '\0')
        {
            *pocRijeci = *krajRijeci;
            pocRijeci++;
            krajRijeci++;
        }
        *krajRijeci = '\0';
        while (*pocRijeci != '\0')
            *pocRijeci++ = '\0';
    }
    return p;
}

int main()
{
	return 0;
}
