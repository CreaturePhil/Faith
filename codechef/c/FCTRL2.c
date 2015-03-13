/*
 * Small factorials
 *
 * Problem code: FCTRL2
 *
 * You are asked to calculate factorials of some small positive integers.
 * Input
 * 
 * 
 * An integer t, 1<=t<=100, denoting the number of testcases, followed by t 
 * lines, each containing a single integer n, 1<=n<=100.
 *
 * Output
 * 
 * For each integer n given at input, display a line with the value of n!
 *
 * Example
 * 
 * Sample input:
 * 4
 * 1
 * 2
 * 5
 * 3
 *
 * Sample output:
 * 1
 * 2
 * 120
 * 6
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 200

void print_factorial(int num);
void array_multiplication(char *arr, int len, int n);

int main(void)
{
  int test_cases, num;

  scanf("%d", &test_cases);

  while(test_cases--) {
    scanf("%d", &num);

    print_factorial(num);
    printf("\n");
  }

  return 0;
}

void print_factorial(int num)
{
  char result[MAX_LEN]; 
  int start = 0;
  int i, len = MAX_LEN;

  // Sets the first `MAX_LEN` characters of `result` to the value 0.
  memset(result, 0, MAX_LEN);

  result[0] = 1;

  for (i = 2; i <= num; i++) {
    array_multiplication(result, MAX_LEN, i);
  }
  
  while(len--) {
    if (start) {
      printf("%d", result[len]);
      continue;
    }
    if (result[len] != 0) {
      printf("%d", result[len]);
      start = 1;
    }
  }
}

void array_multiplication(char *arr, int len, int n)
{
  char list[len]; 
  int i;
  int counter = 0, tmp = 0;

  // Copies `len` characters from `arr` to `list`.
  memcpy(list, arr, len); 

  // Sets the first `len` characters of `arr` to the value 0.
  memset(arr, 0, len); 

  for (i = 0; i < len; i++) {
    tmp = counter + list[i] * n; 
    if (tmp < 10) {
      arr[i] = tmp;
      counter = 0;
    } else {
      arr[i] = tmp % 10;
      counter = tmp / 10;
    }
  }
}
