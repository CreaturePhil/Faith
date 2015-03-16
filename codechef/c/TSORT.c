/**
 * Turbo Sort
 *
 * Problem Code: TSORT
 *
 * Given the list of numbers, you are to sort them in non decreasing order.
 * Input
 * 
 * t – the number of numbers in list, then t lines follow [t <= 10^6]. 
 * 
 * Each line contains one integer: N [0 <= N <= 10^6]
 * Output
 * 
 * Output given numbers in non decreasing order.
 * Example
 * 
 * Input:
 * 5
 * 5
 * 3
 * 6
 * 7
 * 1
 * Output:
 * 1
 * 3
 * 5
 * 6
 * 7
 */

#include <stdio.h>
#include <stdlib.h>

int compare( const void *a, const void *b)
{
  int int_a = * ( (int*) a );
  int int_b = * ( (int*) b );

  if ( int_a == int_b ) return 0;
  else if ( int_a < int_b ) return -1;
  else return 1;
}

int main(void)
{
  int test_cases, len, num, i;

  scanf("%d", &test_cases);

  len = test_cases;

  int arr[test_cases];

  while(test_cases--) {
    scanf("%d", &num);
    arr[test_cases] = num;
  }

  qsort (arr, len, sizeof(int), compare);
  for (i = 0; i < len; i++)
    printf("%d\n", arr[i]);

  return 0;
}

