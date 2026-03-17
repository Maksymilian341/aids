#include <iostream>
#include <string>

int main()
    {
    const int N = 10;
    int T[N] = {10,5,4,2,3,1,6,7,8,9};
    int key = 0;
    int i = 0;
    for(int j = 1;j < N;j++)
    {
        key = T[j];
        i = j - 1;
        while(i >= 0 &&  T[i] > key)
        {
            T[i + 1] = T[i];
            i = i - 1;
        }
        T[i + 1]=key;
    }
    for(int i = 0;i < N;i++)
    {
        std::cout << T[i] << " ";
    }
    std::cout << std::endl; 
    return 0;
    }