# push_swap 🔄 - Because Swap_push isn’t as natural
[![xvoorvaa's 42 push_swap Score](https://badge42.vercel.app/api/v2/cl1l0g8q3005209mm02a81gfy/project/2336649)](https://github.com/JaeSeoKim/badge42)

### In Short...
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.
To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

#### Workflows to check Linux and macOS compilation:

[![Push_swap MacOs compile check CI](https://github.com/xvoorvaa/push_swap/actions/workflows/MacOs_compilation.yml/badge.svg)](https://github.com/xvoorvaa/push_swap/actions/workflows/MacOs_compilation.yml)

[![Push_swap Ubuntu compile check CI](https://github.com/xvoorvaa/push_swap/actions/workflows/ubuntu_compilation.yml/badge.svg)](https://github.com/xvoorvaa/push_swap/actions/workflows/ubuntu_compilation.yml)

### The rules

You have 2 stacks named stack a and b. <br>
At the beginning: <br>
- The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
- The stack b is empty.
#### The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal: <br>

 <table>
<li><code>sa</code> : <code>swap a</code> - Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements).</li>
<li><code>sb</code> : <code>swap b</code> - Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements).</li>
<li><code>ss</code> : <code>sa</code> and <code>sb</code> at the same time.</li>
<li><code>pa</code> : <code>push a</code> - take the first element at the top of b and put it at the top of a. Do nothing if B is empty.</li>
<li><code>pb</code> : <code>push b</code> - take the first element at the top of a and put it at the top of b. Do nothing if A is empty.</li>
<li><code>ra</code> : <code>rotate a</code> - shift up all elements of stack A by 1. The first element becomes the last one.</li>
<li><code>rb</code> : <code>rotate b</code> - shift up all elements of stack B by 1. The first element becomes the last one.</li>
<li><code>rr</code> : <code>ra</code> and <code>rb</code> at the same time.</li>
<li><code>rra</code> : <code>reverse rotate a</code> - shift down all elements of stack A by 1. The last element becomes the first one.</li>
<li><code>rrb</code> : <code>reverse rotate b</code> - shift down all elements of stack B by 1. The last element becomes the first one.</li>
<li><code>rrr</code> : <code>rra</code> and <code>rrb</code> at the same time.</li>
</table>

### Usage

To compile, run the following command:
```
git clone git@github.com:xvoorvaa/push_swap.git
cd push_swap
make
```
When finished, use the executable <code>./push_swap</code> with digits as arguments.

#### Examples
```
$> ./push_swap 0 3 2 1
$> pb
$> sa
$> rra
$> pa
```
```
$> ./push_swap 2 1 3
$> sa
```
```
$> ./push_swap 1 2 3
$>
```


### Third party tutorials
Jamie Dawson - [Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) <br>
Leo Fu - [Push_Swap Tutorial](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
