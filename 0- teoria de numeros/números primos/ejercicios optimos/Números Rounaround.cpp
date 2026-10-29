#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int main(){
	string n;
	cin >> n;
	int i = 1;
	vector <int> num(0);
	
	for(i = 0; i < n.size(); i++){
		num.push_back(n[i]-48);
	}
	
	bool flag2 = false;
	int l = num.size();
	while(!flag2){
		num[l-1]++;
		for(i = l-1; i > 0; i--){
			if(num[i] == 10){
				num[i] = 0;
				num[i-1]++;
			}
		}
		if(num[0] == 10){
			num[0] = 0;
			num.push_back(0);
			for(i = l-1; i >= 0; i--){
				num[i+1] = num[i];
			}
			num[0] = 1;
			l++;
		}
		
		bool ups = true;
		for(int t = 0; t < l; t++){
			for(int u = t+1; u < l; u++){
				if(num[t] == num[u]){
					ups = false;
					break;
				}
			}
			if(!ups){
				break;
			}
		}
		if(!ups){
			continue;
		}
		
		int v[l] = {0}, m = 0;
		bool flag = true;
	
		v[0] = 1;
		for(i = 1; i <= l; i++){
			m += num[m];
			while(m > l-1){
				m = m - l;
			}
			if(i != l){
				if(v[m] == 1){
					flag = false;
					break;
				}
				else{
					v[m] = 1;
				}	
			}
		}
		if(m != 0){
			flag = false;
		}
		
		if(flag){
			flag2 = true;
		}	
	}
	
	for(i = 0; i < l; i++){
			cout << num[i];
	}

	
	return 0;
}