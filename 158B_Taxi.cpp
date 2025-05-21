// https://codeforces.com/problemset/problem/158/B
#include <iostream>

int main()
{
    int n, s, count{ 0 };
    int group[5] = { 0,0,0,0,0 }; 
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
