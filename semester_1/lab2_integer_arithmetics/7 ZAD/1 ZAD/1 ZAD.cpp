#include <iostream>
#include <cmath>
#include <limits>

int main()
{
	int n;
	bool N = false;
	while (!N) {
		std::cout << "Natural n: ";
		std::cin >> n;

		if (std::cin.fail() || n <= 0) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cout << "tupen vvedi NATURALNOE or not so big " << std::endl;
		}
		else {
			N = true;
		}
	}

	for (int a = 1; a <= n; ++a) {
		for (int b = a; b <= n; ++b) {
			int SQc = a * a + b * b;
			int c = static_cast <int> (std::sqrt(SQc));

			if (c * c == SQc && c <= n) {
				std::cout << "(" << a << ", " << b << ", " << c << ")" << std::endl;
			}
		}
	}

	return 0;
   
}

