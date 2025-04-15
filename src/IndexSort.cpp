#include <Utils/Utils.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>

int main() {
	utils::InitUtils();

	constexpr int n = 10;
	auto vec = utils::GenVector(1, 100, n);
	utils::PrintVector(vec, "输入数组");

	std::vector<int> idx(n);
	std::ranges::iota(idx, 0);  // 生成 0 ~ n - 1 下标序列
	utils::PrintVector(idx, "索引数组");

	// 进行索引排序
	std::ranges::sort(idx, {}, [&](int x) { return vec[x]; });
	// 或者写成：
	// std::ranges::sort(idx, [&](int lhs, int rhs) {
	//     return vec[lhs] < vec[rhs];
	// });
	utils::PrintVector(idx, "索引排序后的索引数组");

	std::vector<int> result;
	for (auto i : idx) {
		result.push_back(vec[i]);
	}
	utils::PrintVector(result, "排序结果");

	return 0;
}
