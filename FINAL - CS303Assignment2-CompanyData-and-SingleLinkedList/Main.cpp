#include <iostream>
#include "SingleLinkedList.h"
#include "CompanyData.h"

using namespace std;

int main() {

	singleLinkedList testList;

	testList.empty();

	testList.list();
	testList.push_back(5);
	testList.push_back(12);
	testList.push_back(32);
	testList.push_back(400);
	testList.push_back(8);
	testList.display();

	testList.push_front(87);
	testList.push_front(2);
	testList.push_front(9);
	testList.push_front(0);
	testList.display();

	testList.empty();

	testList.front();
	testList.back();

	testList.pop_front();
	testList.pop_front();
	testList.pop_back();

	testList.display();

	testList.insert(1, 3);

	testList.display();

	testList.insert(12, 24);

	testList.display();

	testList.remove(4);
	
	testList.display();

	testList.remove(41);

	testList.display();

	testList.find(400);
	testList.find(2);
	testList.find(1000);

	cout << endl << endl << endl << endl;


	CompanyData employeeList;

	employeeList.Employee();

	employeeList.pEmployee("Anderson, Eric", 40);
	employeeList.npEmployee("Shrider, Dave", 20);
	employeeList.pEmployee("Evan, Angelica", 45);
	employeeList.npEmployee("Peterson, Ruth", 15);
	employeeList.npEmployee("Kyle, Kyle", 2);
	employeeList.pEmployee("Foster, Kelly", 60);

	employeeList.CalculateWeeklySalary();
	employeeList.CalculateVacationDays();
	employeeList.CalculateInsurance();

	employeeList.printData();


	return 0;
}