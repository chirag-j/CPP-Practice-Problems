#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
#include<map>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<queue>
using namespace std;
/*
Vectors
--continous memory locations -- makes insertion slow
--Fast access, slow insertion

List
-- memory allocation not contiguous -- Insertion deletion easy
-- Slower access, faster insertions

*/

class comp_map{
	public:
	bool operator()(string x, string y){
		return x>y;
	}
};

// class sort_comp{
// 	public:
// 	bool operator()(vector<int> &x1, vector<int> &x2){
// 		return x1[1] < x2[1];
// 	}
// };
auto mycomp(pair<string, int> a, pair<string, int> b){
	return (a.second < b.second);
}

template <class T>
void display(vector<T> &v){
	for (int i = 0; i < v.size(); ++i)
	{	
		cout<<v[i]<<setw(2);
	}
	cout<<endl<<setw(1);
}

void display(vector<int> v){
	for (int i = 0; i < v.size(); ++i)
	{	
		cout<<v[i]<<setw(2);
	}
	cout<<endl<<setw(1);
}

// template <class T>
void display(list<int> &lst){
	list<int> :: iterator it;
	for (it = lst.begin(); it!=lst.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}
void display(vector<vector<int>> &v){
	for(int i=0; i<v.size(); i++){
		display(v[i]);
	}
}
int main(){
	cout<<"Vector begin"<<endl;
	if(0){
		vector<int> v, v1(4); // v1 has length 4
		vector<int> v2(4,3);  // 4 element vector of 3's
		vector<int> v3(v2);  // to make a copy of vector v2
		int length, element;
		// cout<<"Enter Size : ";
		// cin>>length;

		v3[1] = 4;
		display(v2);	//Note change in v3 doesnt change either, same true for vice versa

		// v3.front() -- returns first element
		// v3.back() -- returns last element

		for (int i = 0; i < 4; ++i)
		{
			v.push_back(i);
			/* code */
		}
		v.push_back(4);
		display(v);
		vector<int>::iterator iter = v.begin();  //iter is now pointing to the beginning of vector v
		v.insert(iter+3, 5);		//inserts just before the the location the pointer is pointing to
		display(v);
		cout<<v[4]<<endl;
	}
	
	cout<<"Lists begin"<<endl;
	if(0){

		list <int> list1;
		list1.push_back(4);
		list1.push_back(2);
		list1.push_back(5);
		list1.push_back(5);
		list1.push_back(7);
		
		display(list1);
		// list1.pop_back();
		// list1.pop_front();
		list1.remove(5);   // removes all instances of value = 5;
		display(list1);
		// list1.sort();		// to sort a list
		
		list <int> list2;
		list2.push_back(1);
		list2.push_back(9);
		list2.push_back(3);

		list1.merge(list2);

		cout<<"After merging list1 : ";
		display(list1);

		list1.reverse();
		display(list1);
	}

	cout<<"Sets begin"<<endl;
	if(1){

		// Sets are implemented as Binary Search trees
		// by default stored in ascending order
		set<int> set2;
		set2.insert(45);
		set2.insert(31);
		set2.insert(50);
		set<int> :: iterator itr1;

		for (itr1 = set2.begin() ; itr1!=set2.end() ; itr1++){
			cout<<*itr1<<endl;
		}

		set<int, greater<int>> set3(set2.begin(), set2.end());   // will store in descending order
		for (itr1 = set3.begin() ; itr1!=set3.end() ; itr1++){
			cout<<*itr1<<endl;
		}

		set<vector<int>> setvec;
		setvec.insert({-1,-1,0});
		setvec.insert({-1,-1,0});    //will not insert dupes (if you change order within the vector, it will insert)
		setvec.insert({3,1,0});
		setvec.insert({0,1,0});
		for (auto &it:setvec){
			display(it);
		}
		cout<<"setvec size: "<<setvec.size()<<endl;

		set<string> setstr;
		setstr.insert("akon&florida");
		setstr.insert("chirag@gmail.com");
		setstr.insert("chirag@gmail.com");
		cout<<"Setstr.size(): "<<setstr.size()<<endl;
	}

	cout<<"Maps begin "<<endl;
	if(1){

		// maps store key-value pairs in order of the keys
		// you can also give vector as a key to maps
		auto comp_map_inst = [](string x,  string y){
			return x>y;
		};
		map<string, int, decltype(comp_map_inst)> marks(comp_map_inst);
		marks["bacd"] = 98;
		marks["abcd"] = 95;
		marks["acbd"] = 95;
		marks["abdc"] = 95;
		// marks.insert({{"Chirag", 99},{"Heeman", 100},{"Lauv", 101}});

		map<string, int> :: iterator itr;
		for(itr = marks.begin() ; itr!=marks.end() ; itr++){
			cout<<(*itr).first<<" "<<(*itr).second<<endl;	
		}

		// cout<<"Marks Size : "<<marks.size()<<endl<<"Marks End-----"<<endl;
	}

	cout<<"Unordered Maps begin "<<endl;
	if(1){
		cout<<"Unordered Map - Stores key value pair in a hash table"<<endl;
		unordered_map<string, int> phonebook({{"Police", 100}, {"Fire", 101},{"Ambulance", 102}});

		// unordered_map containers do not allow for duplicate keys, 
		// So, "count" actually returns 1 if an element with that key exists in the container, and zero otherwise.

		if(phonebook.count("Chirag") == 1){
			cout<<"Chirag Found"<<endl;
		}
		else{
			cout<<"No number with name Chirag found"<<endl;
		}
		
		cout<<phonebook["Chirag"]<<endl;
		//note that your query for any random key will add that key to the map with a value of by default zero

		if(phonebook.count("Chirag") == 1){
			cout<<"Chirag's contact found, how?"<<endl;
		}
		else{
			cout<<"No number with name Chirag found"<<endl;
		}
		unordered_map<string, int> :: iterator miter = phonebook.find("Police");
		// find will return the iterator to the key-value pair if found, else it returns end()
		
		// auto keyword saves time, but remember the og syntax
		// auto miter = phonebook.find("Police");
		if(miter == phonebook.end()){
			cout<<"No Police";
		}
		else{
			cout<<miter->first<<" found, its Number : "<<miter->second<<endl;
		}
		unordered_map<int, int> umap;
		umap[1]+=5;

		cout<<"umap[55] : "<<umap[55]<<endl;   ///By default all the values for all keys will be zero
		//note that your query for any random key will add that key to the map with a value of by default zero
		
		// Auto range based loop - C++11 __WOW__tryna_be_python
		for(auto& elm: phonebook){   	 //for(pair<string, int> elm: phonebook){
			cout<<elm.first<<" "<<elm.second<<" ";
		}
	}

	cout<<"Priority Queue begin "<<endl;
	if(0){
		//Lambda function demo
		auto compare = [](pair<int,long long> a, pair<int,long long> b){
			if(a.first == b.first){
				return a.second < b.second;
			}
			return a.first < b.first;
		};
		priority_queue<pair<int,long long>, vector<pair<int,long long>>, decltype(compare)> pq(compare);
		pq.push({1,2});
		pq.push({2,5});
		pq.push({3,4});
		pq.push({5,0});
		pq.push({0,0});
		while(!pq.empty()){
			auto obt = pq.top();
			cout<<obt.first<<" "<<obt.second<<endl;
			pq.pop();
		}
		priority_queue<string> pq_str;
		pq_str.push("abcd");
		pq_str.push("abz");
		pq_str.push("aba");
		while(!pq_str.empty()){
			cout<<pq_str.top()<<endl;
			pq_str.pop();
		}
	}
	
	vector<vector<int>> temp_vec = {{5,7},{1,2},{7,4}};
	auto sort_comp = [](vector<int> x1, vector<int> x2){
		return x1[1] < x2[1];
	};
	sort(temp_vec.begin(), temp_vec.end(), sort_comp);
	display(temp_vec);
	return 0;
}




// STL library -- use inbuilt functions

/*Components of STL
-- Container - Use template classes, store data
-- ALgorithms - Sorting, searching, merging, copying, etc (Use template functions)
-- Iterators - Object that points to an element in a container (Handled just like pointers)- connects algoritmhs with containers
*/
/*
Container -- 
Sequence - Linear Fashion, eg: Vector, List, dqueue(double ended queue)	
Associative - (Tree like data struct)Useful in searching, lookup,deletion etc eg: Set, multi set, multi map, dictionary
Derived - Real world modelling etc: stack, queue, prority queue.
*/