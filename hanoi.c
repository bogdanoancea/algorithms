/* Problema Turnurilor din Hanoi - Metoda Divide et Impera
Se dau 3 tije A,B,C pe tija A aflandu-se n discuri de dimensiuni
diferite, aranjate de la baza spre varf de la cel mai mare disc la cel mai
mic. Stiind ca se muta cate un disc la un moment dat si ca nu se
poate muta un disc mai mare peste un disc mai mic, sa se mute toate
cele n discuri de pe tija A pe tija B utilizand drept ajutor tija C.*/

#include<stdio.h>

void hanoi(int nr_discuri,int start,int stop,int ajutor)
{
	if(nr_discuri == 1) {
		printf("Muta un disc de pe tija %d pe tija %d\n",start,stop);
		return;
	}
	else {
	  hanoi(nr_discuri-1,start,ajutor,stop);
	  printf("Muta un disc de pe tija %d pe tija %d\n",start,stop);
	  hanoi(nr_discuri-1,ajutor,stop,start);
	}
}

int main()
 {
	 int n;
	 printf("Dati nr de discuri:");
	 scanf("%d",&n);
	 hanoi(n,1,3,2);
     return 0;
 }
