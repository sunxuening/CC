/**
 * Comparsion Sort.
 *
 * @author Xuening Sun
 *
 */
#include<stdio.h>
#include<stdbool.h>

//swap point only for int
void swap(int* a, int* b)
{
  if(*a != *b){//zero check
    *b = *b^*a;
    *a = *a^*b;
    *b = *b^*a;
  }
}

//Shell Sort
void shellSort(int* array, int size)
{
  int m = 1;

  while (m <= size)
    {
      m = 3 * m + 1;
    }

  while (m > 0)
    {
      m = m / 3;
      int k;
      for (k = 1; k < m; k++)
        {
          /*Insertion Sort */
          int i;
          for (i = 1; i < size; i++)
            {
              int j;
              for (j = i; j > 0 && arr[j-1] > arr[j]; j--)
                {
                  // Xor swap
                  arr[j]   ^= arr[j-1];
                  arr[j-1] ^= arr[j];
                  arr[j]   ^= arr[j-1];
                }
            }
        }
    }
}

//Binary Sort, from Insert Sort
void binarySort(int* arr, int n)
{
  int left, right, key;
  int mid, j, i;
  for(i = 1; i < n; i++) //just start from 1
  {
      left = 0;
      right = i - 1;
      key = arr[i]; //temp cache i's value
      while( left <= right )// insert position
      {
          mid = left + (( right - left ) >> 1); //　avoid overflow
          if( key < arr[mid] )
            right = mid - 1;
          else        
            left = mid + 1;
      }
      for(j = i - 1; j >= left; j-- )
        arr[j+1] = arr[j];
      arr[left] = key;
    }
}

//Insert Sort
void insertSort (int* arr,int n)
{
  for(int i = 1 ; i < n; i++) {
    int tmp = arr[i];
    for(int j = i - 1; j >= 0 && arr[j] > tmp; j--)
      swap(&arr[j + 1], &arr[j]);
  }
}

//Quick Sort
void quickSort (int* arr, int left, int right)
{
  int i = left, j = right;
  int tmp;
  int pivot = arr[(left + right) >> 1];

  /* partition */
  while (i <= j) {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j) {
      swap(&arr[i], &arr[j]);
      i++;
      j--;
    }
  };

  /* recursion */
  if (left < j)
    quickSort(arr, left, j);
  if (i < right)
    quickSort(arr, i, right);
}

//Bubble Sort
void bubbleSort(int* arr, int n)
{
  bool swapped = true;
  int j = 0;
  while (swapped) {
    swapped = false;
    j++;
    for ( int i = 0 ; i < n - j ; i++) {
      if ( arr[i] > arr[i + 1]) {
        swap(&arr[i], &arr[i + 1]);
        swapped = true;
      }
    }
  }
}

//Print Arrays
void printArr(int* z, int n)
{
  for (int i = 0; i < n; i++)
    printf ("%-4d", z[i]);
  printf ("\n");
}

int main ()
{
  int a[9]={1,2,0,3,5,8,9,1,2};
  int b[9]={0,2,1,4,4,0,8,9,3};
  int c[9]={9,8,7,2,4,5,5,0,3};
  int d[9]={2,-1,6,7,1,4,25,0,3};

  int n, arr[n];
  bubbleSort(a, 9);
  printArr(a, 9);
  insertSort(b, 9);
  printArr(b, 9);
  binarySort(c, 9);
  printArr(c, 9);
  shellSort(d, 9);
  printArr(d, 9);
  printf ("Enter number of arrays:");
  scanf("%d", &n);
  printf ("Enter %d integers\n", n);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", &arr[i]);
  quickSort(arr, 0, n-1);
  printArr(arr, n);

}
