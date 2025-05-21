//#include <iostream>
//#include <string>
//
//
//void out(const int* ptr, int size)
//{
//	std::cout << "Massiv: " << std::endl;
//	for (size_t i = 0; i < size; ++i)
//	{
//		std::cout << ptr[i] << " ";
//	}
//	std::cout << std::endl;
//}
//
//int find_Max(int* ptr, int size)
//{
//	int max, max_2, max_i{ 0 }, max_i2{0};
//	max = ptr[0];
//	max_2 = 0;
//
//	for (int i = 0; i < size; i++)
//	{
//		if (ptr[i] == 0) continue;
//		//проверка что нечетное
//		if (ptr[i] % 2 == 1)
//		{
//			//находим максимальное нечетное
//			if (max < ptr[i])
//			{
//				max = ptr[i];
//				max_i = i;
//			}
//
//		}
//		//если четное
//		else
//		{
//			//находим максимальное четное
//			if (max_2 < ptr[i])
//			{
//				max_2 = ptr[i];
//				max_i2 = i;
//			}
//
//		}
//		//в конце нахождения максимальных, увеличиваем на 1 и уменьшаем на 1
//		if (i == size - 1)
//		{
//			if (ptr[max_i] > ptr[max_i2])
//			{
//				ptr[max_i]++;
//				ptr[max_i2]--;
//			}
//			else
//			{
//				ptr[max_i]--;
//				ptr[max_i2]++;
//			}
//			
//		}
//	}
//
//	return max + max_2;
//}
//int main()
//{
//	int t, n;
//	int* ptr;
//
//	std::cin >> t;
//
//	while (t--)
//	{
//		std::cin >> n;
//		ptr = new int[n];
//
//		for (size_t i = 0; i < n; ++i)
//		{
//			std::cin >> ptr[i];
//		}
//
//		int k = find_Max(ptr, n);
//		for(size_t i = 0; i < k-1; ++i)
//		{
//			find_Max(ptr, n);
//		}
//		
//		out(ptr, n);
//		
//		delete[] ptr;
//	}
//}
//	

#include <iostream>

int main()
{
    int n, s, group[5] = { 0,0,0,0,0 }, count{ 0 };
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> s;
        group[s]++;
    }

    //надо машина для 4-х и для каждых 3-х
    count += group[4] + group[3];

    //когда 1-ниц > 3-шек
    if (group[1] > group[3])
        group[1] = group[1] - group[3];
    //когда 3-шек > 1-ниц
    else
    {
        group[1] = group[1] - group[3];
        //отрицательным быть не может
        if (group[1] < 0)
            group[1] = 0;
    }

    //для каждых двоих в группе, одна машина, и одна машина для одиночной пары
    if (group[2] % 2 == 0)
        count += group[2] / 2;
    else
        count += (group[2] - 1) / 2 + 1;

    //садим одного в машину что оставался без пары с двумя единицами, иначе с теми что остались
    if (group[2] % 2 == 1)
    {
        if(group[1] >= 2)
            group[1] = group[1] - 2;
        else
        {
            group[1] = group[1] - 2;
            //отрицательным быть не может
            if (group[1] < 0)
                group[1] = 0;
        }
    }

    //формула округления вверх (a+ (b-1)) / b == a / b 
    //считаем машины для оставшихся 1-ниц
    count += (group[1] + 3) / 4;

    std::cout << count << std::endl;
    return 0;
}
