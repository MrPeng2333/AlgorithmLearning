#include<bits/stdc++.h>
using namespace std;

int partition(int l, int r, int arr[]) {
    int tmp = arr[l];
    int i = l, j = r;
    while (i < j) {
        while (i < j && arr[j] >= tmp) j--;
        swap(arr[j], arr[i]);
        while (i < j && arr[i] < tmp) i++;
        swap(arr[i], arr[j]);
    }
    arr[i] = tmp;
    return i;
} 

void QuickSort(int l, int r, int arr[]) {
    if (l >= r) return;
    int pivot = partition(l, r, arr);
    QuickSort(l, pivot, arr);
    QuickSort(pivot + 1, r, arr);
}

int main() {
    int arr[7] = {2, 5, 3, 9, 7, 12, 4};
    QuickSort(0, 6, arr);
    for (int i = 0; i < 7; i++)
        printf("%d ", arr[i]);
    printf("\nDone");
    return 0;
}