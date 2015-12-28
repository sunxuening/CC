/**
 * Dynamic Programming.
 * 
 * Get the length of the longest increasing subsequence in a sequence. 
 *
 * @author Xuening Sun
 *
 */
 
#include <stdio.h>
#include <stdlib.h>

int lis(int A[], int n){
  int* d = (int*)malloc( sizeof(int)*n );
  int len = 1;
  for(int i = 0; i < n; ++i){
    d[i] = 1;
    for(int j = 0; j < i; ++j)
      if(A[j] <= A[i] && d[j] + 1 > d[i])
        d[i] = d[j] + 1;
    if(d[i] > len) len = d[i];
  }
  free(d);
  return len;
}

int main(){
  int A[] = {
    5, 3, 4, 8, 6, 7
  };
  printf("%d\n", lis(A, 6));
  return 0;
}
