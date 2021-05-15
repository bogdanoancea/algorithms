#include<stdio.h>

#define N 8
#define true 1
#define false 0

int board[N][N];

// tiparirea solutiei
void printSolution(int board[N][N]) {
    int i,j; 
    for (i = 0; i < N; i++) { 
        for (j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
         
        printf("\n");
    } 
} 
  


/* Functie optimizata care verifica daca o regina poate fi plasata
pe tabla in pozitia board[row][col] 
*/
int isSafe(int row, int col, int slashCode[N][N], int backslashCode[N][N], int rowLookup[], 
    int slashCodeLookup[], int backslashCodeLookup[] ) {

    if (slashCodeLookup[slashCode[row][col]] || backslashCodeLookup[backslashCode[row][col]] || rowLookup[row])
        return false;
 
    return true;
}
  

/* Functie recursiva care rezolva problema celor N regine */
int solveNQueensUtil(int board[N][N], int col, int slashCode[N][N], int backslashCode[N][N],
        int rowLookup[N], int slashCodeLookup[], int backslashCodeLookup[] ) {
    /* daca am plasat toate regine am rezolvat problema */
    if (col >= N)
        return true;
 
    /* Pe coloana col incercam sa plasam regina pu un rand */
    for (int i = 0; i < N; i++)  {
        /* Verificam daca regina paote fi plasata in pozitia
           board[i][col] */
        if ( isSafe(i, col, slashCode, backslashCode, rowLookup,
          slashCodeLookup, backslashCodeLookup) ){
            /* Place this queen in board[i][col] */
            board[i][col] = 1;
            rowLookup[i] = true;
            slashCodeLookup[slashCode[i][col]] = true;
            backslashCodeLookup[backslashCode[i][col]] = true;
 
            /* recursiv, incercam sa plasam urmatoarea regina */
            if ( solveNQueensUtil(board, col + 1, slashCode, backslashCode,
             rowLookup, slashCodeLookup, backslashCodeLookup) )
                return true;
 
            /* Daca plasarea reginei in ozitia board[i][col]
            nu conduce la o solutie, mergem inapoi un pas */
 
            /* Luam regina de pe pozitia board[i][col] */
            board[i][col] = 0;
            rowLookup[i] = false;
            slashCodeLookup[slashCode[i][col]] = false;
            backslashCodeLookup[backslashCode[i][col]] = false;
        }
    }
  /* Daca nu putem plasa regina pe nici un rand, returnam false */
    return false;
}

  
// Functia returneaza false daca reginele nu pot fi plaste pe tabla
// altfel returneaza true. Functia returneaza o singura solutie
//
int solveNQueens() {
    int board[N][N];
    int i,j; 
    for (i = 0; i < N; i++) 
        for (j = 0; j < N; j++)
            board[i][j]=0;
 
    // matrici ajutatoare
    int slashCode[N][N];
    int backslashCode[N][N];
 
    // vector care tine evidenta randurilor atacate
    int rowLookup[N];
    for( i =0; i < N; i++)
        rowLookup[i] = false;

    //vectorii tin evidenta coloanelor atacate
    int slashCodeLookup[2*N - 1];
    for( i =0; i < 2 * N -1; i++) 
        slashCodeLookup[i] = false;
    int backslashCodeLookup[2*N - 1];
    for( i =0; i < 2 * N -1; i++) 
         backslashCodeLookup[i] = false;
 
    // initializam matricile ajutatoare
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            slashCode[i][j] = i + j;
            backslashCode[i][j] = i - j + N - 1;
        }
 
    if (solveNQueensUtil(board, 0, slashCode, backslashCode,
      rowLookup, slashCodeLookup, backslashCodeLookup) == false ) {
        printf("nu exista solutie!");
        return false;
    }
 
    // solutia a fost gasita!
    printSolution(board);
    return true;
}

int main() {
    solveNQueens();
 
    return 0;
}