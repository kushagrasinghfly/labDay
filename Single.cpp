
#include <iostream>
using namespace std;


class Employee 
{
	public:
	    string name;
	    int id;

	    Employee(string name, int id) 
	    {
		this->name = name;
		this->id = id;
	    }

	    void showDetails() 
	    {
		cout << "Employee Name: " << name << endl;
		cout << "Employee ID: " << id << endl;
	    }
};


class Manager : public Employee 
{
	public:
	    string department;

	    Manager(string name, int id, string department) : Employee(name, id) 
	    {
		this->department = department;
	    }

	    void manage() {
		cout << "Managing the " << department << " department." << endl;
	    }
};

int main() 
{
    Manager manager("Alice", 101, "Sales"); 
    manager.showDetails();   
    manager.manage();        

    return 0;
}






