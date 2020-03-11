#include<iostream>
#include<vector>
using namespace std;

class Vertex;

class Edge {
public:
	const Vertex *from;
	const Vertex *to;
	Edge(Vertex*from, Vertex*to) :
		from(from), to(to) {}
};

class Vertex {
	vector<Edge> edges;
	int id;
public:
	Vertex(int id) :id(id) {
	}
	void addEdge(Vertex*to) {
		edges.push_back(Edge(this, to));
		to->edges.push_back(Edge(to, this));
	}
};

class Graph {
public:
	vector<Vertex> vertexes;
};

int main()
{
	
}