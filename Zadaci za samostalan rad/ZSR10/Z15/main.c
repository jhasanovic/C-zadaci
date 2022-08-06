/*#15 Potrebno je napisati funkciju cenzura koja u primljenom tekstu cenzuriše riječi 
nabrojane u drugom stringu.Funkcija prima dva parametra tipa char*.Svaku zabranjenu riječ 
treba zamijeniti sa po tri zvjezdice (asterisk) bez obzira na originalnu dužinu te riječi. 
Funkcija treba biti tipa void što znači da se mijenja string primljen kao prvi parametar. 
Napravite i main funkciju u kojoj se unose dva tražena stringa.Riječ definisana kao niz 
velikih i malih slova. U drugom parametru samo velika i mala slova i razmaci. Pretpostavite 
da je string koji je prvi parametar deklarisan tako da je dovoljno velik da primi sve 
dodatne zvjezdice (u slučaju da su zamijenjene riječi kraće od tri slova).
Ne praviti razliku između velikih i malih slova. Znakovi koji nisu velika ili mala slova 
trebaju ostati na istoj poziciji u stringu (relativno u odnosu na ostale znakove).
Nije dozvoljeno kreiranje pomoćnog stringa u funkciji.*/

void cenzura(char *s1,char *s2){
 
 
char *pom1=s1;
char *pom2=s2;
 
//radi se mnogo slicno onome gdje se salje matrica slova, gdje sa i mjenjamo slova
while(*pom2!='\0'){
 
 
    while(*pom2==' ')pom2++;//preskacem spacebarove
    if(*pom2=='\0')break;
    char *q1=pom2;
    while(*pom2!=' ' && *pom2!='\0')pom2++;
 
    char *q2=pom2;//ogranicio sam rijec sa q1 i q2
 
    while(1){
 
        int indeks=PronadjiOpseg(s1,q1,q2);//trazi ako se nalazi strign omedjen sa q1 i q2 unutar s1
        //jer u ovom zadatku se ne smiju koristit pomocni stringovi
 
        if(indeks==-1)break;//ako nema breka while
        Izbaci(s1+indeks,q2-q1);//izbaci pojavljivanje cenzurisane rijeci
        Ubaci(s1+indeks,"***");//i onda ubaci *** znaka tako se trazi u zadatku
 
    }
 
}
}
 
