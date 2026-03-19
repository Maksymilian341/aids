#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> generateSedgewickGaps(int n) {
    vector<int> gaps;
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

    reverse(gaps.begin(), gaps.end());
    return gaps;
}

void shellSortSedgewick(int arr[], int n) {
    vector<int> gaps = generateSedgewickGaps(n);

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

void shellSortSedgewick(vector<int>& arr) {
    shellSortSedgewick(arr.data(), (int)arr.size());
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    int arr1[] = {64, 2137, 34, 69, 420, 67, 25, 12, 22, 11, 67, 90, 88, 45, 67, 50};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Test" << endl;
    cout << "Originalny:";
    printArray(arr1, n1);
    shellSortSedgewick(arr1, n1);
    cout << "Posortowany:";
    printArray(arr1, n1);
    cout << endl;

    return 0;
}
