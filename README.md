# 42_PUSH_SWAP 🔄
Sorting data on stacks.
# About ✍
Being the first Rank02 project of 42 Common Core, Push_swap is all about sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. 
The goal is to write a program in C which calculates and displays on the standard output the list of operations between two stacks that sorts in ascending order the integers received as arguments.
For this I needed to choose for a sort algorithm that optimized the most this whole proccess, and my choice was the Turk Algorithm.
# Operations Allowed 🔀
- `sa` (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- `sb` (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- `ss` : sa and sb at the same time.
- `pa` (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- `pb` (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- `ra` (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- `rb` (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : ra and rb at the same time.
- `rra` (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : rra and rrb at the same time.
# Turk Algorithm ⚙️
The Turk Algorithm was developed by another 42 student called Ali Ogun  and it is detailed in his article available [here](https://medium.com/@ayogun/push-swap-c1f5d2d41e97). Essentially, the algorithm functions when we have more than 3 numbers as arguments. We begin by pushing the numbers from ``stack_a`` a to ``stack_b`` until only 3 elements remain in ``stack_a``. However, we do this in descending order because later we will need to push the numbers back to ``stack_a``, and they will be automatically organized.

To achieve this efficiently, we define a target node in ``stack_b`` for every node in ``stack_a``, which will be the smallest and closest number to the node in ``stack_a`` present in ``stack_b``. If a smaller number does not exist, the target will become the highest element in ``stack_b``. After that, we calculate the "cost" of each node to be pushed to the right index in ``stack_b``. Finally, we choose the cheapest node, rotate the stack to bring the node to the top (if needed), and then push it.

When only three elements are left in ``stack_a``, we begin pushing the numbers back from ``stack_b`` in a similar manner. However, the target node now becomes the highest and closest number in ``stack_a``. In case a higher number does not exist, the smallest element in ``stack_b`` will then become the target.

Finally, after pushing all the elements from ``stack_b``, if necessary, we organize ``stack_a`` by rotating it until the smallest number is at the top. This ensures that all elements are sorted in ascending order, concluding the program.
