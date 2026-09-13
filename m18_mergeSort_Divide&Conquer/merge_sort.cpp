#include <bits/stdc++.h>
using namespace std;

void conquer(int arr[], int l, int mid, int r) { // O(N)
    int n = mid - l + 1;
    int a[n];
    int k = l;
    for(int i = 0; i < n; i++) a[i] = arr[k++];

    int m = r - mid;
    int b[m];
    k = mid+1;
    for(int i = 0; i < m; i++) b[i] = arr[k++];

    // Conquer
    int left = 0, right = 0, cur = l;
    while(left < n && right < m) {
        if(a[left] <= b[right]) arr[cur++] = a[left++];
        else arr[cur++] = b[right++];
    }

    while(left < n) arr[cur++] = a[left++];
    while(right < m) arr[cur++] = b[right++];
}

void divide(int arr[], int l, int r) { // O(Log N)
    if(l == r) return;

    int mid = (l+r)/2;
    divide(arr, l, mid);
    divide(arr, mid+1, r);

    conquer(arr, l, mid, r);
}

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    divide(arr, 0, n-1); // O(N Log N)

    // Printing
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}