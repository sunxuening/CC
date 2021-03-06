/**
 *
 * Greedy algorithm
 * Get the big number from the combination of numbers.
 *
 * @author Xuening Sun
 *
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef int BOOL;
#define false 0
#define true 1

BOOL compare(int num1, int num2);

int main(int argc, char *argv[])
{
  int N, i, j;
  printf("Please input number:");
  scanf("%d", &N);
  int* arr = (int*)malloc(sizeof(int)*N);
  for(i = 0; i < N ; i++){
    printf("Please input number %d:", i + 1);
    scanf("%d", &arr[i]);
  }

  int temp;
  for(i = 0; i <= N-1; ++i)
    {
      for(j = 0; j < N-i-1; j++)
        if( compare(arr[j], arr[j+1]) ) //key for greedy choose
          {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
          }
    }
  printf("The max number is:");
  for(i = N - 1 ; i >= 0 ; --i)
    printf("%d", arr[i]);
  printf("\n");
  free(arr);
  return 0;
}

BOOL compare(int num1,int num2)
{
  int count1 = 0, count2 = 0;
  int MidNum1 = num1,MidNum2 = num2;
  while( MidNum1 )
    {
      ++count1;
      MidNum1 /= 10;
    }

  while( MidNum2 )
    {
      ++count2;
      MidNum2 /= 10;
    }
  int a = num1;
  int b = num2;
  for(int i = 0; i < count2; i++)
    a = a * 10;
  a += num2;
  for(int i = 0; i < count1; i++)
    b = b * 10;
  b += num1;

  return (a > b)? true:false;
}
