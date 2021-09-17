# CPSC 120

## Decimal Feet to Feet & Inches

When working with [US Customary Units](https://en.wikipedia.org/wiki/United_States_customary_units), one quickly realizes that they don't work well in decimal. Unlike the [International System of Units](https://en.wikipedia.org/wiki/International_System_of_Units), commonly referred to as the metric system, the US customary units are not base 10. Since they are not expressed in a base 10 counting system having 2.34 feet is really 2 feet 4 inches (2'4") and 3.6 feet is 3 feet 7 and 1/8 inches.

We are interested in doing a little arts & crafts at home and we've made measurements of a project that we're going to build out of wood. Using our handy dandy [TI calculator](https://en.wikipedia.org/wiki/Comparison_of_Texas_Instruments_graphing_calculators), we've marked up our plans with very precise measurements out to seven decimal places!

Regrettably, our tape measure and ruler only go to eighths of inches or 0.125 inches. We need to write a program that can convert our measurements in decimal to feet, inches, and eighths of inches. ([What's the difference between a carpenter and a woodworker?](.answer.md))

The challenge here is that if you have a number like 123.45, how do you separate the fractional part (0.45) from the integer part (123)?

A very poor way to do this is to somehow truncate (cut) the decimal number 123.45 to just 123 and then subtract 123 from 123.45. For example, in C++ one may write something like this:

```C++
	float decimal_number = 123.45;
	int truncated = static_cast<int>(decimal_number);
	float fractional_part = decimal_number - float(truncated);
```

Remember the types must always match. Look at each line with an assignment operator ('='). Notice that the type on the left hand side matches the type on the right hand side.

This approach to change a decimal number to an integer is not a very good way strategy for many reasons. (Can you think of one reason?) However for this exercise, you may use this approach if you can't think of a better way to separate out the integer part from the fractional part. (What would happen if `decimal_number` was a very, very large number; would the casting to an `int` type work as we expect?)

Once you have the two parts separated, you can figure out how many inches there are because you know that there are 12 inches to every foot. Given our example, 12 × 0.45 is 5.4 inches. Again, we have to separate out the integer part from the fractional part to find out how many eighths of an inch there are. We know there are 8 eighths of an inch in every inch so 0.4 × 8 is 3.2 eighths of an inch.

Since our tape measure and ruler can't go any finer than an eighth of an inch, we can safely discard any remaining fractional portion.

Thus given our example of 123.45 feet, we can calculate that there are 123 feet, 5 and 3/8 inches.

## Requirements

Use the conversions of 12 inches to every foot and 8 eighth of an inch in every inch.

Perform your calculations using floating point and integer types where needed.

You shall use [cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal and you shall use [cin](https://en.cppreference.com/w/cpp/io/cin) to read in values from the keyboard.

The program reads in one floating point value from the terminal, uses as many variables need to convert the floating point value into a feet, inches, and eights of inches. The program prints out a message summarizing the data and the resulting calculation.

The program must work reliably with positive and negative values. The output should be formatted to only display one negative sign should the resulting measurement be a negative value.

The starting code defines a series of `TODO` comments which you can use to formulate your plan and develop your program.

Write your program progressively. Compile your program often and check that you're making progress. Make sure your program behaves the way you expect.

The output of your program must match the output given in the section Example Output below.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:

* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* lint: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* header: check to make sure your files have the appropriate header
* test: run tests to help you verify your program is meeting the assignment's requirements. This does not grade your assignment.

## Don't Forget

Please remember that:

- You need to put a header in every file.
- You need to follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Remove the `TODO` comments.

## Testing Your Code

Computers only ever do exactly what they are told, exactly the way they are told it, and never anything else. Testing is an important process to writing a program. You need to test for the program to behave correctly and test that the program behaves incorrectly in a predictable way.

As programmers we have to remember that there are a lot of ways that we can write the wrong program and only one to a few ways to write the correct program. We have to be aware of [cognitive biases](https://en.wikipedia.org/wiki/List_of_cognitive_biases) that we may exercise that lead us to believe we have correctly completed our program. That belief may be incorrect and our software may have errors. [Errors in software](https://www.wired.com/2005/11/historys-worst-software-bugs/) may lead to loss of [life](https://www.nytimes.com/2019/03/14/business/boeing-737-software-update.html), [property](https://en.wikipedia.org/wiki/Mariner_1), [reputation](https://en.wikipedia.org/wiki/Pentium_FDIV_bug), or [all of the above](https://en.wikipedia.org/wiki/2009%E2%80%9311_Toyota_vehicle_recalls).

### Test strategy

Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

## Example Output

Please ensure your program's output is identical to the example below.

```
$ make
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14  -D AMD64 decimal_feet_to_feet_inch.cc \
| sed 's/\(decimal_feet_to_feet_inch\)\.o[ :]*/\1.o decimal_feet_to_feet_inch.d : /g' > decimal_feet_to_feet_inch.d; \
[ -s decimal_feet_to_feet_inch.d ] || rm -f decimal_feet_to_feet_inch.d
clang++ -g -O3 -Wall -pipe -std=c++14  -D AMD64 -c decimal_feet_to_feet_inch.cc
clang++ -g -O3 -Wall -pipe -std=c++14  -o decimal_feet_to_feet_inch decimal_feet_to_feet_inch.o 
$ ./decimal_feet_to_feet_inch 
Enter the number of feet you wish to convert to feet-inch: 0
0 feet is 0 feet, 0 inches
$ ./decimal_feet_to_feet_inch 
Enter the number of feet you wish to convert to feet-inch: -7.5
7.5 feet is -7 feet, 6 inches
$ ./decimal_feet_to_feet_inch 
Enter the number of feet you wish to convert to feet-inch: 123.45
123.45 feet is 123 feet, 5 and 3/8 inches
$ ./decimal_feet_to_feet_inch 
Enter the number of feet you wish to convert to feet-inch: 4.3
4.3 feet is 4 feet, 3 and 4/8 inches
```

