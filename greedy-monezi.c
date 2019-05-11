// plata unei sume cu un numar minim de monezi
#include <stdio.h>
#include <stdlib.h>

//coin_value[] - memoreaza valorile monezilor disponibile
//n - numarul total de monezi
//amount  - suma care trebuie platita

void min_coins(int coin_value[], int n, int amount) {
  
  int i;
  for( i=0; i < n; i++ ) 
    while(amount >= coin_value[i])
    {
      //while este necesara deoarece o moneda poate fi utilizata de mia multe ori
      amount = amount - coin_value[i];
      printf("%d  ", coin_value[i]);
    }
  printf("\n");
}

//necesar functiei qsort(), care se gaseste in biblioteca standard
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a ); //descrescator
}


int main() {
  int i, j, n, amount;
  printf( "Suma care trebuie platita: ");
  scanf( "%d",&amount);
  printf( "Numarul de monede: ");
  scanf("%d",&n);
  int coin_value[n]; 
  printf( "Valorile monezilor: ");
  for(i = 0;i< n; i++)//
    scanf("%d",&coin_value[i]);
  qsort(coin_value, n, sizeof(int), cmpfunc); 
  printf( "Monezile cu care platim sunt: \n");
  min_coins(coin_value,n,amount);
  return 0;
} 