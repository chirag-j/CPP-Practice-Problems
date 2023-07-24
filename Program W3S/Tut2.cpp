// Program2
#include<iostream>

using namespace std;

void sampleFunc(int &x);    
// Pass by reference: Useful when you want to change the value of the arguments, 
// without "return"ing the values back to a new var

int sampleFunc(int x, int y);

int main(){
	int a[5] = {1,2,3,4,5};
	cout<<sizeof(a)/sizeof(a[0])<<endl;     //To calculate size of the array


	cout<<&a[3]<<endl;		//Returns memory address of variable a
	int &b = a[3];      // reference variable--points to another variable
	cout<<b<<endl;

// Pointer variable stores the address of a variable
	int* ptr = &a[3];
	cout<<"ptr "<<ptr<<endl;

// De-reference operator --  to get the value of the variable from its pointer	
	cout<<"*ptr "<<*ptr<<endl;
// When used in declaration (string* ptr), it creates a pointer variable.
// When not used in declaration, it act as a dereference operator.

// You can also change the value of variable using its pointer
	*ptr = 7;
	cout<<a[3]<<endl;

	sampleFunc(a[3]);
	cout<<a[3]<<endl;

	cout<<sampleFunc(3,5)<<endl;

	// new keyword
	float *f1 = new float(13.43);
	cout<<"f1 : "<<*f1<<endl;
	delete f1;
	cout<<"f1 : "<<*f1<<endl;
	int *pn = new int[3];
	pn[0] = 40;
	pn[1] = 41;
	delete[] pn;
	cout<<"Value of pn : "<<pn[0]<<endl;

	cout<<"Value of pn : "<<pn[1]<<endl;


	return 0;
}

// C++ works from top to bottom; which means that if the function is not declared above main(), the program is unaware of it
// However, it is possible to separate the declaration and the definition of the function - for code optimization.

void sampleFunc(int &x){
	x+=3;
	cout<<"Function Called\n";
}

// When a parameter is passed to the function, it is called an argument.
// Pass by reference(Call by reference): Useful when you want to change the value of the arguments without "return"ing the values back to a new var
// call by pointer -- Address of the variable (&var) is sent to the function -- inside the function de-reference operator 	

// With function overloading, multiple functions can have the same name with different parameters
// Note : different data types of parameters counts as different functions
int sampleFunc(int x, int y){
	return (x+y);
}

// Storing the address of an array into pointer is different than storing the address of a variable into the pointer 
// because the name of the array is an address of the first index of an array. 
// So to use ampersand "&" with the array name for assigning the address to a pointer is wrong.
int marks[400];
int *p = marks;  // correct way to store address of first location in p

