#include <iostream>
#include <string>

using namespace std;
int main()
{
    int T[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 0;
    int i = 0;
    for(int j = 2;j <= sizeof(T);j++)
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
    cout << T;
}