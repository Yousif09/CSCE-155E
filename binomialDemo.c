/**
 *
 * Yousif Alboufradi, Mason Melcher
 * 2025-11-20
 *
 * Tester file for the pascal recursion implementation
 *
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "binomial.h"

int main(int argc, char **argv) {

    if(argc != 3) {
        printf("Invalid mount of arguments!\n");
        exit(1);
    }
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    // memoization table initialization
    long table[n+1][n+1];
    for(int i=0; i < n+1; i++) {
        for(int j=0; j < n+1; j++) {
            table[i][j] = -1; // meaning they have not yet been computed
        }
    }

    long memResult = chooseMem(n, k, table);
    printf("the memoization result is: %ld\n", memResult);




    return 0;
}