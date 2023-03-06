#pragma once
#include "SingleLinkedList.h"
#include <iostream>

using namespace std;


class CompanyData {
	public:
		void Employee();												//initializer class
		void npEmployee(string name, double hoursWorked);				//nonprofessional employee
		void pEmployee(string name, double hoursWorked);				//professional employee

		void CalculateWeeklySalary();									//calculates the weekly salary of the list
		void CalculateVacationDays();									//calculates the vacation time of the list
		void CalculateInsurance();										//calculates the insurance contribution of the list

		const void printData();

	private:

		struct DataNode {												//these are ONLY initialized here because it decided to keep throwing a warning that they weren't initialized
			string employeeName = " ";
			double hoursWorked = 0.00;
			bool professional = false;
			DataNode *nextEmployee;
			double pay = 0.00;
			double vacationDays = 0.00;
			double vacationHours = 0.00;
			double insuranceContribut = 0.00;
			int IDnum = 0;
		};

		DataNode* head;
		DataNode* tail;

		double monthlySalary;
		double hourlySalary;
		double vacationHoursconvert;
		double healthInsuranceProf;
		double healthInsuranceNonProf;
		int employeeNum;

};