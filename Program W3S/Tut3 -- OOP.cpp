#include<iostream>
#include<string>
using namespace std;
// There are two ways to define functions that belongs to a class:
// Inside class definition
// Outside class definition   
// To define a function outside the class definition, 
// you have to declare it inside the class and then define it outside of the class

class vehicle{
private:
	static int count; 					// static variable is created only once for the class, and is shared by its objects
	// static variable is also called class variables
	string driver_name;
public:									//Access specifier Private members cannot be accessed from outside the class
	void turn_left(int max_speed);
	vehicle(int length, int width);   //declaring the constructor
	// Note: Constructors can also be called with default arguments
	vehicle();						// constructor overloading

	// copy constructor used to make an object of the class which resembles another object of the same class
	// or maybe some other purpose
	// Note : Compiler by default has a copy constructor, so if not provided the default just copies into new obj
	// copy constructor is also invoked if new object is created and assigned to another object in the SAME line
	// vehicle v3 = v2; // Copy constructor will be invoked
	// vehicle v3;
	//v3 = v2;  // copy constructor will NOT be invoked
	vehicle(vehicle &x){
		driver_name = x.driver_name; 
		cout<<"Copy constructor called \n";
	}

	// Encapsulation start
	void set_driver_name(string name){
		driver_name = name;
	}

	string get_driver_name(){
		return driver_name;
	}
	// Encapsulation end


	static void getCount(){
		cout<<"Value of count is : "<<count<<endl;			//cannot access non-static variables inside a static function 
	}

	// To call a static funtion use className :: funnction()
	// vehicle :: getCount();
};

int vehicle :: count;       		
//static variable is declared outside the class, to allocate memory only once, 
// default value taken is zero
// count can be initialized to value here

// A static function is used to access only static variables


class truck: public vehicle{
public:
	int length = 7, width = 4;
	truck(int length, int width, int speed):vehicle(length, width){     //parameterized constructor of parent class
		cout<<"entered"<<endl;
	}

};


void vehicle::turn_left(int max_speed){
	cout<<"Taking turn_left at max_speed : "<<max_speed<<endl;
}

vehicle::vehicle(int length, int width){
	cout<<"vehicle length : "<<length<<endl<<"vehicle width : "<<width<<endl;
	// This is the constructor
}

vehicle::vehicle(){
	cout<<"Non parameterized constructor was called"<<endl;
}

int main(){

	vehicle v1;

	truck veh1(10,10, 70);

	veh1.turn_left(55);
	veh1.set_driver_name("John");
	cout<<veh1.get_driver_name()<<endl;

	// cout<<veh1.driver_name<<endl;   //Not Allowed

	vehicle v2(v1);		// another object passed as an argument

	vehicle *v3 = &v1; 	//Pointer to an object (So now *v3 and v1 refer to the same object)
	// (*v3).set_driver_name("Daddy");   // is exactly same as
	v3->set_driver_name("Daddy");
	// (->) this automatically applies dereference operator
	cout<<"Driver Name of *v3 is "<<(v1).get_driver_name()<<endl;   //Note: v1 driver name has been changed
	// vehicle *v3 = new vehicle; //Also valid--works the same

	vehicle *v4 = new vehicle[3];   //creating an array of objects 
	//v4 points to the first object in the object array
	v4->set_driver_name("Nights Fury");
	(v4+1)->set_driver_name("Stark");
	cout<<v4->get_driver_name()<<(v4+1)->get_driver_name()<<endl;
	// vehicle v5[3];   WOrks same as well

	// base class Pointer pointing to derived class
	


	return 0;
}

// The constructor has the same name as the class, it is always public, and it does not have any return value
// Constructor can take parameters like regular functions
// Just like functions, constructors can also be defined outside the class.

// Access Specifiers --- by default members of class are private unless otherwise specified
// It is considered good practice to declare your class attributes as private (as often as you can). 
// This will reduce the possibility of yourself (or others) to mess up the code 
// protected : just like private but Members can be accessed in inherited class also

// Encapsulation --- Increased security of data
// Declare functions in public to get and set a private value -- eg shown above

// Inheritance --  Inherit methods and variables from a parent class(base) to child class(derived)
// reuse attributes and methods of an existing class when you create a new class

// Multilevel Inheritance -- A class can also be derived from one class, which is already derived from another class.

// Multiple Inheritance -- A class can also be derived from more than one base class, using a comma-separated list

/*
class MyChildClass: public MyClass, public MyOtherClass {

};
*/

// virtual base class : need arises in case of multiple inheritance when copies of same members are accesible from 
// two different classes. (i.e a common parent class), 

