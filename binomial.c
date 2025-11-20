/**
 *
 * Yousif Alboufradi, Mason Melcher
 * 2025-11-20
 *
 * Implementing a recursive pascal function and utilizing memoization
 * for efficiency
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "binomial.h"

 long choose(int n, int k) {
    if(k == 0 || n == k) {
        return 1;
    } else {
     return choose(n - 1, k) + choose(n - 1, k - 1);
    }
 }



// memoization implementation:
long chooseMem(int n, int k, long table[n+1][n+1]) {

    if(table[n][k] != -1) {
        return table[n][k];
    }
    if(k == 0 || n == k) {
        return 1;
    } else {
        // pay for the recursion
        long result =  chooseMem(n - 1, k, table) + chooseMem(n - 1, k - 1, table);
        table[n][k] = result; // cache it
        return result;

    }
}





