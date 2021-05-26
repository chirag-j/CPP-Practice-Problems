#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    stops.push_back(dist);
    int lastRefill = 0, n = 0;
    // std::cout<<stops.size()<<std::endl;

    for(int i = 0; i<stops.size()-1; i++){
        if(((stops[i] - lastRefill)<=tank) && ((stops[i+1] - lastRefill) > tank)){
            lastRefill = stops[i];
            // std::cout<<lastRefill<<"\n";
            n++;
        }
        if((stops[i] - lastRefill)>tank || (stops[i+1]-stops[i])>tank) {
            return -1;
        }
    }
    return n;
}


int main() {
    int d = 0;
    int m = 0;
    int n = 0;
    cin >> d;
    cin >> m;
    cin >> n;
    vector<int> stops(n);

    for (size_t i = 0; i < n; ++i){
        cin >> stops.at(i);
    }
    // d = 10;
    // m = 3;
    // n = 4;
    // vector<int> stops = {1,2,5,9};

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
