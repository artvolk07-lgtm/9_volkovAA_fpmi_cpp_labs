#include <iostream>

int main()
{
	int k;
	std::cout << "Vvedi cрislo  ";
	std::cin >> k;

	if (k < 0) {
		std::cout << "Poloshitelnoe nado durak"<< std::endl;
		return 1;
	}
	long result = 1;

	if (k % 2 == 0) {
		for (int i = 2; i <= k ; i += 2) {
			result *= i;
		}
	}
	else {
		for (int i = 1; i <= k; i += 2) {
			result *= i;
		}
	}
	std::cout << k << "!! = " << result << std::endl;
	return 0;
}

