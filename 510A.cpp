#include <iostream>



int main()
{
	int n, m;
	bool flag = true;

	std::cin >> n >> m;
	
	for (size_t i = 0; i < n; i++)
	{
		if (i % 2 == 1 && flag == true)
		{
			for (int k = 0; k < m-1; k++)
				std::cout << ".";

			std::cout << "#" << std::endl;
			flag = !flag;
		}
		else if (i % 2 == 1 && flag == false)
		{
			std::cout << "#";
			for (int k = 0; k < m - 1; k++)
				std::cout << ".";

			std::cout << std::endl;
			flag = !flag;
		}
		else
		{
			for (int k = 0; k < m; k++)
				std::cout << "#";

			std::cout << std::endl;
		}
	}
}