# Push_Swap project
## How To Use Push_Swap
1. Copy and paste the following in shell
```
git clone https://github.com/Lucabhm/Push_Swap.git
```
2. cd inside the push_swap directory and use the following command to compile the files
```
make
```
3. use this syntax to execute the Program
```
./push_swap <random numbers>
```
4. if you want to compile the bonus part use
```
make bonus
```
5. to execute the bonus part use this syntax
```
./checker <random numbers>
```
## Introduction
The Push swap project is a very simple and a highly straightforward algorithm project: data must be sorted.
You have at your disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks.
Your goal? Write a program in C called push_swap which calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.
## Mandatory part
### The rules
+ You have 2 stacks named a and b.
+ At the beginning:
+ The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
+ The stack b is empty.
+ The goal is to sort in ascending order numbers into stack a.
+ To do so you have the following operations at your disposal:
  - sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
  - sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
  - ss : sa and sb at the same time.
  - pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  - pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  - ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
  - rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
  - rr : ra and rb at the same time.
  - rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
  - rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one. 
  - rrr : rra and rrb at the same time.
## Bonus part
+ Write a program named checker that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given, it stops and displays nothing.
+ It will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, the program has to execute them on the stack received as an argument.
+ If after executing those instructions, the stack a is actually sorted and the stack b is empty, then the program must display "OK" followed by a ’\n’ on the standard output.
+ In every other case, it must display "KO" followed by a ’\n’ on the standard output.
+ In case of error, you must display "Error" followed by a ’\n’ on the standard er- ror. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or is incorrectly formatted.
## Images
![F86D606D-9D0A-4C56-9A38-FF29A66236F4](https://github.com/Lucabhm/Push_Swap/assets/144374574/be89a908-7d40-404c-a561-e7a7f9d4f055)
## My Result
![FF961C62-0D62-4313-B881-7A313DA2B6FD](https://github.com/Lucabhm/Push_Swap/assets/144374574/9f376faa-7e08-4c46-a0fc-a54ad2e0bd1b)
