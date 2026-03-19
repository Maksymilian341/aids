#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>

void random_arr(std::vector<int>& T,int n)
{
    for(int i = 0; i < n; i++)
    {
    int r = rand() % 101;
    T.push_back(r);
    }
}

void ros_arr(std::vector<int>& T,int n)
{
    for(int i = 0; i < n; i++)
    {
    int r = rand() % 101;
    T.push_back(r);
    }
    std::sort(T.begin(),T.end());
}

void mal_arr(std::vector<int>& T,int n)
{
    for(int i = 0; i < n; i++)
    {
    int r = rand() % 101;
    T.push_back(r);
    }
    std::sort(T.begin(),T.end());
    std::reverse(T.begin(),T.end());
}

void sta_arr(std::vector<int>& T,int n)
{
    int r = rand() % 101;
    for(int i = 0; i < n; i++)
    {
        T.push_back(r);
    }
}

void A_arr(std::vector<int>& T,int n)
{
    std::vector<int> B;
    int t;
    int b;
    if(n%2==0)
    {
        t = n/2;
        b = n/2;
    }
    else
    {
        t = n/2 + 1;
        b = n/2;
    }
    for(int i = 0; i < t; i++)
    {
    int r = rand() % 50;
    T.push_back(r);
    }
    std::sort(T.begin(),T.end());

    for(int i = 0; i < b; i++)
    {
    int r = rand() % 50;
    B.push_back(r);
    }
    std::sort(B.begin(),B.end());
    std::reverse(B.begin(),B.end());

    T.insert(T.end(),B.begin(),B.end());
}

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

std::vector<int> generateSedgewickGaps(int n) {
    std::vector<int> gaps;
    int k = 0;

    while (true) {
        int gap;

        if (k % 2 == 0)
            gap = 9 * (pow(2, k) - pow(2, k / 2)) + 1;
        else
            gap = 8 * pow(2, k) - 6 * pow(2, (k + 1) / 2) + 1;

        if (gap > n)
            break;

        gaps.push_back(gap);
        k++;
    }

    std::reverse(gaps.begin(), gaps.end());
    return gaps;
}

void shellSortSedgewick(std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> gaps = generateSedgewickGaps(n);

    for (int gap : gaps) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
/*
void shellSortSedgewick(std::vector<int>& arr) {
    shellSortSedgewick(arr.data(), (int)arr.size());
}
*/
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

void kopiec(std::vector<int>& T,int n,int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

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

void kopiec_sort(std::vector<int>& T)
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


int partition(std::vector<int>& T,int p, int r)
{
    //int x = T[r];
    //int x = T[p];
    //int x = rand() % T.size();
    int x = T[p + (r - p) / 2];
    int i = p;
    int j = r;
    while(i <= j)
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
    }
    return i;
}
void quick_sort(std::vector<int>& T, int p, int r)
{
    if(p < r)
    {
    int q = partition(T,p,r);
    if(p < q - 1) 
    quick_sort(T,p,q-1);
    if(q < r) 
    quick_sort(T,q,r);
    }
}

int main()
{
srand(time(NULL));
int n;
int m;
int al;
std::vector<int> T;
std::cout<<"Podaj liczbe elementow tablicy"<<std::endl;
std::cin>>n;
std::cout<<"Wybierz rodzaj tablicy:"<<std::endl<<"1 - losowy"<<std::endl<<"2 - rosnacy"<<std::endl<<"3 - malejacy"<<std::endl<<"4 - staly"<<std::endl<<"5 - A-ksztaltny"<<std::endl;
std::cin>>m;
switch(m)
{
case 1:
    random_arr(T,n);
    std::cout<<"Tablica została wygenerowana"<<std::endl;
    for(int i = 0;i < T.size();i++)
        std::cout << T[i] << " ";
    std::cout << std::endl; 
    break;
case 2:
    ros_arr(T,n);
    std::cout<<"Tablica została wygenerowana"<<std::endl;
    for(int i = 0;i < T.size();i++)
        std::cout << T[i] << " ";
    std::cout << std::endl;
    break;
case 3:
    mal_arr(T,n);
    std::cout<<"Tablica została wygenerowana"<<std::endl;
    for(int i = 0;i < T.size();i++)
        std::cout << T[i] << " ";
    std::cout << std::endl;
    break;
case 4:
    sta_arr(T,n);
    std::cout<<"Tablica została wygenerowana"<<std::endl;
    for(int i = 0;i < T.size();i++)
        std::cout << T[i] << " ";
    std::cout << std::endl;
    break;
case 5:   
    A_arr(T,n);
    std::cout<<"Tablica została wygenerowana"<<std::endl;
    for(int i = 0;i < T.size();i++)
        std::cout << T[i] << " ";
    std::cout << std::endl;    
    break;
}

std::cout<<"Wybierz rodzaj algorytmu:"<<std::endl<<"1 - insertion"<<std::endl<<"2 - shell"<<std::endl<<"3 - selection"<<std::endl<<"4 - heap"<<std::endl<<"5 - quick"<<std::endl;
std::cin>>al;
switch(al)
{
case 1:
    insertion_sort(T);
    std::cout<<"Posortowany ciąg"<<std::endl;
    for(int i = 0;i < T.size();i++)
        std::cout << T[i] << " ";
    std::cout << std::endl; 
    break;

case 2:

    shellSortSedgewick(T);
    std::cout<<"Posortowany ciąg"<<std::endl;
    for(int i = 0;i < T.size();i++)
        std::cout << T[i] << " ";
    std::cout << std::endl; 
    break;

case 3:
    selection_sort(T);
    std::cout<<"Posortowany ciąg"<<std::endl;
    for(int i = 0;i < T.size();i++)
        std::cout << T[i] << " ";
    std::cout << std::endl; 
    break;
case 4:
    kopiec_sort(T);
    std::cout<<"Posortowany ciąg"<<std::endl;
    for(int i = 0;i < T.size();i++)
        std::cout << T[i] << " ";
    std::cout << std::endl; 
    break;
case 5:
    {
    int p = 0;
    int r = T.size() - 1;
    quick_sort(T,p,r);
    std::cout<<"Posortowany ciąg"<<std::endl;
    for(int i = 0;i < T.size();i++)
        std::cout << T[i] << " ";
    std::cout << std::endl; 
    }
    break;
}
return 0;
}