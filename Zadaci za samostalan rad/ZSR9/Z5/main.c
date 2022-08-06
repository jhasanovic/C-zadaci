/*#5 Napisati funkciju void ispisi_unazad (const char *str) koja ispisuje proslijeđeni string u obrnutom 
redoslijedu. Funkcija ne smije koristiti nikakve pomoćne funkcije niti petlje, nego njena implementacija 
treba biti rekurzivna. */
#include <stdio.h>
  
void ispisi_unazad(const char *str) 
{ 
   if (*str!='\0') 
   { 
       ispisi_unazad(str+1); 
       printf("%c", *str); 
   } 
} 
  
int main() 
{ 
   char a[] = "gnirts itunrbo"; 
   ispisi_unazad(a); 
   return 0; 
} 