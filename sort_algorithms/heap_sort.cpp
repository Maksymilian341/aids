#include <iostream>
#include <vector>

void kopiec(std::vector<int>& T,int n,int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && T[left] > T[largest])
        largest = left;

    if (right < n && T[right] > T[largest])
        largest = right;
    
    if (largest != i)
    {
        std::swap(T[i], T[largest]);
        kopiec(T,n,largest);
    }

}

void kopiecsort(std::vector<int>& T)
{
    int n = T.size();
    for(int i = n / 2 - 1; i >= 0; i--)
        kopiec(T,n,i);
    
    for(int i = n - 1; i > 0; i--)
    {
        std::swap(T[0],T[i]);
        kopiec(T,i,0);
    }
}

int main()
{
    std::vector<int> T = {5,3,2,1,7,10,4,9,8,6};
    kopiecsort(T);
    for(int i = 0; i < T.size(); i++)
        std::cout << T[i] << " ";
    std::cout<<std::endl;
    }