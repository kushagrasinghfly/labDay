#include <iostream>
using namespace std;


class Employee 
{
	public:
	    string name;
	    int id;

	    Employee(string name, int id) {
		this->name = name;
		this->id = id;
	    }

	    void showDetails() {
		cout << "Employee Name: " << name << endl;
		cout << "Employee ID: " << id << endl;
	    }
};


class Manager : public Employee 
{
	public:
	    Manager(string name, int id) : Employee(name, id) {}

	    void manageTeam() 
	    {
		cout << "Managing a team of employees." << endl;
	    }
};


class TeamLead : public Manager 
{
	public:
	    TeamLead(string name, int id) : Manager(name, id) {}

	    void assignTasks() 
	    {
		cout << "Assigning tasks to the team." << endl;
	    }
};

int main() 
{
    TeamLead lead("Alice", 101); 
    lead.showDetails();          
    lead.manageTeam();           
    lead.assignTasks();          

    return 0;
}
