"""
http://www.spoj.com/problems/PRIME1/

2. Prime Generator

Problem code: PRIME1

Peter wants to generate some prime numbers for his cryptosystem. Help him! 
Your task is to generate all prime numbers between two given numbers!

Input

The input begins with the number t of test cases in a single line (t<=10). 
In each of the next t lines there are two numbers m and n 
(1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output

For every test case print all prime numbers p such that m <= p <= n, 
one number per line, test cases separated by an empty line.

Example

Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
"""

from math import sqrt

primes = [2]

# Steps through each number from 3 to 32000 (the sqrt of the given upper bound) by 2
# If an individual number is prime, adds it to the list "primes"
for i in range(3, 32000, 2):
    isPrime = True

    cap = sqrt(i) + 1

    for j in primes:
        if j >= cap:
            break
        if i % j == 0:
            isPrime = False
            break

    if isPrime:
        primes.append(i)

# T is the number of integer pairs (test cases) and thus times the generator will activate
T = input()
# Clears the var "output"
output = ""

# Steps through each value in
for t in range(T):
    # After the first integer pair, adds a newline to separate the values)
    if t > 0:
        output += "\n"

    # Grabs the integer pairs from the user and splits them into two vars, m and n, where there is a space
    m, n = raw_input().split(' ')
    m = int(m)
    n = int(n)
    cap = sqrt(n) + 1

    # If the lower bound is not at least 2, make it 2 (no primes exist smaller than 2)
    if m < 2:
        m = 2

    # Changes "isPrime" into a list of 100001 "True"s
    isPrime = [True] * 100001

    # For all the irrelevant values in "primes", sets the corresponding True/False value in "isPrime" to False
    # Faster than looping through all the values of isPrime and setting them to False individually
    for i in primes:
        if 1 >= cap:
            break

        if i >= m:
            start = i * 2
        else:
            start = m + ((i - m % i) % i)

        falseBlock = [False] * len(isPrime[start-m:n+1-m:i]);
        isPrime[start-m:n+1-m:i] = falseBlock

    # Adds all the relevant primes (i.e. between n and m) to the output list
    for i in range(m, n+1):
        if isPrime[i-m] == True:
            output += str(i) + "\n"

print output[:-1]
