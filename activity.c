// C program for activity selection problem. You are given n activities with their start and 
// finish times. Select the maximum number of activities that can be performed by a single person, 
// assuming that a person can only work on a single activity at a time.
// The following implementation assumes that the activities 
// are already sorted according to their finish time 

#include<stdio.h> 
  
// Prints a maximum set of activities that can be done by a single 
// person, one at a time. 
//  n   -->  Total number of activities 
//  s[] -->  An array that contains start time of all activities 
//  f[] -->  An array that contains finish time of all activities 
void printMaxActivities(int s[], int f[], int n)  { 
    int i, j; 
  
    printf ("Following activities are selected: "); 
  
    // The first activity always gets selected 
    i = 0; 
    printf("%d ", i); 
  
    // Consider rest of the activities 
    for (j = 1; j < n; j++) 
    { 
      // If this activity has start time greater than or 
      // equal to the finish time of previously selected 
      // activity, then select it 
      if (s[j] >= f[i]) 
      { 
          printf ("%d ", j); 
          i = j; 
      } 
    } 
} 
  
// driver program to test above function 
int main()  { 
    int s[] =  {1, 3, 0, 5, 8, 5}; 
    int f[] =  {2, 4, 6, 7, 9, 9}; 
    int n = sizeof(s)/sizeof(s[0]); 
    printMaxActivities(s, f, n); 
    return 0; 
} 
