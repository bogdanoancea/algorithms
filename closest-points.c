// Program C care calculeaza distanta minima intre doua puncte dintr-un set de puncte

#include <stdio.h> 
#include <float.h> 
#include <stdlib.h> 
#include <math.h> 
  
// Structura care va reprezenta un punct in spatiul bidimensional
struct Point  { 
    int x;
    int y; 
}; 
  
/* Functia care compara doua puncte dupa X, necesara functiei qsort(). 
   Puteti citi documentatia functiei qsort aici: http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ 
*/
int compareX(const void* a, const void* b)  { 
    struct Point *p1 = (struct Point *)a;
    struct Point *p2 = (struct Point *)b;
    return (p1->x - p2->x); 
} 
// Functia care compara doua puncte dupa X, necesara functiei qsort().  
int compareY(const void* a, const void* b) { 
    struct Point *p1 = (struct Point *)a;   
    struct Point *p2 = (struct Point *)b; 
    return (p1->y - p2->y); 
} 
  
// Functia care calculeaza distanta intre doua puncte
float dist(struct Point p1, struct Point p2)  { 
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + 
                 (p1.y - p2.y)*(p1.y - p2.y) ); 
} 
  
// Functia de tip "forta bruta" care calculeza distanta minima intre doua puncte din tabloul P[] de dimensiune n
float bruteForce(struct Point P[], int n)  { 
    float min = FLT_MAX; 
    int i, j;
    for (i = 0; i < n; ++i) 
        for (j = i+1; j < n; ++j) 
            if (dist(P[i], P[j]) < min) 
                min = dist(P[i], P[j]); 
    return min; 
} 
  
// Functie care calculeaza cel mai mic numar dintre 2 numere de tip float
float min(float x, float y)  { 
    return (x < y) ? x : y; 
} 
  

// O functie care calculeaza distanta intre cele mai apropiate puncte 
// dintr-o banda versticala de dimensiunea data strip[]. Toate punctele din strip[]
// sunt sortate dupa y. Ele au ca limita superioara a distantei minime pe d.
// Desi pare ca algoritmul are complexitatea O(n^2), el are de fapt 
// complexitatea O(n) intrucat bucla interioara are cel mut 7 iteratii.
float stripClosest(struct Point strip[], int size, float d) { 
    int i, j;
    float min = d;  // Initialize the minimum distance as d 
  
    qsort(strip, size, sizeof(struct Point), compareY);  
  
    // selectam punctele unul cate unul si calculam distanta catre punctele
    // care sunt plasate la distanta mai mica decat d pe axa OY
    for (i = 0; i < size; ++i) 
        for (j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
            if (dist(strip[i],strip[j]) < min) 
                min = dist(strip[i], strip[j]); 
  
    return min; 
} 
  
// O functie recursiva care calculeaza distanta cea mai mica intre doua puncte din P[].
// Punctele sunt sortate du coordonata X.
float closestUtil(struct Point P[], int n) { 
    struct Point strip[n]; 
    int i, j = 0, mid; 
    float dl, dr, d;
    struct Point midPoint;
    // Daca sunt doar 2 sau 3 puncte, utilizam algoritmul fortei brute.
    if (n <= 3) 
        return bruteForce(P, n); 
  
    // Selectam punctul din mijloc 
    mid = n/2; 
    midPoint = P[mid]; 
  
    
    // Calculam distanta minima pentru punctele din stanga liniei verticale
    // care trece prin punctul de mijloc si distanta minima pentru
    // punctele din dreapta
    dl = closestUtil(P, mid); 
    dr = closestUtil(P + mid, n-mid); 
  
    // Calculam minimul intre dl si dr
    d = min(dl, dr); 
  

    // Construim tabloul strip[] ce contine punctele mai aproapiate de linia
    // verticala ce trece prin punctul de mijloc decat distanta d.
    for (i = 0; i < n; i++) 
        if (abs(P[i].x - midPoint.x) < d) {
            strip[j] = P[i];
            j++; 
        }
  
    // cautam cele mai apropiate puncte in aceasta banda si returnam minimul intre d
    // si cea mai mica distanta din strip[]
    return min(d, stripClosest(strip, j, d) ); 
} 
  
// functia principala, gaseste distanta minima
float closest(struct Point P[], int n) { 
    qsort(P, n, sizeof(struct Point), compareX); 
  
    // Se foloseste functia recursiva closestUtil().
    return closestUtil(P, n); 
} 
  
// functia main 
int main() 
{ 
    struct Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}; 
    int n = sizeof(P) / sizeof(P[0]); 
    printf("The smallest distance is %f ", closest(P, n)); 
    return 0; 
}