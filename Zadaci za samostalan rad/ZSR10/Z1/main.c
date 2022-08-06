/*#1 U predavanjima je data funkcija const char* podstring ( const char *str, const char *trazi)
koja traži tekst trazi unutar proslijeđenog stringa str . Funkcija treba da vrati pokazivač na poziciju u string str
gdje se nalazi podstring. Ukoliko ima više takvih stringova funkcija treba vratiti indeks koji predstavlja početak
prvog stringa, a ko se podstring ne nalazi u stringu treba vratiti nul-pokazivač.Napisati novu funkciju
pronadji_posljednji koja slično funkciji podstring pronalazi tekst unutar stringa ali ovaj put vraća indeks
posljednjeg pojavljivanja.*/
#include <stdio.h>

int pronadji_posljednji(const char* s1, const char* s2)
{
	int flag=0,i;
	const char* trazeni;
	const char* pocetak=s1;
	while (*s1 != '\0') {
		const char* p = s1;
		const char* q = s2;
		while (*p++ == *q++)
			if (*q == '\0') { //s1 pokazuje na pocetak podstringa
				trazeni=s1;
				flag++;
				i=trazeni-pocetak;
			}
		s1++;
	}
	if(flag!=0)
		return i;
	else
		return -1;
}
int main()
{
	const char *n = "Danas je divan dan!";
	printf ("%d", pronadji_posljednji(n, "an"));
	return 0;
}
