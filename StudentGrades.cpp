#include<iostream>
#include"StudentGrades.h"
#include<string>
#include<algorithm>
#include<numeric>
#include<iomanip>

using namespace std;

//Two argument constructor that stores the names into the private class members.
student::student(string studentName, string className)
{
	name = studentName; //Stores the student name and class name in the private class members.
	cName = className;
}

//Adds each grade to the vector.
void student::addGrade(int grade)
{
	grades.push_back(grade);
}

//Sorts the grade from smallest to largest.
void student::sortGrade()
{
	cout << "The grades for " << name << " - " << cName << " are:" << endl;
	sort(grades.begin(), grades.end());
	for (const auto &i : grades)
		cout << i << ' ' << endl;
}

//Finds the average grade by adding all the data in the vector. 
void student::averageGrade()
{
	float average;
	float sum = accumulate(grades.begin(), grades.end(), 0); //The sum of all data in the vecotr
	average = sum / grades.size(); //Calculates the average grade.
	cout << fixed << showpoint << setprecision(1);
	cout << average << endl;
}

//Calculates the lowest grade using an algorithm
void student::lowestGrade()
{
	int min = grades.at(0); //Assumes the lowest grade is the first object in the vector.
	for (int i = 1; i < grades.size(); i++) //Cycles throught the vector and if a lower grade is found
		if (grades.at(i) < min)				//then it is stored in min.
			min = grades.at(i);
	cout << min << endl;
}

//Calculates the highest grade using an algorithm.
void student::highestGrade()
{
	int max = grades.at(0); //Assumes the highest grade is the first object in the vector.
	for (int i = 1; i < grades.size(); i++) //Cycles through the vector and if a higher gradeis found
		if (grades.at(i) > max)				//then it is stored in max.
			max = grades.at(i);
	cout << max << endl << endl;
}

//Outputs the size of the vector.
void student::getNumGrades()
{
	cout << grades.size();
}

//Prints the data.
void student::printData()
{
	getNumGrades(); //Gets the size of the vector
	cout << " grades were recorded for this course." << endl << endl;
	cout << "Statistics" << endl;
	cout << "Average: " << setw(23);
	averageGrade(); //Gets the average grade
	cout << "Lowest Grade: " << setw(18);
	lowestGrade(); //Gets the lowest grade.
	cout << "Highest Grade: " << setw(17);
	highestGrade(); //gets the highest grade.
	sortGrade(); //Sorts the grades from lowest to highest.
}