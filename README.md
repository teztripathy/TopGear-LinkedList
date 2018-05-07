# TopGear-LinkedList - By: Tejeswar Tripathy

1. Linked list
Write a program in C to manipulate linked lists. The input to the program will be a sequence of instructions of the following categories:
1. Insert name age: create a node with item as the info field and insert into the current list.
The list should always be maintained in sorted order in increasing order of age. If there is more than one person of same age, the order should be as in the input. You may assume that the input is valid and correct. 
You may assume that the name is always a single word with no spaces within. The age will be a positive integer.
2. Remove N: remove the Nth item from the list.
While executing remove, if the list does not have enough elements, the command should be ignored.
3. Print N: print the Nth item from the list. The name should be printed first and then the age with a space in between.
While executing print, if the list does not have enough elements, the command should be ignored.
4. Stop: end of instructions
Each of the instructions occurs on a different line.
Terminate each line output with a newline character.

Sample Input/ Output
Input

insert Sunil 40

insert Moha 30

print 1

insert Ganeshan 35

remove 3

print 1

stop

Output

Sunil 30

Sunil 30
