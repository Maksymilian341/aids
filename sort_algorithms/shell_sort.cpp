#include <iostream>
#include <vector>

using namespace std;

vector<int> generateSedgewickGaps(int n) {
    vector<int> gaps;
    int h = 1;

    while (h < n / 3) {
        gaps.push_back(h);
        h = 3 * h + 1;
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
