#include "Utils.h"

#include <iostream>

namespace utils {

namespace internal {

std::mt19937_64 rng;

}  // namespace internal

void InitUtils() {
	std::random_device rd;
	internal::rng.seed(rd());
}

GraphWriter::GraphWriter(const std::string &graph_name, NodeShape node_shape, bool is_directed)
    : _GraphName(graph_name)
    , _IsDirected(is_directed) {

	_Data << std::format("{}graph {} {{\n", (is_directed ? "di" : ""), graph_name);

	switch (node_shape) {
	case NodeShape::BOX:
		_Data << "node [shape=box];\n";
		break;
	case NodeShape::CIRCLE:
		_Data << "node [shape=circle];\n";
		break;
	case NodeShape::COMPONENT:
		_Data << "node [shape=component];\n";
		break;
	case NodeShape::DIAMOND:
		_Data << "node [shape=diamond];\n";
		break;
	case NodeShape::ELLIPSE:
		_Data << "node [shape=ellipse];\n";
		break;
	case NodeShape::NONE:
		_Data << "node [shape=none];\n";
		break;
	case NodeShape::NOTE:
		_Data << "node [shape=note];\n";
		break;
	case NodeShape::PLAINTEXT:
		_Data << "node [shape=plaintext];\n";
		break;
	case NodeShape::RECORD:
		_Data << "node [shape=record];\n";
		break;
	default:
		break;
	}

	_Data << std::flush;
}

void GraphWriter::Output() {
	std::cout << _Data.rdbuf() << "\n}" << std::endl;
}

}  // namespace utils
