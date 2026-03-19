#include <iostream>
#include <vector>

int partition(std::vector<int>& T,int p, int r)
{
    //int x = T[r];
    int x = T[p];
    //int x = rand() % T.size();
    int i = p;
    int j = r;
    while(true)
    {
        while(T[i] < x)
        {
            i++;
        }
        while(T[j] > x)
        {
            j--;
        }
        if(i <= j)
        {
            std::swap(T[i], T[j]);
            i++;
            j--;
        }
        else
            return j;
    }
}
void quick_sort(std::vector<int>& T, int p, int r)
{
    if(p < r)
    {
    int q = partition(T,p,r);
    quick_sort(T,p,q);
    quick_sort(T,q + 1,r);
    }
}
int main()
{
    std::vector<int> T = {3,4,5,2,1,6,7,9,10,8};
    int p = 0;
    int r = T.size() - 1;
    quick_sort(T,p,r);
    for(int i = 0;i < T.size();i++)
        std::cout << T[i] << " ";
    std::cout << std::endl; 
    return 0;
}