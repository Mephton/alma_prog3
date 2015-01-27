#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

typedef vector<vector<int> > Graph;

Graph graph;
Graph graph_rev;
int v, e;


class way{
private:
	vector<int> _way;
public:
	way(int start){
		_way.push_back(start);
	}
	int size(){
		return _way.size();
	}
	string output(){
		stringstream s;
		for (auto i : _way){
			s << i;
			if (i != _way.back()){ 
				s << " - "; 
			}
			else{
				s << " (size: " << size()-1 << ")\n";
			}
		}
		return s.str();
	}
	void add(int newnode){
		if (is_empty()){
			pop();
		}
		_way.push_back(newnode);
	}
	void pop(){
		_way.pop_back();
	}
	bool is_empty(){
		return(_way.size() == 1 && _way[0] == -1);
	}
};

vector<way> longestwayarrival;

way l(int vj, way state){

	if (!longestwayarrival[vj].is_empty()){
		return(longestwayarrival[vj]);
	}
	way m = state;
	for (auto vi : graph_rev[vj]){
		way tmp = l(vi, state);
		tmp.add(vj);

		m = m.size() > tmp.size() ? m : tmp;
	}
	longestwayarrival[vj] = m;
	return m;
}

void read_from_file(string filename){
	fstream fin(filename);
	fin >> v >> e;

	for (int i = 0; i < v; ++i){
		graph.push_back(vector<int>());
		graph_rev.push_back(vector<int>());
	}

	int tmp1, tmp2;
	for (int i = 0; i < e; ++i){
		fin >> tmp1 >> tmp2;
		graph[tmp1].push_back(tmp2);
		graph_rev[tmp2].push_back(tmp1);
	}
}

way maxways(){
	longestwayarrival.resize(v, way(-1));
	way longestway = way(0);
	for (int i = 0; i < graph.size(); ++i){
		way current = l(i, way(i));
		longestway = longestway.size() < current.size() ? current : longestway;
	}
	return(longestway);
}

vector<int> topsort_algo(){

	vector<bool> visited(v, false);
	vector<bool> saved(v, false);
	vector<int> topsort;

	stack<int> s;

	for (int i = 0; i < v; ++i){
		s.push(i);
	}

	while (!s.empty()){
		int curr = s.top();
		if (saved[curr]){
			s.pop();
			continue;
		}
		if (visited[curr]){
			saved[curr] = true;
			topsort.push_back(curr);
			s.pop();
		}
		else{
			visited[curr] = true;
			for (auto i : graph_rev[curr]){
				s.push(i);
			}
		}
	}
	return topsort;
}


int main(){
	for (int file = 0; file < 850; ++file){
		longestwayarrival.clear();
		graph.clear();
		graph_rev.clear();
		

		ofstream fout("out" + to_string(file) + ".txt");

		read_from_file("graph" + to_string(file) + ".txt");

		vector<int> topsort = topsort_algo();

		for (auto i : topsort){
			fout << i;
			if (i != topsort.back()){
				fout << " - ";
			}
			else{
				fout << "\n";
			}
		}

		way longestway = maxways();
		fout << longestway.output();
	}
	

	return 0;

}

