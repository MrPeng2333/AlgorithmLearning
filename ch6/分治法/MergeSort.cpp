#include<bits/stdc++.h>
using namespace std;

void merge(int l, int m, int r, int arr[]) {
    int i = l, j = m + 1, k = 0;
    int len = r - l + 1;
    int tmp[len];
    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }
    while (i <= m) tmp[k++] = arr[i++];
    while (j <= r) tmp[k++] = arr[j++];
    k = 0; i = l;

    while (k < len) arr[i++] = tmp[k++];
}

void MergeSort(int l, int r, int arr[]) {
    if (l == r) return;
    int m = (l + r) / 2;
    MergeSort(l, m, arr);
    MergeSort(m + 1, r, arr);
    merge(l, m, r, arr);
}

int main() {
    int arr[7] = {2, 5, 3, 9, 7, 12, 4};
    MergeSort(0, 6, arr);
    for (int i = 0; i < 7; i++)
        printf("%d ", arr[i]);
    printf("\nDone");
    return 0;
}