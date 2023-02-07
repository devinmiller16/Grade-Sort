//<Programming Assignment 3> -- Sorts and computes data involving a students grades
//CSIS 112-<D01>
//<Citations if necessary> -- Sorting algorithm help from Karthikeye Boyini (https://www.tutorialspoint.com/sorting-a-vector-in-cplusplus).
//highest and lowest grade algorithm help from Juhi Kamdar (https://www.studymite.com/cpp/examples/finding-maximum-and-minimum-number-in-array-in-cpp/).
//Example code used from C++ Programming Assignment Instructions by Terri Sipantzi.
#include<iostream>
#include "StudentGrades.h"
#include<fstream>

using namespace std;

void errorCheck(string);
void nameCheck(string);
void gradeCheck(ifstream&, int, student, bool);

int main()
{
	cout << "Devin Miller - Assignemnt 3" << endl << endl;
	
	string fileName; 
	string studentName;
 	string className;
	
	
	cout << "Enter the name of the file you want to open: " << endl;
	getline(cin, fileName); //Name of the file is stored in fileName.
	
	ifstream infile;
	infile.open(fileName);

	if (!infile.is_open()) //Checks to see if the file is open.
	{
		cout << "ERROR! failed to open file. " << endl;
	}
	
	int grade{ 0 }; //Holds the number read in from the file.
	 //opens the file fileName.
	if (infile.eof()) //Checks to make sure the file isnt empty.
	{
		cout << "The file is empty\n";
		cout << "Exiting program..." << endl;
	}
	if (infile.is_open()) { //Checks if the file is open. 
		getline(infile, studentName); //Stores the first line into studentName.
		nameCheck(studentName); //Passes the students name to the error checking function.
	}

	if (infile.is_open()) { //Checks if the file is open.
		getline(infile, className); //Stores the next line into className.
		errorCheck(className); //Passes the class name to the error checking function.
	}
	
	
	student student1(studentName, className); //Once error checking is complete the student name and class name
											  //is then stored in the private members of the class.
	bool go = false; //Initiates bool to be false.
	gradeCheck(infile, grade, student1, go); //Passes data to check the input validation of the grade then prints the data.
	
	infile.close(); //Close the file.

	system("pause");
	return 0;
 }

//Function to ensure the class name is 8 characters long.
void errorCheck(string className) {
	if (className.size() < 8) //If the class name is less than 8 characters output an error message.
	{
		cout << "ERROR! The class name doesnt contain enough characters. Ex. CSIS 112\n";
		cout << "Exiting program please try again...." << endl;
		system("Pause");
		exit(0);
	}
	else if (className.size() > 8) //If the class is greater than 8 character output an error message.
	{
		cout << "ERROR! The class mame contains too many characters. Ex. CSIS 112\n";
		cout << "Exiting program please try again...." << endl;
		system("pause");
		exit(0);
	}
}

//Function that ensures ther is no numbers in a students name and checks if the file has data.
void nameCheck(string studentName) { 
	if (studentName.size() == 0) //If there is no data in the students name then there is no data in the file
	{							 //and outputs the proper error messge and exit the program.
		cout << "ERROR! There is no data in the file.\n";
		cout << "Exiting program please try again...." << endl;
		system("pause");
		exit(0);
	}
	else if (string::npos != studentName.find_first_of("0123456789")) //If a number is found in the students name then output the proper error message.
	{																  //and exit the program.
		cout << "ERROR! Student name must not include numbers.\n";
		cout << "Exiting program please try agian...." << endl;
		system("pause");
		exit(0);
	}
	else if (studentName.size() < 2)
	{
		cout << "ERROR! The Students name must be more than 1 character.\n";
		cout << "Exiting program please try again....";
		system("pause");
		exit(0);
	}
}

//Function that error checks the grade input and outputs the corresponding error message.
//also invokes the printData function as long as the grade input is valid. 
void gradeCheck(ifstream& infile, int grade, student student1, bool go) 
{
	//Loop that reads in each grade of the file. As long as a numeric value greater than 0 is entered
	//the loop will execute. When a negative or non-numeric value is passed the program exits. When the
	//end of the file is reached the loop outputs a messge. 
	while (!infile.fail() && grade >= 0)
	{
		infile >> grade; //Stores value into grade.

		//If a non-numeric value is found in the file then the program outputs the proper error message
		//and the program exits.
		if (infile.fail() && !infile.eof())
		{
			cout << "A non-numeric value was found in the file .... Exiting program. " << endl;
			system("pause");
			exit(0);
		}

		//If the end of the file is reached then the program outputs the proper error message
		//and the program exits.
		else if (infile.fail() && infile.eof())
		{
			cout << "End of file reached." << endl << endl;
		}

		//If the number is negative then the program outputs the proper error message 
		//and the program exits.
		else if (grade < 0)
		{
			cout << "A negative value was found in the file ... Exiting the program. " << endl;
			system("pause");
			exit(0);
		}

		//Otherwise, output the grade/number that was read in ans stores it into the vector
		else
		{
			cout << "The grade read in was " << grade << endl; 
			student1.addGrade(grade); //Adds the grade into the the vector.
			go = true; //Changes the bool value to true which allows the printData function to run.

		}
	} //end of the while loop
	while (go) //Loop to print the data using the printData function once.
	{
		student1.printData(); //Invokes the printData function from the student class.
		go = false; //Once the data is printed once the bool value changes back to false thus ending the function.
	}
}

