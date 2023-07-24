#include<iostream>
#include <cmath>
using namespace std;

float newVar;
const int m = 15;    //m cannot be changed and will remain 15
int x  = 0 , y = 5;
int main(){	
	newVar = 16.5;
	cout<<"HelloWorld"<<endl<<"HelloWorld\n"<<newVar<<endl;
	
	cout<<(x==y)<<endl;

// Short hand If else statement
// variable = (condition) ? expressionTrue : expressionFalse;
	x = (x<y) ? y : x;
	cout<<x<<endl<<y<<endl;
// Do while loop
	int i = 0;
	do{
		cout<<x<<endl;
		x = i;
		i++;
	}
	while(i<=5);


	return 0;
}