
/// Program to calculate the BMR of a person using the Mifflin St Jeor equation.

#include <cmath>
#include <iostream>

using namespace std;

/// Main function - the entry point to our program, it does not take command
/// line arguments
int main(int argc, char const *argv[]) {
  // TODO: Define a constant of type float with the name kInchesToCentimeters
  // which is assigned the value 2.54
  // TODO: Define a constant of type float with the name kPoundsToKilograms
  // which is assigned the value 0.4535

  cout << "This program estimates the basal metabolic rate\n";
  cout << "using the Mifflin St Jeor Equation.\n";

  cout << "Please enter the subject's sex.\n";
  cout << "Please enter 'm' for male or 'f' for female: ";
  string sex;
  cin >> sex;

  cout << "You entered '" << sex << "'\n\n";
  bool is_male_flag = false;
  is_male_flag = (sex == "m");

  // TODO: Using cout prompt the computer user for the subject's age in years.

  // TODO: Declare a variable of type int with the name age_years and assign it
  // the value of 0.

  // TODO: Read from the terminal using cin to set a value to age_years

  // TODO: Confirm the value that was entered by printing it back to the
  // terminal using cout.

  // TODO: Using cout, prompt the computer user to select metric units or US
  // customary weights and measures.

  // TODO: Declare a variable named measurement_system of type string. You do
  // not need to initialize strings because they are set to an empty string by
  // default. An empty string is "".

  // TODO: Using cin, read the measurement system (either an "m" or "u") into
  // the variable measurement_system.

  // TODO: Confirm the value that was entered by printing it back to the
  // terminal using cout.

  // TODO: Similar to the is_male_flag, declare a variable of type bool named
  // is_metric_flag and assign the value false

  // TODO: Assign the value of (measurement_system == "m") to is_metric_flag
  // similar to how is_male_flag is assigned (sex == "m").

  // TODO: Declare a variable of type float named height_cm and assign the value
  // NAN to it. Remember integers are assigned 0 and floats are assigned NAN.
  // NAN stands for 'not a number' which represents things like 7 / 0 or the
  // square root of -15.

  // TODO: Using is_metric_flag, write an if/else statement. If is_metric_flag
  // is true then prompt the computer user to enter the subject's height in
  // centimeters. Else, prompt the computer user to input the subject's height
  // in inches, declare a variable of type float named height_inches, assign NAN
  // to height_inches, and read in the value from the terminal. Immediately
  // convert the inches into centimeters and store that in height_cm. Remember,
  // the computer user may enter inches but everything inside the program is in
  // centimeters. Convert between inches and centimeters by multiplying the
  // inches by kInchesToCentimeters.

  // TODO: Declare a variable of type float named mass_kg and assign the value
  // NAN to it. Remember integers are assigned 0 and floats are assigned NAN.
  // NAN stands for 'not a number' which represents things like 7 / 0 or the
  // square root of -15.

  // TODO: Using is_metric_flag, write an if/else statement. If is_metric_flag
  // is true then prompt the computer user to enter the subject's weight in
  // kilograms (kg). Else, prompt the computer user to input the subject's
  // weight in poounds, declare a variable of type float named mass_pounds,
  // assign NAN to mass_pounds, and read in the value from the terminal.
  // Immediately convert the pounds into kilograms and store that in mass_kg.
  // Remember, the computer user may enter pounds but everything inside the
  // program is in kilograms. Convert between pounds and kilograms by
  // multiplying the pounds by kPoundsToKilograms.

  // TODO: Declare a variable of type float named magic_s and assign the value
  // NAN to it. Remember integers are assigned 0 and floats are assigned NAN.
  // NAN stands for 'not a number' which represents things like 7 / 0 or the
  // square root of -15.

  // TODO: Using is_male_flag, write an if/else statement. If is_male_flag is
  // true then assign magic_s to 5.0. Else, assign magic_s to -161.0.

  // TODO: Declare a variable of type float named bmr and assign the value NAN
  // to it. Remember integers are assigned 0 and floats are assigned NAN. NAN
  // stands for 'not a number' which represents things like 7 / 0 or the square
  // root of -15.

  // TODO: Calculate the BMR using the formula given in the README.md and assign
  // the result to the variable bmr. Remember that age_years is an int so it
  // must be converted to a float using the float constructor.

  // TODO: Declare a variable named sex_string of type string. You do not need
  // to initialize strings because they are set to an empty string by default.
  // An empty string is "".

  // TODO: Using is_male_flag, write an if/else statement. If is_male_flag is
  // true then assign sex_string "male". Else, assign sex_string "female".

  // TODO: Declare a variable named pronoun of type string. You do not need to
  // initialize strings because they are set to an empty string by default. An
  // empty string is "".

  // TODO: Using is_male_flag, write an if/else statement. If is_male_flag is
  // true then assign pronoun "He". Else, assign pronoun "She".

  // TODO: Summarize the data that was given to the program. Remember that we
  // need to have the sex_string, age_years, height_cm, and mass_kg variables.
  // For example, "Given the details of the male subject of 30 years of age,
  // with a height of 177.8 cm and a weight of 78.909 kg..."

  // TODO: Summarize the outcome of the caluclation by printing the pronoun and
  // the BMR of the subject. For example, "She has a BMR of 1315.25 kcal per
  // day."

  return 0;
}
