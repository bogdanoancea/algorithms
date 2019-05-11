#include <stdio.h>
#include <stdlib.h>


void swap( int* lhs, int* rhs )
{
	int tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}


void selectionSort( int a[], int n) {
  int min, i, j;
	for (i = 0; i < n-1; i++) {
    min = i;
    for (j = i+1; j < n; j++)
       if (a[j] < a[min])
			min = j;
    swap(&a[i], &a[min]);
  }
}

void insertionSort(int a[], int n)
{
    int tmp, i, j;
    for (i = 1; i < n; i++)
    {
      tmp = a[i];
      for (j=i; j>0 && tmp < a[j-1]; j--)
         a[j] = a[j-1];
      a[j] = tmp;
    }
}

void bubleSort(int a[], int n)
{
   int sorted = 0;
   int last = n-1;
   int i, j;
   for (i = 0; (i < last) && !sorted; i++){
      sorted = 1;
      for (j=last; j > i; j--)
         if (a[j-1] > a[j]) {
            swap(&a[j],&a[j-1]);
            sorted = 0; // signal exchange
         }
    }
}

void merge(int theArray[], int first, int mid, int last) {
   int tempArray[10]; 	// tablou temporar
   int first1 = first; 	        // inceputul primei liste
   int last1 = mid; 		// sfarsitul primei liste
   int first2 = mid + 1;	// inceputul celei de-a doua liste
   int last2 = last;		// sfarsitul celei de-a doua liste
   int index = first1; // urmatoarea locatie disponibila in tempArray
   for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
      if (theArray[first1] < theArray[first2]) {
         tempArray[index] = theArray[first1];
         ++first1;
      }
      else {
          tempArray[index] = theArray[first2];
          ++first2;
      } }
// prima lista
   for (; first1 <= last1; ++first1, ++index)
      tempArray[index] = theArray[first1];

// a doua lista
   for (; first2 <= last2; ++first2, ++index)
      tempArray[index] = theArray[first2];

// copiem rezultatul inapoi
   for (index = first; index <= last; ++index)
      theArray[index] = tempArray[index];
}  // end merge

void mergesort(int theArray[], int first, int last) {
   if (first < last) {
      int mid = (first + last)/2; 	// indexul punctului de mijloc
      mergesort(theArray, first, mid);
      mergesort(theArray, mid+1, last);

      // interclasam cele doua jumatati
      merge(theArray, first, mid, last);
   }
}

void printVector(int a[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void copyVector(int a[], int b[], int n) {
    int i;
    for(i = 0; i < n; i++)
        b[i] = a[i];
}

int main()
{
    printf("Hello sorting algorithms!\n");
    int a[10] = {2,1,7,9,212,43,76,1,10,15};
    int b[10], c[10], d[10] ,e[10];
    printVector(a,10);

    copyVector(a,b,10);
    selectionSort(b,10);
    printVector(b,10);

    copyVector(a,c, 10);
    insertionSort(c ,10);
    printVector(c,10);

    copyVector(a,d,10);
    bubleSort(d,10);
    printVector(d,10);

    copyVector(a,e,10);
    mergesort(e,0,9);
    printVector(e,10);

    return 0;
}
