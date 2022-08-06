#include <stdio.h>
#include <string.h>
struct Student {
    char ime[20];
    char prezime[20];
};
 
struct Ocjena {
    struct Student s;
    char predmet[100];
    int ocjena;
};
 
struct Predmet {
    int id;
    char naziv[100];
    float prosjek;
};
int uporedi(struct Student s1, struct Student s2)
{
    if(!(strcmp(s1.ime,s2.ime) || strcmp(s1.prezime,s2.prezime))) return 1;
    return 0;
}
struct Student top_student(struct Ocjena *niz,int vel)
{
    struct Student maxStudent;
    struct Student tmp;
    double prosjek=0;
    double maxProsjek=0;
    double suma=0;
    int brojOcjena=0;
    int i,j;
    for(i=0; i<vel; i++) {
        suma=0;
        prosjek=0;
        brojOcjena=0;
        tmp=niz[i].s;
        for(j=0; j<vel; j++) {
            if(uporedi(tmp,niz[j].s)) {
                suma+=niz[j].ocjena;
                brojOcjena++;
            }
        }
        prosjek=suma/brojOcjena;
        if(prosjek>maxProsjek) {
            maxStudent=tmp;
            maxProsjek=prosjek;
        }
        if(prosjek==maxProsjek) {
            if(strcmp(maxStudent.prezime,tmp.prezime)>0) maxStudent=tmp;
        }
    }
    return maxStudent;
}
 
int ucitaj_ocjene(struct Ocjena *niz,int vel)
{
    FILE* ocjene = fopen("ocjene.dat","rb");
    if(!ocjene) return 0;
    int i=0;
    int a;
    for(i=0; i<vel; i++) {
        a=fread(niz,sizeof(*niz),1,ocjene);
        if(a==0) break;
        niz++;
    }
    fclose(ocjene);
    return i;
}
int ucitaj_predmete(struct Predmet *niz,int val)
{
    FILE *predmeti=fopen("predmeti.txt","r");
    if(!predmeti) return 0;
    int i=0;
    while(i<val && fscanf(predmeti,"%d,%[^,],%f\n",&niz[i].id,niz[i].naziv,&niz[i].prosjek)==3) {
        i++;
    }
 
    fclose(predmeti);
    return i;
}
struct Predmet max_prosjek(struct Predmet *niz,int vel)
{
    int i;
    double maxProsjek=0;
    struct Predmet maxPredmet;
    for(i=0; i<vel; i++) {
        if(niz[i].prosjek>maxProsjek) {
            maxProsjek=niz[i].prosjek;
            maxPredmet=niz[i];
        }
    }
    return maxPredmet;
}
int predmet_studenti(struct Predmet *predmeti,int vel1,struct Ocjena *ocjene,int vel2)
{
    struct Predmet maxPredmet;
    maxPredmet = max_prosjek(predmeti,vel1);
    int i;
    for(i=0; i<vel2; i++) {
        if(strcmp(maxPredmet.naziv,ocjene[i].predmet)==0) {
            printf("%s %s %d\n",ocjene[i].s.ime,ocjene[i].s.prezime,ocjene[i].ocjena);
        }
    }
    return i;
}
int zapisi_predmete(struct Predmet *niz,int vel)
{
    int i=0;
    FILE* unos=fopen("predmeti.txt","w");
    if(!unos) return 0;
    for(i=0; i<vel; i++) {
        fprintf(unos,"%d,%s,%.2f\n",niz[i].id,niz[i].naziv,niz[i].prosjek);
       
    }
    fclose(unos);
    return i;
}
 
int main()
{
    struct Predmet niz[100];
    int vel, i;
    FILE* provjera = fopen("predmeti.txt", "w");
    fprintf(provjera, "1,Osnove rac,7.51\n2,Inz fiz 1,7.90\n3,Linearna algebra,8.00\n4,Inz mat 1,6.80");
    fclose(provjera);
 
    vel = ucitaj_predmete(niz, 100);
 
    for (i=0; i<vel; i++) {
        printf("%d '%s' - %g\n", niz[i].id, niz[i].naziv, niz[i].prosjek);
    }
    return 0;
}