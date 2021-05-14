#include<stdio.h>

#define N 8
#define true 1
#define false 0

int board[N][N];

// function to print solution 
void printSolution(int board[N][N]) {
    int i,j; 
    for (i = 0; i < N; i++) { 
        for (j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
         
        printf("\n");
    } 
} 
  
//function to check if queen can 
// be placed on board[row][col] 

int isPossible(int row, int col, int slashDiagnol[N][N],
            int backSlashDiagnol[N][N], int rowLook[N],
            int slashDiagnolLook[], int backSlashDiagnolLook[]) { 
    if (slashDiagnolLook(slashDiagnol[row][col] || backSlashDiagnol[row][col] || rowLook[row] )
        return false; 
  
    return true; 
} 
  
//A recursive utility function to solve N Queen problem 
int solveNQueensUtil(int board[N][N], int col,
    int slashDiagnol[N][N],int backSlashDiagnol[N][N], 
    int rowLook[N], int slashDiagnolLook[],
    int backSlashDiagnolLook[] ) { 
    //base case: If all queens are placed
    if (col >= N) 
        return true; 
  
    //Consider this column and try placing 
    // queen in all rows one by one 
    for (int i = 0; i < N; i++) { 
       
        if ( isPossible(i, col, slashDiagnol, backSlashDiagnol,
             rowLook, slashDiagnolLook,  backSlashDiagnolLook)  ) {
            board[i][col] = 1; 
            rowLook[i] = true; 
            slashDiagnolLook[slashDiagnol[i][col]] = true;
            backSlashDiagnolLook[backSlashDiagnol[i][col]] = true;
  
            //recur to place rest of the queens 
            if ( solveNQueensUtil(board, col + 1, slashCode, backslashCode, 
                    rowLook, slashCodeLookup, backslashCodeLookup) ) 
                return true; 
  
            // placing queen in board[i][col] 
            // dosen't yield a solution, backtrack
 
            board[i][col] = 0; 
            rowLook[i] = false; 
            slashDiagolLook[slashDiagnol[i][col]] = false;
            backSlashDiagnolLook[backSlashDiagnol[i][col]] = false;
        } 
    } 
  
    //If queen can not be placed in any row in 
   //this colum col then return false 
    return false; 
} 
  
/* This function solves the N Queen problem using 
Branch and Bound. It mainly uses solveNQueensUtil() to 
solve the problem. It returns false if queens 
cannot be placed, otherwise return true and 
prints placement of queens in the form of 1s. 
Please note that there may be more than one 
solutions, this function prints one of the 
feasible solutions.*/
int solveNQueens() { 
   int i, j;
     for (i = 0; i < N; i++) 
        for (j = 0; j < N; j++)
            board[i][j] = 0;
  
    // helper matrices 
    int slashDiagnol[N][N];
    int backSlashDiagnol[N][N];
  
    // arrays to tell us which rows are occupied 
    int rowLook[N] = {false}; 
  
    //keep two arrays to tell us which diagonals are occupied 
    bool slashDiagnolLook[2*N-1] = {false};
    bool backSlashDiagnolLook[2*N-1] = {false};
  
    // initialize helper matrices 
    for (i = 0; i < N; i++)
        for ( j = 0; j < n; j++)
        {
            slashDiagnol[i][j] = i+j;
            backSlashDiagnol[i][j] = (i+j-7);
         }
  
    if (solveNQueensUtil(board, 0, slashDiagnol, backSlashDiagnol,
      rowLook, slashDiagnolLook, backSlashDiagnolLook) == false)
    { 
        printf("No solution \n");
        return false; 
    } 
  
    // solution found 
    printSolution(board); 
    return true; 
} 
  
// main function
int main() 
{ 
    
    solveNQueens();
    return 0; 
} 