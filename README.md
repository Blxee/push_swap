# Push Swap

This project has been created as part of the 42 curriculum by `atahiri-`.

## Description:

**Push Swap** is a challenging project about sorting a stack, it explores variable length [data-structures](https://en.wikipedia.org/wiki/Data_structure) such as queues, and [time complexity](https://en.wikipedia.org/wiki/Time_complexity).

![time complexity graph](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20220812122843/Logarithmic-time-complexity-blog-1.jpg)

## Approach:

My approach for solving the _push swap_ project, was first to just find out which time complexity the subject requires, which were:

**For `100` random integers => no more than `700` operations**
**For `500` random integers => no more than `5500` operations**

The first idea I tried was just looking at the complexity graph, and giving the amount of numbers to the various time functions. For example:

for 100 numbers, I tried the following:

- **O(n)**			= 100 (less than 700)
- **O(n^2)**		= 10000 (way more than 700)
- **O(n\*log(n))**	= 664 (this is the closest result to 700)

After finding the target complexity, I decided to use the Greedy Turk algorithm to solve it. 

The main idea for the Greedy algorithm is to always choose the optimal cheapest move to take.
The steps for it are as follows:

- Push all the elements from the stack A to stack B, except 3 elements.
- Sort the 3 elements with a hard coded algorithm.
- for each element in stack B calculate the cost to get it in its sorted position.
- choose the cheapest items from stack B, rotate it to the top along with its position in stack A.
- then push it to stack A.
- repeat the cost calculation and push operation until B is empty.
- rotate stack A so that the smallest element is on top of the stack.

However after implementing the algorithm, it was breaching the limit for 500 numbers.
I found out the main bottleneck was the first step of pushing all the elements but 3 to stack B.

I then found out about the **Chunks** algorithm, which was used to optimize the step of pushing all elements to stack B.
which made the stack B roughly sorted in a way that the Greedy algorithm could benefit from.

The first step from the Greedy algorithm was changed to be the following:

- rank all the numbers from smallest to largest (smallest gets a rank of 0, largest gets a rank of n-1)
- As long as stack A has more than 3 elements:
	- split the numbers in A into chunks (ex: 16 numbers per chunk)
	- for each chunk, find one of its members in stack A by rotating.
	- push that element to stack B.
	- if that number's rank is less than the len(stack B), rotate stack B once

## Instructions:

### compilation:

To compile the mandatory part (_push_swap_ program), just run:

	make

And to compile the bonus part (_checker_ program), run:

	make bonus

### Additional make rules:

| Rule       | Description                           |
|------------|---------------------------------------|
| **all**    | make the `push_swap` program          |
| **bonus**  | make the `checker` program            |
| **clean**  | remove all the object files           |
| **fclean** | run **clean** and remove the binaries |
| **re**     | run **fclean** and then run **all**   |

### running:

| Program     | Arguments               | Input                                   | Output                                                                   |
|-------------|-------------------------|-----------------------------------------|--------------------------------------------------------------------------|
| `push_swap` | [int1] [int2] .. [intn] | N/a                                     | set of instructions to sort the numbers  if input is valid, else `Error` |
| `checker`   | [int1] [int2] .. [intn] | set of instructions to sort the numbers | `OK` if the stack is sorted, `KO` if not,  else `Error`                  |

#### **push_swap**:
	
- To run the `push_swap` program, you need to give it a set of _non-repeating_ integers (_within the integer range_). 
- The integers can be either one int in one argument, or multiple in one single space-separated arguments.
- Additionally the integers can be preceded by a sign.

**Example:**

	$ ./push_swap 3 5 2 4 1
	pb
	pb
	rra
	pa
	rra
	pa
	rra
	rra


#### **checker**:

- To run the `checker` program, you need to provide the instructions (_usually the output from `push_swap`_) to sort a set of numbers.
- The set of numbers is provided as arguments just like the `push_swap` program.

**Example:**

	$ ARGS="3 5 2 4 1" ; ./push_swap $ARGS | ./checker $ARGS
	OK

## Resources:

The following tools have been helpful during the making of this project:

- **[gdb](https://en.wikipedia.org/wiki/GNU_Debugger)**: the C debugger was of immense importance for finding sneaky bugs.
- **[seq](https://man7.org/linux/man-pages/man1/seq.1.html) command**: for testing purposes the seq command just gives a sequence of numbers, which you can then shuffle using the `shuf` command.
- **[pushswap visualizer](https://push-swap-visualizer.vercel.app/)**: this simple app lets you prototype your ideas quickly. It proved to be useful.

And the following articles were used to get the general idea of the algorithms used:

- [Push_Swap Turk algorithm explained in 6 steps](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)
- [Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
