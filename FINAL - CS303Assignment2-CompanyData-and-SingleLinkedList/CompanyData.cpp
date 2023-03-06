#include "CompanyData.h"
#include <iostream>
#include <iomanip>

using namespace std;

void CompanyData::Employee() {									//initializer class
	head = NULL;
	tail = NULL;
	monthlySalary = 4813;										//flat salary for professional employees
	hourlySalary = 14.50;
	vacationHoursconvert = 0.1;									//conversion variable for vacation hours
	healthInsuranceProf = 0.14;
	healthInsuranceNonProf = 0.05;
	employeeNum = 0;

}

void CompanyData::npEmployee(string name, double hours) {		//nonprofessional employee addition
	DataNode* tempNode = new DataNode;
	tempNode->employeeName = name;								//assign name and other such values
	tempNode->hoursWorked = hours;
	tempNode->nextEmployee = NULL;								//place at the end of the list
	tempNode->professional = false;								//note that the employee is not a professional employee
	if (head == NULL) {											//addition if the list is empty
		tempNode->IDnum = 0;
		head = tempNode;
		tail = tempNode;
		tempNode = NULL;
	}
	else {														//addition if the list is NOT empty
		tempNode->IDnum = employeeNum;
		tail->nextEmployee = tempNode;
		tail = tempNode;
	}
	employeeNum += 1;											//iterate the employee number
}

void CompanyData::pEmployee(string name, double hours) {		//professional employee addition
	DataNode* tempNode = new DataNode;
	tempNode->employeeName = name;								//assign necessary values
	tempNode->hoursWorked = hours;
	tempNode->nextEmployee = NULL;								//set at the end of the list
	tempNode->professional = true;								//note that the employee is a professional employee
	if (head == NULL) {											//addition if the list is empty
		tempNode->IDnum = 0;
		head = tempNode;
		tail = tempNode;
		tempNode = NULL;
	}
	else {														//addition if the list is NOT empty
		tempNode->IDnum = employeeNum;
		tail->nextEmployee = tempNode;
		tail = tempNode;
	}
	employeeNum += 1;											//iterate the employee number
}

void CompanyData::CalculateWeeklySalary() {						//calculates weekly salary
	DataNode* previous = new DataNode;							//created for iteration
	DataNode* current = new DataNode;
	double weeklySalary;										//stores salary calculations
	current = head;												//start at the beginning

	for (int i = 0; i < employeeNum; i++) {						//loop through the list using the employee number as the index max
		if (current->professional != true) {					//calculates weekly salary for nonprofessional employees
			weeklySalary = current->hoursWorked * hourlySalary;
			current->pay = weeklySalary;
		}
		else if (current->professional == true) {				//sets the pay of the current node to the default monthly salary
			current->pay = monthlySalary;
		}
		else {													//error message if something goes wrong
			cout << "We can't figure out what went wrong but something went wrong. Check your list!" << endl;
		}
		previous = current;
		current = current->nextEmployee;
	}

}

void CompanyData::CalculateVacationDays() {						//calculates the vacation days/hours
	DataNode* previous = new DataNode;							//created for iteration
	DataNode* current = new DataNode;
	current = head;												//start at the beginning
	double vacHours;											//stores the vacation hours variable

	for (int i = 0; i < employeeNum; i++) {						//iterate through the list using the employee number as the max index
		if (current->professional == true) {					//if the employee is a professional set their vacation days to a flat 10
			current->vacationDays = 10;
			current->vacationHours = 0;
		}
		else if (current->professional == false) {				//if the employee is a nonprofessional set their vacation hours as their hours worked times the vacation hours conversion
			vacHours = current->hoursWorked * vacationHoursconvert;
			current->vacationHours = vacHours;
			current->vacationDays = 0;
		}
		previous = current;
		current = current->nextEmployee;
	}
}

void CompanyData::CalculateInsurance() {						//calculates the insurance that an employee pays per month
	DataNode* previous = new DataNode;							//created for iteration
	DataNode* current = new DataNode;
	current = head;												//start at the top of the list
	double insur;												//holds the insurance contribution value

	for (int i = 0; i < employeeNum; i++) {						//iterates through the list using the employee number as the max index
		if (current->professional == true) {					//uses the professional conversion variable to calculate
			insur = current->hoursWorked * healthInsuranceProf;
			current->insuranceContribut = insur;
		}
		else if (current->professional == false) {				//uses the nonprofessional conversion variable to calculate
			insur = current->hoursWorked * healthInsuranceNonProf;
			current->insuranceContribut = insur;
		}
		previous = current;
		current = current->nextEmployee;
	}
}

const void CompanyData::printData() {
	DataNode* temp = new DataNode;
	temp = head;										//start at the beginning

	cout << fixed << setprecision(2);					//setting the decimal value to 2
	cout << left << setw(10) << "ID" << left << setw(25) << "Employee Name" << left
		<< setw(25) << "Professional Status" << left << setw(20) << "Hours Worked"
		<< left << setw(10) << "Salary" << left << setw(20) << "Vacation Time" << left
		<< setw(30) << "Monthly Insurance Contribution" << endl;

	while (temp != NULL)								//break when you hit the end, tail is 'NULL'
	{
		if (temp->professional == true) {				//spreadsheet-style output, '1' in the professional column
			cout << left << setw(10) << temp->IDnum << left << setw(25) << temp->employeeName
				<< left << setw(25) << temp->professional << left << setw(20) << temp->hoursWorked
				<< left << setw(10) << temp->pay << left << setw(10) << temp->vacationDays
				<< left << setw(15) << "days" << left << setw(30) << temp->insuranceContribut << endl;
		}
		else if (temp->professional == false) {			//spreadsheet-style output, '0' in the professional column
			cout << left << setw(10) << temp->IDnum << left << setw(25) << temp->employeeName
				<< left << setw(25) << temp->professional << left << setw(20) << temp->hoursWorked
				<< left << setw(10) << temp->pay << left << setw(10) << temp->vacationHours
				<< left << setw(15) << "hours" << left << setw(30) << temp->insuranceContribut << endl;
		}
		temp = temp->nextEmployee;
	}

}