#include <iostream>
#include <vector>

constexpr int N = 20;
std::vector<int> factors[N + 1];

int main() {
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			factors[j].push_back(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		std::cout << i << ": ";
		for (auto fac : factors[i]) {
			std::cout << fac << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}
