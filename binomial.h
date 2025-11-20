/**
 *
 * Yousif Alboufradi, Mason Melcher
 * 2025-11-20
 *
 * Header file for pascal recursion implementation
 *
 */
 #include <stdio.h>
 #include <stdlib.h>


 /**
  * recursive solution for the pascal formula
  */
 long choose(int n, int k);

 /**
  *  recursive solution for the pascal formula BUT this one uses memoization to
  *  improve efficiency.
  */
 long chooseMem(int n, int k, long table[n+1][n+1]);