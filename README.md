# Push Swap

This project has been created as part of the 42 curriculum by `atahiri-`.

## Description:

**Push Swap** is a program about sorting a stack, it explores variable length [data-structures](https://en.wikipedia.org/wiki/Data_structure) such as queues, and [time complexity](https://en.wikipedia.org/wiki/Time_complexity).

![time complexity graph](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20220812122843/Logarithmic-time-complexity-blog-1.jpg)

## Instructions:

### compilation:

To compile the mandatory part (_push_swap_ program), just run:

	make

And to compile the bonus part (_checker_ program), run:

	make bonus

### running:

| program     | arguments        | input                                   | output                                                                   |
|-------------|------------------|-----------------------------------------|--------------------------------------------------------------------------|
| `push_swap` | [int1] [int2] .. | N/a                                     | set of instructions to sort the numbers  if input is valid, else `Error` |
| `checker`   | [int1] [int2] .. | set of instructions to sort the numbers | `OK` if the stack is sorted, `KO` if not,  else `Error`                  |

#### **push_swap**:
	
- To run the `push_swap` program, you need to give it a set of _non-repeating_ integers (_within the integer range_). 
- The integest can be either one int in one argument, or multiple in one single space separated arguments.
- Additionaly the integers can be preceeded by a sign.

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
- The set of numbers is provided as agruments just like the `push_swap` program.

**Example:**

	$ ARGS="3 5 2 4 1" ; ./push_swap $ARGS | ./checker $ARGS
	OK

## Resources:

# TODO:

[ ]: reset the 42 header so it includes your username
[ ]: delete the checker linux file
[ ]: remove the -g flag
[ ]: make the checker validate then apply the operation for stone heads
