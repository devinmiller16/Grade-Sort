#pragma once
#include<string>
#include<vector>
#include<iostream>

class student {
public:
	void addGrade(int grade);
	void sortGrade();
	void averageGrade();
	void lowestGrade();
	void highestGrade();
	void getNumGrades();
	void printData();
	student(std::string, std::string);
private:
	std::vector<int> grades;
	std::string name;
	std::string cName;
};