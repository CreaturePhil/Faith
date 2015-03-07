/**
 * http://www.spoj.com/problems/DOUGHNUT/
 *
 * DOUGHNUT - Harry and big doughnuts
 *
 * Young Harry was asked to buy some foodstuffs for his neighbour – a strange 
 * old lady who lived with a bunch of fat cats. But the cats were strange too 
 * and they ate only doughnuts. So the lady wanted Harry to bring exactly one 
 * doughnut for each of her cats – and she had c of them. Harry had a rucksack 
 * with him but as he was a little boy he could carry only k kilograms. Harry 
 * knew that each doughnut weights w kilograms (big cats, big doughnuts). Help 
 * him decide whether he should go to supermarket and buy the doughnuts or 
 * just give up and dream he could do some magic...
 *
 * Input
 * 
 * There is a single positive integer t (t <= 100) on the first line of input 
 * which corresponds to the number of tests (Harry was asked to buy doughnuts 
 * few times). Then t lines follow, each containing three numbers: 
 * c, k and w (1 <= c, k, w <= 100). 
 * 
 * t [number of tests]
 * c k w [number of cats, Harry's hoisting capacity and weight of doughnut]
 * c k w [next test case]
 * ...
 * 
 * Output
 * 
 * t lines containing word “yes” if Harry is capable of handling the task or “no” 
 * if doughnuts would cause his spine crack.
 * 
 * Example
 * 
 * Input:
 * 3
 * 5 15 3
 * 1 5 4
 * 13 25 2
 * 
 * Output:
 * yes
 * yes
 * no
 */

#include <stdio.h>

int main(void)
{
  int tests;
  scanf("%i", &tests);

  int numCats, holdingCapacity, doughnutWeight;

  while(tests--) {
    scanf("%i %i %i", &numCats, &holdingCapacity, &doughnutWeight);

    if ((numCats * doughnutWeight) <= holdingCapacity)
      printf("yes\n");
    else
      printf("no\n");
  }

  return 0;
}
