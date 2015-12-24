#include <stdio.h>
#include <stdlib.h>

/**
 * one prime only can be divisible by one and self.
 * actually, two is smallest prime, three is the 2th prime.
 */
int isp1(int n)
{
  if(n < 2)
    return 0;
  for(int i = 2; i < n ; i++)
    if(n%i == 0)
      return 0;
  return 1;
}


/**
 * on the basis of the theory of numbers,
 * one number Isn't prime, if the number can be divisible by number less than * it's sqrt.
 * because sqrt method should be include <math.h>, so just using multiple.
 */
int isp2(int n)
{
  if(n < 2)
    return 0;
  for(int i = 2; i * i <= n; i++)
    if(n%i == 0)
      return 0;
  return 1;
}

/**
 * n&1 == 1 or n%2 == 1, n is odd, in turn n is even.
 * and more, even certainly not be prime except 2.
 */
int isp3(int n)
{
  if(n == 2)
    return 1;
  if(n < 2 || !(n&1))
    return 0;
  for(int i = 3; i * i <= n + 1 ; i = i + 2)
    if(n%i == 0)
      return 0;
  return 1;
}

/**
 * sieve of Eratosthenes,
 * for Big Prime.
 */
int* sieve4primes(int n)
{
  int* arr  = (int*)malloc( sizeof(int)*n );
  int i, j;
  for(i = 0; i < n; i++)
    *(arr + i) = 1;
  *arr = *(arr + 1) = 0;
  int count = 2;// 0, 1 is not
  for(i = 2 ; i*i <= n; i++)
    if(arr[i])
      for(j = i + i ; j <= n ; j += i){
        arr[j] = 0;
        count++;
      }
  count = n - count;
  int* ps = (int*)malloc( sizeof(int)*count );

  for(i = 0, count = 0 ; i < n; i++)
    if(arr[i]){
      ps[count++] = i;
      printf("%10d ", i);
      if(count % 10 == 0)
        printf("\n");
    }
  printf("\nPrime count is %d.\n", count);
  return arr;
}

/**
 * all primes below n.
 */
int* primes(int n)
{
  int* ps = (int*)malloc( sizeof(int)*n );
  int count = 0;
  for(int i = 0 ; i < n ; i++)
    if(isp3(i)){
      ps[count++] = i;
      printf("%10d ", i);
      if(count % 10 == 0)
        printf("\n");
    }
  printf("\nPrime count is %d.\n", count);
  return ps;
}

int main(int argc, char *argv[])
{
  int N = atoi(argv[1]);
  free(primes(N));
  free(sieve4primes(N));
  return 0;
}
