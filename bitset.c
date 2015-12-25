/**
 * Bitmap struct for sort, unique and so on.
 *
 * @author Xuening Sun
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define BITS sizeof(int) * 8 // 4*8=32

#define SHIFT 5 // 2^5=32

#define MASK 0x1f // 2^5=32

#define MAX 1024*1024*1024 //max number

int bitset [MAX / BITS];

void set(int i)
{
  bitset[i >> SHIFT] |= (1 << (i & MASK));
}

int get(int i)
{
  return bitset[i >> SHIFT] & (1 << (i & MASK));
}

int prime(int N)
{
  int i,j;
  for(i = 2; i*i <= N; i++){
    if(get(i)) continue;
    j = i*i;
    while(j <= N){
      set(j);
      j += i;
    }
  }
  int count = 0;
  for(i = 2; i <= N; i++){
    if(!get(i)) {
      printf("%10d ", i);
      count++;
      if(count%10 == 0) printf("\n");
    }
  }
  return count;
}
int main(int argc, char *argv[])
{
  int N = atoi(argv[1]);
  printf("\nPrimes below %d:\n", N);
  printf("\nPrimes count is %d.\n", prime(N));
  return 0;
}
