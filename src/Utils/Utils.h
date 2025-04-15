#pragma once

#include <algorithm>
#include <iostream>
#include <random>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>

namespace utils {

namespace internal {

extern std::mt19937_64 rng;

}  // namespace internal

/**
 * @brief Init utils, like setting up random engines, clear buffers, etc.
 *
 */
void InitUtils();

/**
 * @brief Generate a random vector whose elements are within range [left, right] (inclusive)
 *
 */
template<typename T>
std::vector<T> GenVector(T left, T right, size_t length) {
	std::uniform_int_distribution<T> dist(left, right);
	std::vector<T> res(length);
	std::ranges::generate(res, [&]() -> T {
		return dist(internal::rng);
	});
	return res;
}

template<typename T>
void PrintVector(const std::vector<T> &vec, const std::string &name = "") {
	if (!name.empty()) {
		std::cout << name << " = ";
	}

	std::cout << "[ ";

	int n = vec.size();
	for (int i = 0; i < n; i++) {
		std::cout << vec[i];
		if (i != n - 1) {
			std::cout << ", ";
		}
	}

	std::cout << " ]" << std::endl;
}

enum class NodeShape {
	PLAINTEXT,
	ELLIPSE,
	BOX,
	CIRCLE,
	DIAMOND,
	RECORD,
	NONE,
	NOTE,
	COMPONENT
};

/**
 * @brief A helper class to write DOT graph to stdout
 *
 * It's just an interface, see derived classes for more information
 *
 * @see GraphWriter_Array
 */
class GraphWriter {
protected:
	std::string _GraphName;
	bool _IsDirected;

	std::stringstream _Data;

public:
	GraphWriter(const std::string &graph_name, NodeShape node_shape, bool is_directed = true);

	/**
	 * @brief Write graph data to *stdout*
	 *
	 */
	void Output();
};

class GraphWriter_Array : public GraphWriter {
public:
	size_t AddArray(size_t length);
};

}  // namespace utils
