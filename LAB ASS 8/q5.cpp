#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool increasing) {
    int extreme = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (increasing) {
        if (l < n && arr[l] > arr[extreme]) extreme = l;
        if (r < n && arr[r] > arr[extreme]) extreme = r;
    } else {
        if (l < n && arr[l] < arr[extreme]) extreme = l;
        if (r < n && arr[r] < arr[extreme]) extreme = r;
    }
    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, increasing);
    }
}

void heapsort(int arr[], int n, bool increasing = true) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, increasing);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, increasing);
    }
    if (!increasing) {
        for (int i = 0; i < n / 2; i++)
            swap(arr[i], arr[n - i - 1]);
    }
}

int main() {
    int arr[] = {4, 7, 1, 3, 9, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapsort(arr, n, true);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    heapsort(arr, n, false);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
