/**
 * http://www.spoj.com/problems/PALIN/
 *
 * 5. The Next Palindrome
 *
 * Problem code: PALIN
 *
 * A positive integer is called a palindrome if its representation in the 
 * decimal system is the same when read from left to right and from right to 
 * left. For a given positive integer K of not more than 1000000 digits, write 
 * the value of the smallest palindrome larger than K to output. Numbers are 
 * always displayed without leading zeros.
 *
 * Input
 * The first line contains integer t, the number of test cases. Integers K are given in the next t lines.
 *
 * Output
 * For each K, output the smallest palindrome larger than K.
 *
 * Example
 * Input:
 * 2
 * 808
 * 2133
 * 
 * Output:
 * 818
 * 2222
 */

#include <stdio.h>

int main(void)
{
  int numTestCases, num, i;

  scanf("%i", &numTestCases);

  int nums[numTestCases];

  for (i = 0; i < numTestCases; i++) {
    scanf("%i", &num);

    nums[i] = num;
  }

  for (i = 0; i < numTestCases; i++) {
    num = nums[i];
    printf("\n");
    for (++num; num < (num + 10000); num++) {
      if (isPalin(num)) {
        printf("%i\n", num);
        break;
      }
    }
  }

  return 0;
}

int reverseNum(int num)
{
  int n, rev, dig;

  n = num;
  rev = 0;
  while (num > 0)
  {
    dig = num % 10;
    rev = rev * 10 + dig;
    num = num / 10;
  }

  return rev;
}

int isPalin(int num)
{
  if (num == reverseNum(num)) {
    return 1;
  } else {
    return 0;
  }
}
