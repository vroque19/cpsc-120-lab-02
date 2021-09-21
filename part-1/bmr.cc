// Vanessa Roque
// CPSC 120-19
// 2021-09-20
// vroque19@csu.fullerton.edu
// @vroque19
//
// Lab 00-02
//
// This is a program to calculate the BMR of a person using the Mifflin St Jeor equation.

#include <cmath>
#include <iostream>

using namespace std;

/// Main function - the entry point to our program, it does not take command
/// line arguments
int main(int argc, char const *argv[]) {
  // Define a constant of type float with the name kInchesToCentimeters
  // which is assigned the value 2.54
  // Define a constant of type float with the name kPoundsToKilograms
  // which is assigned the value 0.4535
const float kInchesToCentimeters = 2.54;
  cout << "This program estimates the basal metabolic rate\n";
  cout << "using the Mifflin St Jeor Equation.\n";
const float kPoundsToKilograms = 0.4535;
  cout << "Please enter the subject's sex.\n";
  cout << "Please enter 'm' for male or 'f' for female: ";
  string sex;
  cin >> sex;

  cout << "You entered '" << sex << "'\n\n";
  bool is_male_flag = false;
  is_male_flag = (sex == "m");

  // Using cout prompt the computer user for the subject's age in years.
cout << "Please enter the subject's age in years (no decimal point please): ";
  // Declare a variable of type int with the name age_years and assign it
  // the value of 0.
int age_years = 0;
  // Read from the terminal using cin to set a value to age_years
cin >> age_years;
  // TODO: Confirm the value that was entered by printing it back to the
  // terminal using cout.
cout << "You entered '" << age_years << "'\n\n";
  // Using cout, prompt the computer user to select metric units or US
  // customary weights and measures.
cout << "Would you like to enter the subject's height and weight \n";
cout << "in metric units (kg & cm) or U.S. customary units (in & lbs)?\n";
cout << "Enter 'm' for metric and 'u' for U.S.:";
  // Declare a variable named measurement_system of type string. You do
  // not need to initialize strings because they are set to an empty string by
  // default. An empty string is "".
string measurement_system = "";
  // Using cin, read the measurement system (either an "m" or "u") into
  // the variable measurement_system.
cin >> measurement_system;
  // Confirm the value that was entered by printing it back to the
  // terminal using cout.
cout << "You entered '" << measurement_system << "'.\n";
  // Similar to the is_male_flag, declare a variable of type bool named
  // is_metric_flag and assign the value false
bool is_metric_flag = false;
  // Assign the value of (measurement_system == "m") to is_metric_flag
  // similar to how is_male_flag is assigned (sex == "m").
is_metric_flag = (measurement_system == "m");
  // Declare a variable of type float named height_cm and assign the value
  // NAN to it. Remember integers are assigned 0 and floats are assigned NAN.
  // NAN stands for 'not a number' which represents things like 7 / 0 or the
  // square root of -15.
float height_cm = NAN;
  // Using is_metric_flag, write an if/else statement. If is_metric_flag
  // is true then prompt the computer user to enter the subject's height in
  // centimeters. Else, prompt the computer user to input the subject's height
  // in inches, declare a variable of type float named height_inches, assign NAN
  // to height_inches, and read in the value from the terminal. Immediately
  // convert the inches into centimeters and store that in height_cm. Remember,
  // the computer user may enter inches but everything inside the program is in
  // centimeters. Convert between inches and centimeters by multiplying the
  // inches by kInchesToCentimeters.
if (is_metric_flag == true) {
  cout << "Enter the subject's height in cm.";
} else {
  cout << "Enter the subject's height in inches.\n";
}
  // Declare a variable of type float named mass_kg and assign the value
  // NAN to it. Remember integers are assigned 0 and floats are assigned NAN.
  // NAN stands for 'not a number' which represents things like 7 / 0 or the
  // square root of -15.
float mass_kg = NAN;
  // Using is_metric_flag, write an if/else statement. If is_metric_flag
  // is true then prompt the computer user to enter the subject's weight in
  // kilograms (kg). Else, prompt the computer user to input the subject's
  // weight in poounds, declare a variable of type float named mass_pounds,
  // assign NAN to mass_pounds, and read in the value from the terminal.
  // Immediately convert the pounds into kilograms and store that in mass_kg.
  // Remember, the computer user may enter pounds but everything inside the
  // program is in kilograms. Convert between pounds and kilograms by
  // multiplying the pounds by kPoundsToKilograms.
if (is_metric_flag == true) {
  cout << "Please enter the subject's weight in kilograms.\n";
} else {
  cout << "Please enter the subject's weight in pounds";
}
float mass_pounds = NAN;
cout << "mass_pounds";
mass_kg = (mass_pounds * kPoundsToKilograms);
  // Declare a variable of type float named magic_s and assign the value
  // NAN to it. Remember integers are assigned 0 and floats are assigned NAN.
  // NAN stands for 'not a number' which represents things like 7 / 0 or the
  // square root of -15.
float magic_s = NAN;
  // Using is_male_flag, write an if/else statement. If is_male_flag is
  // true then assign magic_s to 5.0. Else, assign magic_s to -161.0.
if (is_male_flag == true) {
  magic_s = 5.0;
} else {
  magic_s = -161.0;
}
  // TODO: Declare a variable of type float named bmr and assign the value NAN
  // to it. Remember integers are assigned 0 and floats are assigned NAN. NAN
  // stands for 'not a number' which represents things like 7 / 0 or the square
  // root of -15.
float bmr = NAN;
  // Calculate the BMR using the formula given in the README.md and assign
  // the result to the variable bmr. Remember that age_years is an int so it
  // must be converted to a float using the float constructor.
bmr = ((10 * mass_kg)+(6.25 * height_cm)-(5 * age_years));
  // Declare a variable named sex_string of type string. You do not need
  // to initialize strings because they are set to an empty string by default.
  // An empty string is "".
string sex_string = "";
  // Using is_male_flag, write an if/else statement. If is_male_flag is
  // true then assign sex_string "male". Else, assign sex_string "female".
if (is_male_flag == true) {
  sex_string = "male";
} else {
  sex_string = "female";
}
  // Declare a variable named pronoun of type string. You do not need to
  // initialize strings because they are set to an empty string by default. An
  // empty string is "".
string pronoun = "";
  // Using is_male_flag, write an if/else statement. If is_male_flag is
  // true then assign pronoun "He". Else, assign pronoun "She".
if (is_male_flag == true) {
  pronoun = "He";
} else {
    pronoun = "She";
  }

  // Summarize the data that was given to the program. Remember that we
  // need to have the sex_string, age_years, height_cm, and mass_kg variables.
  // For example, "Given the details of the male subject of 30 years of age,
  // with a height of 177.8 cm and a weight of 78.909 kg..."
cout << "Given the details" <<sex_string<< " of " <<age_years<< " years of age";
cout << ", " <<height_cm<< " and a weight of " <<mass_kg<< "." ;
  // Summarize the outcome of the caluclation by printing the pronoun and
  // the BMR of the subject. For example, "She has a BMR of 1315.25 kcal per
  // day."
cout << "" <<pronoun<< " has a BMR of " <<bmr<< "kcal per day.";
  return 0;
}
