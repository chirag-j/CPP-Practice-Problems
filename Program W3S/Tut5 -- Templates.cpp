#include<iostream>
using namespace std;

// template -- Parameterized classes

// multiple parameters template can also be prepared
template <class T1 = float, class T2 = char>
class vector{
public:
	T1* arr;
	int size;
	T2 x;

	vector(int n, T2 x){
		this->x = x;
		size = n;
		arr = new T1[size];
	}

	T1 dotProduct(vector &v){
		T1 d = 0;
		for(int i = 0; i<size; i++){
			d+=(this->arr[i])*v.arr[i];
		}
		return d;
	}

	void display();

	// void display(){
	// 	cout<<x<<size<<endl;
	// }
};
// How to declare member function with template outside the classs
template<class T1, class T2>
void vector<T1,T2> :: display(){
	cout<<"x : "<<x<<endl<<"size : "<<size<<endl;
}
// Thats how its done, else it throws an error.


// How to declare a template function
template<class T1, class T2>
void findAverage(T1 a, T2 b){
	cout<<"Average of "<<a<<" and "<<b<<" is "<<(a+b)/2.0<<endl;
}
// done

//funtion overloading, normal vs template---- Exact match function is given highest priority
void findAverage(int a, int b){

	cout<<"Average of "<<a<<" and "<<b<<" is "<<(a+b)/2.0<<endl;
	cout<<"This was called by exact match function and not by template function"<<endl;
}
//

int main(){
	vector <> v1(3, 'a'), v2(3, 'g');    // using default template arguments
	// vector <float, int> v1(3, 5), v2(3, 6);
	v1.display();
	v2.display();

	v1.arr[0] = 4.3;
	v1.arr[1] = 3.2;
	v1.arr[2] = 1.1;	

	v2.arr[0] = 2.1;
	v2.arr[1] = 4.5;
	v2.arr[2] = 0.9;

	cout<<"Dot Product is: "<<v1.dotProduct(v2)<<endl;

	vector <int, int> v3(45, 43);   // Specifying different template arguments
	v3.display();


	findAverage(3.4,4.4);    		/// i can pass two numbers of any data type it will accept it
	// function template very useful in case of swap function where you have to swap two variables regardless of their dtype
	findAverage(3,4);
	return 0;
}