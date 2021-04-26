// fiind date greutatile si valoarile pentru n obiecte, umpleti un rucsac de capacitate W
// astfel incat sa maximizati valoare obiectelor din rucsac.
// Avand doua tablouri val[0...n-1] si wt[0...n-1] care reprezinta valorile si greutatile obiectelor,
// si avand un rucsac de capacitate W, gasiti subsetul de valoare maxima din val[] astfel incat suma
// greutatilor obiectelor sa nu depaseasca W.
#include<stdio.h> 
  

int max(int a, int b) { return (a > b)? a : b; } 
  
// returneaza valoare maxima a obiectelor ce pot fi incarcate in rucsacul cu capacitatea W 
int knapSack(int W, int wt[], int val[], int n) { 
   // cazul de baza
   if (n == 0 || W == 0) 
       return 0; 
  
   // daca greutatea obiectului n depaseste capacitatea W, acest obiect nu poate fi inclus

   if (wt[n-1] > W) 
       return knapSack(W, wt, val, n-1); 
  
   // Returneaza maximul dintre
   // (1) obiectul n este inclus
   // (2) obiectul n nu este inclus
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1)  ); 
} 
  
// program driver
int main() { 
//    int val[] = {60, 100, 120}; 
//    int wt[] = {10, 20, 30}; 
    int wt[] = {1,10,5,1,7,5,1}; 
    int val[] = {10,15,20,2,30,10,30}; 
    int  W = 20; 
    int n = sizeof(val)/sizeof(val[0]); 
    printf("%d \n", knapSack(W, wt, val, n)); 
    return 0; 
} 