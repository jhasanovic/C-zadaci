/*#7 Napisati program koji će ispisati sve brojeve do n koji nisu djeljivi sa brojevima 
2, 3 i 13, svaki u novom redu. Broj n se unosi sa tastature te mora biti prirodan; 
ukoliko nije, unos se ponavlja. U programu se ne smije koristiti „else“ i „else if“ dio
„if-else“ strukture.*/

#include <stdio.h>

int main() {
	int i,n;
	do{
	printf("Unesite n: ");
	scanf("%d",&n);
	if(n<=0)
	printf("Broj nije prirodan!\n");
	}while(n<=0);
	
		for(i=1;i<=n;i++){
		if(i%2!=0 && i%3!=0 && i%13!=0)
		printf("%d\n",i);
		}
	return 0;
}
