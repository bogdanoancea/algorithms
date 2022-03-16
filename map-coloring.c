/* Problema colorarii hartilor */

#include <stdio.h>
#include <stdlib.h>

#define NONE  0
#define RED  1
#define YELLOW  2
#define GREEN  3
#define BLUE  4

#define  NO_COUNTRIES 7
#define true 1
#define false 0

int **map;
int mapColors[] = { NONE, NONE, NONE, NONE, NONE, NONE, NONE };
int noNeighbours[NO_COUNTRIES];

void createMap() {
    map = (int**)malloc(NO_COUNTRIES * sizeof(int*));
    map[0] = (int*) malloc(4 * sizeof(int));
    map[0][0] = 1;
    map[0][1] = 4;
    map[0][2] = 2;
    map[0][3] = 5;
    noNeighbours[0] = 4;

    map[1] = (int*) malloc(4 * sizeof(int));
    map[1][0] = 0;
    map[1][1] = 4;
    map[1][2] = 6;
    map[1][3] = 5;
    noNeighbours[1] = 4;

    map[2] = (int*) malloc(5 * sizeof(int));
    map[2][0] = 0;
    map[2][1] = 4;
    map[2][2] = 3;
    map[2][3] = 6;
    map[2][4] = 5;
    noNeighbours[2] = 5;

    map[3] = (int*) malloc(3 * sizeof(int));
    map[3][0] = 2;
    map[3][1] = 4;
    map[3][2] = 6;
    noNeighbours[3] = 3;

    map[4] = (int*) malloc(5 * sizeof(int));
    map[4][0] = 0;
    map[4][1] = 1;
    map[4][2] = 6;
    map[4][3] = 3;
    map[4][4] = 2;
    noNeighbours[4] = 5;

    map[5] = (int*) malloc(4 * sizeof(int));
    map[5][0] = 2;
    map[5][1] = 6;
    map[5][2] = 1;
    map[5][3] = 0;
    noNeighbours[5] = 4;

    map[6] = (int*) malloc(5 * sizeof(int));
    map[6][0] = 2;
    map[6][1] = 3;
    map[6][2] = 4;
    map[6][3] = 1;
    map[6][4] = 5;
    noNeighbours[6] = 5;
}

void printMap() {
    int i;
    for (i = 0; i < NO_COUNTRIES; i++) {
        printf("map[%d] is ", i);
        switch (mapColors[i]) {
            case NONE:
                printf("none");
                break;
            case RED:
                printf("red");
                break;
            case YELLOW:
                printf("yellow");
                break;
            case GREEN:
                printf("green");
                break;
            case BLUE:
                printf("blue");
                break;
        }
        printf("\n");
    }
}


int okToColor(int country, int color) {
    int i;
    int ithAdjCountry;
    for (i = 0; i < noNeighbours[country]; i++) {
        ithAdjCountry = map[country][i];
        if (mapColors[ithAdjCountry] == color) {
            return false;
        }
    }
    return true;
}


int explore(int country, int color) {
    if (country >= NO_COUNTRIES)
        return true;
    if (okToColor(country, color)) {
        mapColors[country] = color;
        for (int i = RED; i <= BLUE; i++) {
            if (explore(country + 1, i))
                return true;
        }
    }
    return false;
}

int main() {
    int result;
    createMap();
    result = explore(0, RED);
    if(result == true)
        printMap();

    return 0;
}
