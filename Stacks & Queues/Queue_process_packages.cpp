#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void display(vector<int> v){
	for(int i = 0; i<v.size(); i++){
		cout<<v[i]<<endl;
	}
	cout<<endl;
}

void display(queue<int> v){
	while(v.size()>0){
		cout<<v.front()<<" ";
		v.pop();
	}
	cout<<endl;
}
int main(){

	int S, n;
	
	cin>>S>>n;
	vector<int> jobs;
	vector<pair<int,int>> incoming_jobs(n);
	for(int i=0; i<n; i++){
		cin>>incoming_jobs[i].first>>incoming_jobs[i].second;
	}

	// S = 1;
	// vector<pair<int,int>> incoming_jobs = {{0,2}, {1,4},{5,3}};
	queue<int> ja, jp;
	if(incoming_jobs.size() == 0 || S==0){
		return 0;
	}

	int ctime = incoming_jobs[0].first, ftime = incoming_jobs[0].second, jnum = 0;
	ja.push(incoming_jobs[0].first);
	jp.push(incoming_jobs[0].second);
	vector<int> result(incoming_jobs.size());
	result[jnum] = incoming_jobs[0].first;
	jnum++;
	for(int i = 1; i<incoming_jobs.size(); i++){
		// cout<<"ja ";
		// display(ja);
		// cout<<"jp ";
		// display(jp);
		// cout<<"ctime "<<ctime<<" ftime "<<ftime<<endl;
		// display(result);
		if(ja.size()==S && ftime>incoming_jobs[i].first){
			result[i] = -1;
			// jnum++;
			continue;
		}
		else{
			ja.push(incoming_jobs[i].first);
			jp.push(incoming_jobs[i].second);
		}
		ctime = incoming_jobs[i].first;
		if(ctime>=ftime){
			ja.pop();
			jp.pop();
			while(result[jnum]==-1){
				jnum++;
			}
			result[jnum] = max(ftime, ja.front());
			jnum++;
			ftime = max(ftime, ja.front()) + jp.front();
		}

	}
	// cout<<"ja ";
	// display(ja);
	// cout<<"jp ";
	// display(jp);
	// cout<<"ctime "<<ctime<<" ftime "<<ftime<<" jnum "<<jnum<<endl;
	// display(result);

	while(ja.size()>1){
		ja.pop();
		jp.pop();
		while(result[jnum]==-1){
			jnum++;
		}
		result[jnum] = max(ftime, ja.front());
		jnum++;
		ftime = max(ftime, ja.front()) + jp.front();
	}

	display(result);
	return 0;
}