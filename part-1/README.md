# CPSC 120

## Basal Metabolic Rate or BMR

Ever wonder how much energy you burn just laying there breathing? You can estimate how much energy your body uses doing nothing by calculating your [Basel Metabolic Rate](https://en.wikipedia.org/wiki/Basal_metabolic_rate). In this exercise, we'll write a program which uses the the Mifflin St Jeor equation to estimate a subject's BMR.

Our test subject shall have their sex, age, height, and weight recorded and subsequently used to calculate their BMR. Their BMR is given in kilocalories. In everyday conversation, we refer to kilocalories as calories.

## Requirements

The BMR calculation must use the Mifflin St Jeor equation. The Mifflin St Jeor equation is ![P=\left( \frac{10.0m}{1 \textrm{ kg}} + \frac{6.25h}{1 \textrm{ cm}} - \frac{5.0a}{1 \textrm{ year}} + s \right) \frac{\textrm{kcal}}{\textrm{day}}](https://render.githubusercontent.com/render/math?math=P%3D%5Cleft%28%20%5Cfrac%7B10.0m%7D%7B1%20%5Ctextrm%7B%20kg%7D%7D%20%2B%20%5Cfrac%7B6.25h%7D%7B1%20%5Ctextrm%7B%20cm%7D%7D%20-%20%5Cfrac%7B5.0a%7D%7B1%20%5Ctextrm%7B%20year%7D%7D%20%2B%20s%20%5Cright%29%20%5Cfrac%7B%5Ctextrm%7Bkcal%7D%7D%7B%5Ctextrm%7Bday%7D%7D), where _m_ is mass measured in kilograms, _h_ is height measured in centimeters, and _a_ is age measured in years. The variable _s_ is +5 for males and -161 for females.

Bear in mind that this calculation is an estimate. There are many [factors that must be considered to accurately estimate a person's BMR](https://en.wikipedia.org/wiki/Basal_metabolic_rate#Causes_of_individual_differences_in_BMR) such as daily activity level and general health. 

Write a program that prompts the computer user to enter the details of the subject being considered. Provide the option to input the data values in [metric units](https://en.wikipedia.org/wiki/Metric_system) (kilograms, centimeters, and years) or in [U.S. customary units](https://en.wikipedia.org/wiki/United_States_customary_units) (pounds, inches, and years).

In order to convert units, standardize the logic of your program to use metric units. Estimate the metric equivalent of the U.S. customary units by using the following ratios for conversion.
* 1 pound is approximately 0.4535 kilograms (or 1 kilogram is approximately 2.205 pounds)
* 1 inch is approximately 2.54 centimeters (or 1 centimeter is approximately 0.3937 inches)
* 1 metric year is approximately 1 U.S. year (thank heavens!)

You shall use [cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal and you shall use [cin](https://en.cppreference.com/w/cpp/io/cin) to read in values from the keyboard.

The program reads in five values from the terminal, stores them in at least five different variables and then prints out a message summarizing the data and the resulting BMR calculation.

A mixture of different types must be used in this program. Many of the numeric values are decimal numbers so `float` or `double` types must be used. In other cases, the value may be stored as an `int`. Be mindful of how you perform your calculations.

Input from the keyboard that requires letters shall be stored as strings. Do not use `char`.

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
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14  -D AMD64 bmr.cc \
| sed 's/\(bmr\)\.o[ :]*/\1.o bmr.d : /g' > bmr.d; \
[ -s bmr.d ] || rm -f bmr.d
clang++ -g -O3 -Wall -pipe -std=c++14  -D AMD64 -c bmr.cc
clang++ -g -O3 -Wall -pipe -std=c++14  -o bmr bmr.o 
$ ./bmr
This program estimates the basal metabolic rate
using the Mifflin St Jeor Equation.
Please enter the subject's sex.
Please enter 'm' for male or 'f' for female: f
You entered 'f'

Please enter the subject's age in years (no decimal point please): 23
You entered 23 years old.

Would you like to enter the subject's height and weight
in metric units (kg & cm) or U.S. customary units (in, lbs)?
Enter 'm' for metric and 'u' for U.S.: u
You entered 'u'.

Please enter height in inches, decimal points are OK: 63
Please enter weight in pounds, decimal points are OK: 120


Given the details of the female subject of 23 years of age,
with a height of 160.02 cm and a weight of 54.42 kg...
She has a BMR of 1268.32 kcal per day.
$ ./bmr
This program estimates the basal metabolic rate
using the Mifflin St Jeor Equation.
Please enter the subject's sex.
Please enter 'm' for male or 'f' for female: m
You entered 'm'

Please enter the subject's age in years (no decimal point please): 30
You entered 30 years old.

Would you like to enter the subject's height and weight
in metric units (kg & cm) or U.S. customary units (in, lbs)?
Enter 'm' for metric and 'u' for U.S.: u
You entered 'u'.

Please enter height in inches, decimal points are OK: 70
Please enter weight in pounds, decimal points are OK: 174


Given the details of the male subject of 30 years of age,
with a height of 177.8 cm and a weight of 78.909 kg...
He has a BMR of 1755.34 kcal per day.
$ ./bmr
This program estimates the basal metabolic rate
using the Mifflin St Jeor Equation.
Please enter the subject's sex.
Please enter 'm' for male or 'f' for female: f
You entered 'f'

Please enter the subject's age in years (no decimal point please): 30
You entered 30 years old.

Would you like to enter the subject's height and weight
in metric units (kg & cm) or U.S. customary units (in, lbs)?
Enter 'm' for metric and 'u' for U.S.: m
You entered 'm'.

Please enter height in centimeters, decimal points are OK: 173.4
Please enter weight in kilograms, decimal points are OK: 54.25


Given the details of the female subject of 30 years of age,
with a height of 173.4 cm and a weight of 54.25 kg...
She has a BMR of 1315.25 kcal per day.
```

