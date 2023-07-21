#include <iostream>
#include <list>
#include <string>
#include <locale>         // std::locale, std::tolower

using namespace std;



class Node
{
  public:
    Node(string name, list<Node> children = {})
    {
        name_ = name;
        children_=children;
    };
    
    static int cToLower(int c) {
        return tolower(c);
    }

    bool isPresent(string name, string ndl){
        int j=0;
        for(int i=0; i<name.size(); i++){
            if(cToLower(name[i]) == cToLower(ndl[j])){
                j++;
                if(j==ndl.size()){return 1;}
            }
            else{
                j==0;
            }
        }
        return 0;
    }

    int count_nodes_containing_string(string needle)
    {
        //TODO implement me, needs to be case-insensitive
        // needle; //TODO use the parameter
        int cnt = 0;
        if(isPresent(name_, needle)){
            cnt++;
        }
        for(Node node: children_){
            cnt = cnt + node.count_nodes_containing_string(needle);
        }

        return cnt;
    }
private:
    string name_;
    list<Node> children_;
};

#ifndef RunTests
int main()
{
    //Create an example tree
    Node n("root",{
        {"MagaZino",{
            {"I"},
            {"Love"},
            {"magazino"}
            }},
        {"Hello",{
            {"Hello",{
                {"Hello",{
                    {"World"}
                }}
            }}
        }}
    });
    //Cout the solution
    cout << n.count_nodes_containing_string("hello")<<endl;
}
#endif