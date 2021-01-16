#include <stdlib.h>
#include <stdio.h>

int deckLen (int *deck[]) {
    int len = 0;
    while (deck[len] != NULL) len++;
    return len;
}

// void swap (int *a, int *b) {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

void shuffle(int *deck[]) {
    int len = deckLen(deck);
    int cut = len/2 + len%2;

    int **shuffled = malloc(len * sizeof(int *));
    
    
    for (int i=0; i<len; i++) {
        shuffled[i] = deck[i/2 + (i%2)*cut];
    }
    for (int i=0; i<len; i++) {
        deck[i] = shuffled[i];
    }
    free(shuffled);
}

void print(int *deck[]) {
    int len = deckLen(deck);
    for (int i=0; i<len; i++) {
        printf("%d", *(deck[i]));
        if (i != len-1) printf(" ");
        else printf("\n");
    }
}