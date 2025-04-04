
#include <iostream>
using namespace std;


class Book 
{
	public:
	    string title;
	    string author;

	    Book(string title, string author) 
	    {
		this->title = title;
		this->author = author;
	    }

	    void showDetails() 
	    {
		cout << "Book Title: " << title << endl;
		cout << "Book Author: " << author << endl;
	    }
};


class Magazine : public Book 
{
	public:
	    int issueNumber;

	    Magazine(string title, string author, int issueNumber) : Book(title, author) 
	    {
		this->issueNumber = issueNumber;
	    }

	    void showIssue() 
	    {
		cout << "Magazine Issue Number: " << issueNumber << endl;
	    }
};

int main() {
    Magazine mag("Tech Today", "John Doe", 42); 
    mag.showDetails();     
    mag.showIssue();       

    return 0;
}

