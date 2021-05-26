#include <iostream>
#include <vector>

int get_change(int m) {
	std::vector<int> v = {10,5,1};
	int n = 0;
	int temp = m;
	for(int i = 0; i<=v.size(); i++){
		n+=int(temp/v[i]);
		temp = temp % v[i];
		if(temp == 0){
			break;
		}
	}


  //write your code here

	return n;
}

int main() {
  int m;
  std::cin >> m;
  // m = 28;
  std::cout << get_change(m) << '\n';
}
