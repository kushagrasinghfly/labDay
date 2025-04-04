#include <iostream>
#include <string>
using namespace std;


class Animal 
{
	protected:
	    string name;
	    int age;
	    
	public:
	    Animal(string name, int age) {
		this->name = name;
		this->age = age;
	    }

	    void animalInfo() {
		cout << name << " is " << age << " years old." << endl;
	    }
};


class Pet 
{
	protected:
	    string breed;
	    
	public:
	    Pet(string breed) {
		this->breed = breed;
	    }

	    void petInfo() {
		cout << "Breed: " << breed << endl;
	    }
};


class Dog : public Animal, public Pet 
{
	public:
	    Dog(string name, int age, string breed) : Animal(name, age), Pet(breed) {}

	    void dogInfo() 
	    {
		cout << name << " is a " << breed << " dog." << endl;
	    }
};


class Cat : public Animal, public Pet 
{
	public:
	    Cat(string name, int age, string breed) : Animal(name, age), Pet(breed) {}

	    void catInfo() {
		cout << name << " is a " << breed << " cat." << endl;
	    }
};

int main() 
{
    
    Dog dog("Buddy", 3, "Golden Retriever");
    Cat cat("Whiskers", 2, "Siamese");


    cout << "Dog Info: " << endl;
    dog.animalInfo();  
    dog.petInfo();     
    dog.dogInfo();     

    cout << endl;


    cout << "Cat Info: " << endl;
    cat.animalInfo();  
    cat.petInfo();     
    cat.catInfo();     

    return 0;
}

