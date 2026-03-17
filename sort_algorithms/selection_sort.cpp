#include <iostream>
#include <string>

int main()
    {
    const int N = 10;
    int T[N] = {10,5,4,2,3,1,6,7,8,9};
    int min = 0;
    for(int i = 0;i < N - 1;i++)
    {
        min = i;
        for(int j = i + 1; j < N;j++)
        {
            if(T[j] < T[min])
            {
                min = j;
            }
        }
        int temp = T[min];
        T[min] = T[i];
        T[i] = temp;
    }
    for(int i = 0;i < N;i++)
    {
        std::cout << T[i] << " ";
    }
    std::cout << std::endl; 
    return 0;
    }