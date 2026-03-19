#include <iostream>
#include <string>

void insertion_sort(std::vector<int>& T)
{
    int key = 0;
    int i = 0;
    for(int j = 1;j < T.size();j++)
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
}
int main()
    {
    std::vector<int> T = {10,5,4,2,3,1,6,7,8,9};
    insertion_sort(T);
    for(int i = 0;i < T.size();i++)
        std::cout << T[i] << " ";
    std::cout << std::endl; 
    return 0;
    }