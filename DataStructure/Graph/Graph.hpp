#pragma once
#include "../Tree/Set.hpp"
#include <iostream>

template <typename T>
class Graph
{
public:
	static const size_t MAX = 20;

	Graph(){
		many_vertices = 0;
	}

	T& operator[](size_t vertex) {
		assert(vertex < size());
		return labels[vertex];
	}

	void add_vertex(const T& label) {
		assert(size() < MAX);

		size_t new_vertex_number = many_vertices++;
		labels[new_vertex_number] = label;

		for (int i = 0; i < many_vertices; i++) {
			edges[i][new_vertex_number] = false;
			edges[new_vertex_number][i] = false;
		}

	}

	void add_edge(size_t source, size_t target) {
		assert(source < size());
		assert(target < size());
		edges[source][target] = true;

	}

	bool is_edge(std::size_t source, std::size_t target) const
	{
		assert(source < size());
		assert(target < size());
		return edges[source][target];
	}

	void remove_edge(std::size_t  source, std::size_t  target)
	{
		assert(source < size());
		assert(target < size());

		edges[source][target] = false;
	}

	Set<size_t> neighbors(size_t vertex) const {
		Set<size_t> answer;
		assert(vertex < size());

		for (int i = 0; i < size(); i++) {
			if (edges[vertex][i]) {
				answer.insert(i);
			}
		}

		return answer;
	}

	size_t size() const {
		return many_vertices;
	}

	void print() {
		if (size() == 0) {
			std::cout << "[No Vertex]" << std::endl;
		}
		else {
			std::cout << "[printLabels start]" << std::endl << std::endl;
			printLabels();
			std::cout << std::endl << "[printLabels end]" << std::endl << std::endl;

			std::cout << "[printEdges start]" << std::endl << std::endl;
			printEdges();
			std::cout << std::endl << "[printEdges end]" << std::endl << std::endl;
		}
	}
private:
	bool edges[MAX][MAX];
	T labels[MAX];
	size_t many_vertices;
	void printLabels() {
		for (int i = 0; i < many_vertices; i++) {
			std::cout << "v" << i << ": " << labels[i] << " ";
		}
		std::cout << std::endl;
	}

	void printEdges() {
		std::cout << "   ";
		for (int i = 0; i < many_vertices; i++) {
			std::cout << "v" << i << " ";
		}

		std::cout << std::endl;
		
		for (int i = 0; i < many_vertices; i++) {
			std::cout << "v" << i << " ";
			for (int j = 0; j < many_vertices; j++) {
				std::cout << (edges[i][j] ? "T " : "F ") << " ";
			}
			std::cout << std::endl;
		}
	}

};