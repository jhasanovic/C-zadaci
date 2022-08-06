/*ALGORITMI POKAZIVACI*/
//1)
void ispisi_obrnuto (int *pok, int vel) {
int i;
int *kraj = pok + vel; /* iza kraja */
for (i = 0; i < vel; ++i) {
/* prvo -- jer je pokazivao iza kraja! */
kraj--;
printf ("%i ", *kraj);
}
}

//2)svaki clan niza zaokruziti na dvije decimale
//kod pozitivni se dodaje 0.5, kod negativnih oduzima
double *zaokruzi (double *niz, int vel) {
double *p = niz;
while (p < niz + vel) {
*p *= 100;
/* odsijecanje decimala: */
*p = (int)(*p + 0.5);
*p++ /= 100;
}
/* vratimo pokazivac na pocetak */
return niz;
}
