/*
Program name: ProductionWorker.cpp
Programmer: Tyler Davies
Date: 9-25-21
Version: 1.0
Description: This program contains two classes, and tests the class named ProductionWorker which is 
             derived from the Employee class. The main creates instances of the class, and inputs
             values from the user to print out a report.
*/

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//This class holds an employee's name, number, and hire date.
class Employee
{
private:
    string employeeName, hireDate;
    int employeeNum;
public:
    Employee();
    Employee(string, int, string);

    void setName(string name)
        { employeeName = name; }

    void setHireDate(string date)
        { hireDate = date; }

    void setEmployeeNum(int num)
        { employeeNum = num; }

    string getEmployeeName()
        { return employeeName; }

    int getEmployeeNum()
        { return employeeNum; }
    
    string getHireDate()
        { return hireDate; }
};

//Default constructor.
Employee::Employee()
{
    employeeName = " ";
    employeeNum = 0;
    hireDate = " ";
}

//Overloaded constructor.
Employee::Employee(string name, int num, string date)
{
    employeeName = name;
    employeeNum = num;
    hireDate = date;
}

//This class is derived from the Employee class. It also holds values determining the shift type and pay.
class ProductionWorker : public Employee
{
private:
    int shift;  //1 for day shift; 2 for night shift.
    double hourlyPay;
public:
    ProductionWorker();
    void print();

    void setShift(int s)
        { shift = s; }

    void setHourlyPay(double pay)
        { hourlyPay = pay; }

    int getShift()
        { return shift; }

    double getHourlyPay()
        { return hourlyPay; }
};

//Default constructor.
ProductionWorker::ProductionWorker() : Employee()
{
    shift = 1;  //Day shift by default.
    hourlyPay = 0.0;
}

//This function prints an employee report.
void ProductionWorker::print()
{
    cout << left << fixed << setprecision(2) << endl;
    cout << setw(20) << "Employee Name: " << getEmployeeName() << endl;
    cout << setw(20) << "Employee Number: " << getEmployeeNum() << endl;
    cout << setw(20) << "Hire Date: " << getHireDate() << endl;
    cout << setw(20) << "Shift: ";

    if (shift == 1)
        cout << "Day" << endl;
    else if (shift == 2)
        cout << "Night" << endl;
    else
        cout << "Error" << endl;

    cout << setw(20) << "Hourly Pay Rate: " << hourlyPay << endl;
}

//This main function instantiates a ProductionWorker object, and prompts the user for the employee's
//details which are stored in the object. It them uses the object's print function to print a report.
int main()
{
    string name, date;
    int num, shift;
    double pay;
    ProductionWorker employee;

    cout << "Enter employee name: " << endl;
    getline(cin, name);
    employee.setName(name);

    cout << "Enter employee number: " << endl;
    cin >> num;
    employee.setEmployeeNum(num);

    cout << "Enter hire date: " << endl;
    cin >> date;
    employee.setHireDate(date);

    cout << "Enter shift (1) for day and (2) for night: " << endl;
    cin >> shift;
    employee.setShift(shift);

    cout << "Enter hourly pay rate: " << endl;
    cin >> pay;
    employee.setHourlyPay(pay);

    employee.print();

    exit(0);
}