#include <iostream>
#include <fstream>
#include <vector> 
#include <string.h>
#include <algorithm>

using namespace std;

class edge{
public:
	int from;
	int to;
	int weight;
};
int v;


vector<edge> readfile(){

	string filename = "graph.txt";

	ifstream fin(filename);

	fin >> v;

	vector<edge> graph;

	while (!fin.eof()){
		edge e;
		fin >> e.from >> e.to >> e.weight;
		graph.push_back(e);
	}

	return graph;
}


void mbf(vector<edge> graph){
	
	int oo = 2000000000;
	vector<int> predecessors(v, -1);
	vector<int> minweight(v, oo);
	minweight[0] = 0;
	predecessors[0] = 0;

	for (int i = 0; i < v-1; ++i){
		for (auto e : graph){
			if (minweight[e.to] > minweight[e.from] + e.weight){
				minweight[e.to] = minweight[e.from] + e.weight;
				predecessors[e.to] = e.from;
			}
		}
	}

	for (auto e : graph){
		if (minweight[e.to] > minweight[e.to] + e.weight){
			cout << "negative cyclus!\n";


			vector<bool> visited(v, false);
			vector<int> negcycle_reverse;




			int current = e.to;
			for (int k = 0; k < v; ++k){
				
				if (visited[current]){ //cycle found?
					int up = predecessors[current];
					//collect cycle
					while (up != current){
						negcycle_reverse.push_back(up);
						up = predecessors[up];
					}

					//output
					for (auto j = negcycle_reverse.rbegin(); j != negcycle_reverse.rend(); ++j){
						cout << *j << "-";
					}

					break;
				}

				visited[current] = true;
			}





		}
	}



}



int main(){



	vector<edge> graph = readfile();
	mbf(graph);

	return 0;
}