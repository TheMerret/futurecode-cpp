#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;
	int res = a / b;
	if (a % b != 0)
	{
		res += 1;
	}
	std::cout << res;
}