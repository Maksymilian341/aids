#include <iostream>
#include <string>

void selection_sort(std::vector<int>& T)
{
    int min = 0;
    for(int i = 0;i < T.size() - 1;i++)
    {
        min = i;
        for(int j = i + 1; j < T.size();j++)
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
}
int main()
    {
    std::vector<int> T = {10,5,4,2,3,1,6,7,8,9};
    selection_sort(T);
    for(int i = 0;i < T.size();i++)
        std::cout << T[i] << " ";
    std::cout << std::endl; 
    return 0;
    }