#include <stdio.h>
#include <stdlib.h>
// A job has a start time and a finish time.
struct Activity 
{ 
    int start, finish; 
}; 
  
// A utility function that is used for sorting 
// activities according to finish time 
int activityCompare(const void *s1, const void *s2) 
{ 
    return (((struct Activity*)s1)->finish - ((struct Activity*)s2)->finish); 
} 
  
// Returns count of the maximum set of activities that can 
// be done by a single person, one at a time. 
void printMaxActivities(struct Activity arr[], int n)  { 
    // Sort jobs according to finish time 
    qsort(arr, n, sizeof(struct Activity), activityCompare); 
  
    printf("Following activities are selected \n"); 
  
    // The first activity always gets selected 
    int i = 0; 
    printf("( %d , %d ),", arr[i].start, arr[i].finish ); 
  
    // Consider rest of the activities 
    for (int j = 1; j < n; j++) 
    { 
      // If this activity has start time greater than or 
      // equal to the finish time of previously selected 
      // activity, then select it 
      if (arr[j].start >= arr[i].finish) 
      { 
          printf("( %d , %d ),", arr[j].start, arr[j].finish ); 
          i = j; 
      } 
    } 
    printf("\n");
} 
  
// Driver program 
int main() 
{ 
    struct Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, 
                                       {5, 7}, {8, 9}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printMaxActivities(arr, n); 
    return 0; 
} 
