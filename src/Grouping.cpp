#include <Utils/Utils.h>

#include <iostream>
#include <numeric>
#include <unordered_map>

int main() {
	utils::InitUtils();

	constexpr int n = 10;
	auto vec = utils::GenVector(1, 5, n);
	utils::PrintVector(vec, "输入数组");

	std::vector<int> idx(n);
	std::ranges::iota(idx, 0);
	utils::PrintVector(idx, "下标序列");

	std::unordered_map<int, std::vector<int>> groups;
	for (int i = 0; i < n; i++) {
		groups[vec[i]].push_back(i);
	}

	for (auto &[val, pos] : groups) {
		std::cout << val << ": ";
		utils::PrintVector(pos);
	}

	return 0;
}
