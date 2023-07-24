#include<iostream>
#include<iomanip>    // to use setw()
using namespace std;

int a = 25;
const int b = 34;   // value of a contant variable cannot be changed

class road{
	int volume, ex;
public:
	// int volume;

	friend void setVolume(road &r, int n);   //A friend function can access private function of the class

	int getVolume(){
		cout<<volume<<endl;
	}

	// this keyword -- to state to the compiler, that we are referring to a member of this class
	// this is a pointer which points to the object who invoked this function
	// so essentially (*r3).a = a; 		// this is happening
	void setEx(int ex){
		// ex = ex;      //By default the ex in this function will refer to the local variable which is the argument
		this->ex = ex;   // Will change the class member value ex

	}
	void getEx(){
		cout<<"Value Of Ex : "<<ex<<endl; 
	}
};

void setVolume(road &r, int n){    		//Taking a class object as one of the parameters
	r.volume = n;
	cout<<r.volume<<endl;
}



int main(){
	int a = 35;
	cout<<a<<endl<<::a<<endl<<endl;    //use scope resolution operator :: to access the global variable a

	float x = 34.4f;
	long double y = 35.6l;
	cout<<sizeof(34.4)<<endl<<sizeof(34.4f)<<endl<<setw(4)<<sizeof(34.4l);
	//l - makes the number long double, f - floating point number, default double

	road jvlr;
	setVolume(jvlr, 100);
	cout<<endl<<"JVLR volume : "; 
	jvlr.getVolume();

	road r2;
	r2.setEx(3);
	r2.getEx();


	return 0;
}

// double is the default type given to a  decimal literal 
// (34.4 is double by default and not float), so to use it as float, you have to specify it like "34.4F," 


//Polymorphism
//can be "runtime" or "compile time"
// compile time -- function overloading and operator overloading
// runtime -- virtual function
