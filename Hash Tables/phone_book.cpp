#include <iostream>
#include <vector>
#include <string>
#include<cmath>
using namespace std;

class Query{
public:
    string type, name;
    long long number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<Query> contacts;
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            bool was_founded = false;
            // if we already have contact with such number,
            // we should rewrite contact's name
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    contacts[j].name = queries[i].name;
                    was_founded = true;
                    break;
                }
            // otherwise, just add it
            if (!was_founded)
                contacts.push_back(queries[i]);
        } 
        else if (queries[i].type == "del") {
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    contacts.erase(contacts.begin() + j);
                    break;
                }
        } 
        else {
            string response = "not found";
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    response = contacts[j].name;
                    break;
                }
            result.push_back(response);
        }
    return result;
}

long long hashInteger(long long x,long long p, long long a, long long b, long long m){
    long long temp = (a*x+b)%p;
    // cout<<temp<<endl;
    return temp%m;
}

vector<string> process_queries_hash(vector<Query> queries){
    long long m = 1e7;
    long long p = 1e7 +13;
    long long a = 523069, b = 18469;
    // long long a = rand()%p +1, b = rand()%p + 1; 
    vector<string> names(m, "not found");
    // vector<int> phone(m);
    vector<string> results;

    for(int i=0; i<queries.size(); i++){
        if(queries[i].type == "add"){
            names[queries[i].number] = queries[i].name;      
        }
        else if(queries[i].type == "del"){
            names[queries[i].number] = "not found";
        }
        else{
            results.push_back(names[queries[i].number]);
        }
    }
    // cout<<p<<endl<<a<<endl<<b<<endl<<hashInteger(7777778,p,a,b,m)<<endl;
    return results;
}

int main() {

    // process_queries_hash();
    write_responses(process_queries_hash(read_queries()));
    return 0;
}
