/******************************************************************************
# Author:            Ari P.
# Assignment:        Assignment 8
# Date:              June 1, 2025
# Description:       This program will calculate a student's final GPA and
                     letter grade, with assignments being worth 60% and exams
                     being worth 20% each.
# Input:             numScores (int), score (double), midterm (double), final
                     (double)
# Output:            totalScore (double), totalGrade (char)
# Sources:           Assignment 8 specifications, zyBooks reference,
                     cplusplus.com
#*****************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// Declare core functions, which are defined after main()
void Welcome();
int ReadInt(string prompt);
void ReadScore(string prompt, double& score);
double AssignAverage(int numScores);
void GetInput(double& midterm, double& final);
double CalcFinalScore(double average, double midterm, double final);
void CalcLetterGrade(double totalScore, char& totalGrade);
void DisplayResults(double totalScore, char totalGrade);
void Goodbye();

// Declare and initialize constant variables for calculations
const double WEIGHT_ASSIGNMENTS = 0.60;
const double WEIGHT_EXAMS = 0.20;

int main() {
   // Declare variables for input and output
   int numScores = 0;
   double average = 0.0;
   double midterm = 0.0;
   double final = 0.0;
   double totalScore = 0.0;
   char totalGrade = ' ';

   // Set floating point precision to 1 decimal place for output
   cout << fixed << setprecision(1);

   // Print a welcome message
   Welcome();
   cout << endl;

   // Prompt user for the number of assignments they have to enter
   numScores = ReadInt("Enter number of assignments (0 to 10): ");
   // Prompt user for their assignment scores and calculate the average
   average = AssignAverage(numScores);
   cout << endl;
   // Prompt user for their midterm and final exam scores
   GetInput(midterm, final);
   cout << endl;
   
   // Calculate the user's final score and letter grade
   totalScore = CalcFinalScore(average, midterm, final);
   CalcLetterGrade(totalScore, totalGrade);

   // Display results
   DisplayResults(totalScore, totalGrade);
   cout << endl;

   // Print a goodbye message
   Goodbye();
   return 0;
}

// Name:    Welcome()
// Desc:    This function prints a welcome message
// Input:   None
// Output:  Text
// Return:  void
void Welcome() {
   cout << "Welcome to the Final Grade Calculator! Enter scores for up to 10 \
assignments, along with the midterm and final exams. This program will \
calculate your final score and give you a letter grade from A to F." << endl;
}

// Name:    ReadInt()
// Desc:    This function gets an int representing the number of assignments
//          (0 to 10).
// Input:   prompt (string)
// Output:  Prompt
// Return:  numScores (int)
int ReadInt(string prompt) {
   int numScores = 0;
   cout << prompt;
   cin >> numScores;
   // Perform input validation
   while (cin.fail() || numScores < 0 || numScores > 10) {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Invalid option! Please try again." << endl;
      cout << prompt;
      cin >> numScores;
   }
   return numScores;
}

// Name:    ReadScore()
// Desc:    This function gets a double representing an assignment or exam 
//          score (0.0 to 4.0).
// Input:   prompt (string), score (double&)
// Output:  Prompt
// Return:  void
void ReadScore(string prompt, double& score) {
   cout << prompt;
   cin >> score;
   // Perform input validation
   while (cin.fail() || score < 0.0 || score > 4.0) {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Invalid option! Please try again." << endl;
      cout << prompt;
      cin >> score;
   }
}

// Name:    AssignAverage()
// Desc:    This function repeatedly calls ReadScore() until the user has 
//          entered a score for all their assignments. It then gets the average
//          of the scores.
// Input:   numScores (int)
// Output:  Prompt
// Return:  average (double)
double AssignAverage(int numScores) {
   double average = 0.0;
   double score = 0.0;
   string prompt = "";
   // Make sure there's assignments to get grades for
   if (numScores == 0) {
      cout << "You've already failed!" << endl;
      return average;
   }
   cout << endl << "All scores must be 0.0 to 4.0" << endl;
   // Use ReadScore() to get a grade for each assignment
   for (int i = 1; i <= numScores; i++) {
      // Ensure each prompt includes its assignment number
      prompt = "Enter score ";
      prompt.append(to_string(i));
      prompt.append(": ");
      ReadScore(prompt, score);
      average += score;
   }
   // After summing all assignment scores, get the average
   average /= static_cast<double>(numScores);
   return average;
}

// Name:    GetInput()
// Desc:    This function gets the user's midterm and final exam scores
// Input:   midterm (double&), final (double&)
// Output:  prompt
// Return:  void
void GetInput(double& midterm, double& final) {
   ReadScore("Enter midterm exam score: ", midterm);
   ReadScore("Enter final exam score: ", final);
}

// Name:    CalcFinalScore()
// Desc:    This function calculates the user's final GPA
// Input:   average (double), midterm (double), final (double)
// Output:  None
// Return:  totalScore (double)
double CalcFinalScore(double average, double midterm, double final) {
   double totalScore = average * WEIGHT_ASSIGNMENTS;
   totalScore += (midterm * WEIGHT_EXAMS) + (final * WEIGHT_EXAMS);
   return totalScore;
}

// Name:    CalcLetterGrade()
// Desc:    This function determines the user's final letter grade
// Input:   totalScore (double), totalGrade (char)
// Output:  None
// Return:  void
void CalcLetterGrade(double totalScore, char& totalGrade) {
   if (totalScore < 1.2) {
      totalGrade = 'F';
   }
   else if (totalScore < 2.0) {
      totalGrade = 'D';
   }
   else if (totalScore < 2.8) {
      totalGrade = 'C';
   }
   else if (totalScore < 3.3) {
      totalGrade = 'B';
   }
   else if (totalScore <= 4.0) {
      totalGrade = 'A';
   }
}

// Name:    DisplayResults()
// Desc:    This function displays the user's final score and letter grade
// Input:   totalScore (double), totalGrade (char)
// Output:  totalScore (double), totalGrade (char)
// Return:  void
void DisplayResults(double totalScore, char totalGrade) {
   cout << "Your final score is " << totalScore << endl;
   cout << "Your final grade is ";
   // Ensure correct grammar
   if (totalGrade == 'A' || totalGrade == 'F') {
      cout << "an ";
   }
   else {
      cout << "a ";
   }
   cout << totalGrade << endl;
}

// Name:    Goodbye()
// Desc:    This function prints a goodbye message
// Input:   None
// Output:  Text
// Return:  void
void Goodbye() {
   cout << "Thanks for using the Final Grade Calculator." << endl;
}
