#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N1 10000
#define N2 50000
#define N3 100000


void swap( int* lhs, int* rhs ) {
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

void insertionSort(int a[], int n) {
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
   int tempArray[N3]; 	// tablou temporar
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
      }
    }
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

int main() {
    printf("Hello sorting algorithms!\n");
    int a1[N3];
    int b1[N3];
    int i;
    clock_t start, end;
    double cpu_time_used;

    printf("number of elements to be sorted: %d\n", N1);
    //generez valoari aleatoare pentru elementele vectorului a
    for(i = 0; i < N1; i++) {
        a1[i] = rand()%N1;
    }
    copyVector(a1,b1,N1);

    start = clock();
    selectionSort(b1,N1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("selection sort time: %.15f\n", cpu_time_used);

    copyVector(a1, b1, N1);
    start = clock();
    insertionSort(b1, N1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("insertion sort time: %.15f\n", cpu_time_used);


    copyVector(a1,b1,N1);

    start = clock();
    bubleSort(b1, N1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("buble sort time: %.15f\n", cpu_time_used);

    copyVector(a1,b1,N1);
    start = clock();
    mergesort(b1, 0, N1-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("merge sort time: %.15f\n", cpu_time_used);


    printf("number of elements to be sorted: %d\n", N2);
    //generez valoari aleatoare pentru elementele vectorului a
    for(i = 0; i < N2; i++) {
        a1[i] = rand()%N2;
    }
    copyVector(a1,b1,N2);

    start = clock();
    selectionSort(b1,N2);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("selection sort time: %.15f\n", cpu_time_used);

    copyVector(a1, b1, N2);
    start = clock();
    insertionSort(b1, N2);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("insertion sort time: %.15f\n", cpu_time_used);


    copyVector(a1,b1,N2);

    start = clock();
    bubleSort(b1, N2);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("buble sort time: %.15f\n", cpu_time_used);

    copyVector(a1,b1,N2);
    start = clock();
    mergesort(b1, 0, N2-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("merge sort time: %.15f\n", cpu_time_used);


     printf("number of elements to be sorted: %d\n", N3);
    //generez valoari aleatoare pentru elementele vectorului a
    for(i = 0; i < N3; i++) {
        a1[i] = rand()%N3;
    }
    copyVector(a1,b1,N3);

    start = clock();
    selectionSort(b1,N3);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("selection sort time: %.15f\n", cpu_time_used);

    copyVector(a1, b1, N3);
    start = clock();
    insertionSort(b1, N3);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("insertion sort time: %.15f\n", cpu_time_used);


    copyVector(a1,b1,N3);

    start = clock();
    bubleSort(b1, N3);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("buble sort time: %.15f\n", cpu_time_used);

    copyVector(a1,b1,N3);
    start = clock();
    mergesort(b1, 0, N3-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("merge sort time: %.15f\n", cpu_time_used);
    return 0;
}


