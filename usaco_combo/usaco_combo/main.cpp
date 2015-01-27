
/*
ID: mirko.s1
PROG: combo
LANG: C++
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;


set<vector<int> > valids;
int n;
vector<vector<int> > codes(2);

void rec(int dial, int code, vector<int> current){
	for (int pos = (codes[code][dial] + n - 2) % n; pos != (codes[code][dial] + 3) % n; pos = (pos + 1) % n){
		current[dial] = pos;
		if (dial == 2){ 
			valids.insert(current); 
		}
		else{ 
			rec(dial + 1, code, current); 
		}
	}
}



int main(){
	ofstream fout("combo.out");
	ifstream fin("combo.in");
	

	fin >> n;
	n++;
	int tmp;
	for (int i = 0; i < 6; ++i){
		fin >> tmp;
		codes[i / 3].push_back(tmp);
	}



	for (int code = 0; code < 2; ++code){
		rec(0, code, vector<int>(3));
	}

	fout << valids.size() << "\n";

	return 0;
}