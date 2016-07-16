/* Klasa SP jest grafem, ktory modeluje np. spolecznosc. Wierzcholki sa napisami (np. nazwiska osob), krawedzie skierowane modeluja relacje pomiedzy osobami. Implementacja metod:
- dodawanie wierzcholka
- usuwanie wierzcholkow i wszystkich krawedzi
- dodawanie krawedzi miedzy osobami
- laczenie wierzcholkow (i scalanie przy tym krawedzi) */

#pragma once
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class SP
{
	map<const char*, vector<const char*>> graph;
public:
	SP()
	{};
	void add_vertex(const char* v);
	void del_vertex(const char* v);
	void add_edge(const char* p1, const char* p2);
	void connect_vertex(const char* p1, const char* p2);
	void write()
	{
		for (map<const char*, vector<const char*>>::iterator it = graph.begin(); it != graph.end(); ++it)
		{
			cout << it->first << " => ";
			for (vector<const char*>::iterator it_vector = it->second.begin(); it_vector != it->second.end(); it_vector++)
				cout << *it_vector << ", ";
			cout << endl;
		}
	}
};

void SP::add_vertex(const char* v)
{
	pair<map<const char*, vector<const char*>>::iterator, bool> ret;
	ret = graph.insert({ v, vector<const char*>() });
	if (ret.second == false)
		cout << "element already exists" << endl;
}

void SP::del_vertex(const char* v)
{
	if (graph.find(v) != graph.end())
	{
		graph[v].clear();
		graph.erase(v);
	}
	else
		cout << "element doesn't exist" << endl;
}

void SP::add_edge(const char* p1, const char* p2)
{
	if (graph.find(p1) != graph.end())
	{
		if (find(graph[p1].begin(), graph[p1].end(), p2) == graph[p1].end())
			graph[p1].push_back(p2);
		else
			cout << "edge already exist" << endl;
	}
	else
		cout << "vertex doesn't exist" << endl;
}

void SP::connect_vertex(const char* p1, const char* p2)
{
	for (vector<const char*>::iterator it = graph[p2].begin(); it != graph[p2].end(); it++)
		if (find(graph[p1].begin(), graph[p1].end(), *it) == graph[p1].end())
			graph[p1].push_back(*it);
	graph[p2].clear();
	graph.erase(p2);
}
