/*ALGORITMI SA STRINGOVIMA*/

//1)zamjena cifre stringom

void zamijeni_string_ubaci(char* s, const char* pretraga, const char* zamjena, int pomak)
{
	char* pozicija = strstr(s, pretraga);
	while (pozicija) {
		char* kraj = pozicija;
		while (*kraj != '\0') kraj++;
		while (kraj > pozicija) {
			*(kraj+pomak) = *kraj;
			kraj--;
		}
		strcpy(pozicija, zamjena);
		pozicija = strstr(s, pretraga);
	}
}
void zamijeni_string_izbaci(char* s, const char* pretraga, const char* zamjena, int pomak)
{
	char* pozicija = strstr(s, pretraga);
	while (pozicija) {
		char* tmp = pozicija;
		while (*tmp != '\0') {
			*tmp = *(tmp+pomak);
			tmp++;
		}
		strcpy(pozicija, zamjena);
		pozicija = strstr(s, pretraga);
	}
}
void zamijeni_string(char* s, const char* pretraga, const char* zamjena)
{
	int pomak = strlen(zamjena) - strlen(pretraga);
	if (pomak > 0)
		zamijeni_string_ubaci(s, pretraga, zamjena, pomak);
	else
		zamijeni_string_izbaci(s, pretraga, zamjena, -pomak);
}
void zamijeni1(char* s)
{
	zamijeni_string(s, "1", "jedan");
}

//2)duzina stringa
int duzina(char* s)
{
	int duz = 0;
	while (*s++) duz++;
	return duz;
}

//3)brojanje karaktera u stringu
int prebroji(const char* s, char znak)
{
	int brojac = 0, tmp;
	if (znak >= 'A' && znak <= 'Z')
		znak += 'a' - 'A';
	while (*s != '\0') {
		tmp = *s;
		if (tmp >= 'A' && tmp <= 'Z')
			tmp += 'a' - 'A';
		if (tmp == znak) brojac++;
		s++;
	}
	return brojac;
}

//4)leksikografsko poredjenje
int uporedi(const char* s1, const char* s2)
{
	while (*s1 != '\0' && *s2 != '\0') {
		if (*s1 < *s2) return -1;
		if (*s1 > *s2) return 1;
		s1++;
		s2++;
	}
	if (*s1 != '\0') return 1;
	if (*s2 != '\0') return -1;
	return 0;
}

//5)spajanje stringova
char* spoji(char* s1, const char* s2)
{
	char* ret = s1;
	while (*s1++);
	s1--;
	while (*s1++ = *s2++);
	return ret;
}

//6)da li je s2 podstring stringa 1
const char* podstring(const char* s1, const char* s2)
{
	while (*s1 != '\0') {
		const char* p = s1;
		const char* q = s2;
		while (*p++ == *q++)
			if (*q == '\0') return s1;
		s1++;
	}
	return NULL;

//7)trazenje broja u stringu

int trazi_broj(const char* s, int broj) {
char sbroj[12];
char* sb = sbroj;
int tmp = broj;

/* predznak */
if (broj < 0) {
broj = -broj;
*sb++ = '-';
}
/* prebrojavamo cifre */
do {
i++;
tmp /= 10;
} while (tmp != 0);
*sb-- = '\0';

do {
*sb-- = broj % 10 + '0';
broj /= 10;
} while (broj != 0);

if (podstring(s, sbroj)) return 1;
 return 0;
}

//8)Ekstrakcija broja iz stringa
int trazi_broj(const char* s, int broj) {
 int tmp, predznak = 1;
 while (*s != '\0') {
 if (*s == '-') predznak = -1;
 else if (*s >= '0' && *s <='9') {
 tmp = 0;
 while (*s >= '0' && *s <= '9') {
tmp = tmp * 10 + *s - '0';
s++;
}
if (predznak * tmp == broj) return 1;
}
 else predznak = 1;
s++;
}
return 0;
}

//9)provjerava da li se rijec s2 nalazi u s1
const char* nadji_rijec(const char* s1, const char* s2) {
const char* poc = s1;
while (*s1 != '\0') {
const char* p = s1;
const char* q = s2;
while (*p++ == *q++)
if (*q == '\0' && (s1 == poc || *(s1-1) == ' ') && (*p == ' ' || *p == '\0')) return s1;
 s1++;
 }
return NULL;
}

//10)izbacivanje dijela stringa
char* p = s1;
while (*p != '\0') {
if (uslov) {
char *q = p, *r = p+5;
while (*q++ = *r++);
} else p++;
}

//11)izbacivanje n-te rijeci(rijeci razdvojene razmacima)
void izbaci_rijec(char* s, int n) {
 int razmak=1, broj_rijeci=0;
 char* pocetak;
 while (*s != '\0') {
 if (*s == ' ')
 razmak=1;
 else if (razmak == 1) {
 razmak=0;
 broj_rijeci++;
 if (broj_rijeci==n) pocetak=s;
 if (broj_rijeci==n+1) {
 while (*pocetak++ = *s++);
 return;
 }
 }
 s++;
 }
 if (broj_rijeci == n) *pocetak = '\0';
}

//12)izbacivanje n-te rijeci(rijec je neprekinut niz slova)
void izbaci_rijec2(char* s, int n) {
int neslovo=1, broj_rijeci=0;
char* pocetak;
while (*s != '\0') {
if ( !(*s >= 'A' && *s <= 'Z' ||
*s >= 'a' && *s <= 'z') )
neslovo=1;
else if (neslovo == 1) {
neslovo=0;
broj_rijeci++;
if (broj_rijeci==n) pocetak=s;
if (broj_rijeci==n+1) {
while (*pocetak++ = *s++);
return;
}
}
s++;
}
if (broj_rijeci == n) *pocetak = '\0';
}