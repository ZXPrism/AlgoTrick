#include <format>
#include <iostream>

int main() {
	// 普通的二进制枚举
	for (int i = 0; i < (1 << 4); i++) {
		std::cout << std::format("{:04b}\n", i);
	}

	std::cout << '\n';

	// 扩展的二进制枚举
	unsigned x = 0b1010, x0 = x;
	int bit_num = std::popcount(x);
	for (int i = 0; i < (1 << bit_num); i++) {
		std::cout << std::format("{:04b}\n", x0);
		x0 = (x0 - 1) & x;
	}

	return 0;
}
