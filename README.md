# push_swap 🔄 - Because Swap_push isn’t as natural

### In Short
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.
To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

#### Workflows to check Linux and macOS compilation:

[![Push_swap Ubuntu compile check CI](https://github.com/xvoorvaa/push_swap/actions/workflows/ubuntu_compilation.yml/badge.svg)](https://github.com/xvoorvaa/push_swap/actions/workflows/ubuntu_compilation.yml)

[![Push_swap Ubuntu compile check CI](https://github.com/xvoorvaa/push_swap/actions/workflows/ubuntu_compilation.yml/badge.svg)](https://github.com/xvoorvaa/push_swap/actions/workflows/ubuntu_compilation.yml)

#### Workflow to check if program does what it should do:



### The rules

You have 2 stacks named stack a and b. <br>
At the beginning: <br>
- The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
- The stack b is empty. <br> <br>
#### The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal: <br>

  <p>
  <  sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. <br>
  <  sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. <br>
  <  ss: sa and sb at the same time. <br>
  <  pa (push a): Take the first element at the top of stack b and put it at the top of stack a. Do nothing if stack b is empty. <br>
  <  pb (push b): Take the first element at the top of stack a and put it at the top of stack b. Do nothing if stack a is empty. <br>
  <  ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one. <br>
  <  rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one. <br>
  <  rr: ra and rb at the same time. <br>
  <  rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one. <br>
  <  rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one. <br>
  <  rrr: rra and rrb at the same time. <br>
  </p>
