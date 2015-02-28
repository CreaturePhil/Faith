"""
http://www.spoj.com/problems/ONP/

4. Transform the Expression

Problem code: ONP

Transform the algebraic expression with brackets into 
RPN form (Reverse Polish Notation). Two-argument operators: 
+, -, *, /, ^ (priority from the lowest to the highest), brackets ( ). 
Operands: only letters: a,b,...,z. 
Assume that there is only one RPN form (no expressions like a*b*c).

Input

t [the number of expressions <= 100]
expression [length <= 400]
[other expressions]
Text grouped in [ ] does not appear in the input file.

Output

The expressions in RPN form, one per line.

Example

Input:
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^*
"""

class Stack:
  def __init__(self):
    self.items = []

  def isEmpty(self):
    return self.items == []

  def push(self, item):
    self.items.append(item)

  def pop(self):
    return self.items.pop()

  def peek(self):
    return self.items[len(self.items) - 1]

  def size(self):
    return len(self.items)

precedence = {"^": 4, "*": 3, "/": 3, "+": 2, "-": 2, "(": 1}
alphabet = "abcdefghijklmnopqrstuvwxyz" 
numbers  = "0123456789"

def infixToRPN(expression):
  """Convert infix notation to reverse polish notion"""
  stack  = Stack()
  RPNList = []
  tokens = expression.split()
  spaces = True

  # If no spaces in expression then push each char in a tokens list
  if len(tokens) == 1:
    spaces = False
    tokens = [char for char in expression]

  for token in tokens:
    if token in alphabet or token in numbers:
      RPNList.append(token)
    elif token == '(':
      stack.push(token)
    elif token == ')':
      top = stack.pop()
      while top != '(':
        RPNList.append(top)
        top = stack.pop()
    else:
      while (not stack.isEmpty()) and (precedence[stack.peek()] >= precedence[token]):
        RPNList.append(stack.pop())
      stack.push(token)

  while not stack.isEmpty():
    RPNList.append(stack.pop())

  if spaces:
    return " ".join(RPNList)
  else:
    return "".join(RPNList)

t = int(raw_input())
while t > 0:
  print infixToRPN(raw_input())
  t -= 1
