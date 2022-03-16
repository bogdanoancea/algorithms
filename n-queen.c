/* Problema celor N regine rezolvata prin metoda backtracking */

#define N 4
#define true 1
#define false 0

#include<stdio.h>


/* O functie care tipareste solutia */
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

/*O functie care verifica daca putem plasa o regina pe tabla in pozitia
  board[row][col]. Aceasta functie este apelata cand au fost deja plasate 
  "col" regine, pe coloanele 0 pana la col-1.
   Verificam deci doar partea din stanga */
int isSafe(int board[N][N], int row, int col) {
    int i, j;

    /* Verificam randul row pe coloanele din stanga */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    /* Verificam diagonala principala, in stanga */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;

    /* Verificam diagonala secundara, in stanga */
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

/* O functie recursiva care rezolva problema celor N regine */
int solveNQUtil(int board[N][N], int col) {
    /* daca toate reginele sunt plasate return true */
    if (col >= N)
        return true;

    /* Incercam sa plasam o regina pe coloana "col"*/
    for (int i = 0; i < N; i++) {
        /* Verifica daca pot plasa regina pe pozitia board[i][col] */
        if ( isSafe(board, i, col) ) {
            /* plasez regina pe pozitia board[i][col] */
            board[i][col] = 1;

            /* apel recursiv pentru a plasa restul de regine */
            if ( solveNQUtil(board, col + 1) )
                return true;

            /* daca plasarea reginei pe pozitie  board[i][col]
               nu a condus la o solutie atunci luam regina 
               de pe pozitia board[i][col] */
            board[i][col] = 0; // BACKTRACK
        }
    }

     /* Daca regina nu poate fi plasata pe nici un rand de pe coloana "col" 
     return false */
    return false;
}

/*  O functie care rezolva problema celor N regine prin
    metoda backtracking. functia returneaza false daca
    nu se pot plasa reginele astfel incat sa nu se atace
    si true in caz contrar, caz in care printeaza solutia
*/
int solveNQ() {
    int board[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    if ( solveNQUtil(board, 0) == false ) {
      printf("Nu exista solutie!!!");
      return false;
    }

    printSolution(board);
    return true;
}

// driver program 
int main() {
    solveNQ();
    return 0;
}