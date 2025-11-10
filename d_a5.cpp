#include<bits/stdc++.h>
using namespace std;


int partitionDet(int low, int high, vector<int> &arr) {
    int pivot = arr[low]; 
    int i = low;
    int j = high;

    while(i < j) {
        while(arr[i] <= pivot && i < high) i++;
        while(arr[j] > pivot && j > low) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSortDet(vector<int> &arr, int low, int high) {
    if(low < high) {
        int pindex = partitionDet(low, high, arr);
        quickSortDet(arr, low, pindex - 1);
        quickSortDet(arr, pindex + 1, high);
    }
}

int partitionRand(int low, int high, vector<int> &arr) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[low], arr[randomIndex]); 
    return partitionDet(low, high, arr); 
}

void quickSortRand(vector<int> &arr, int low, int high) {
    if(low < high) {
        int pindex = partitionRand(low, high, arr);
        quickSortRand(arr, low, pindex - 1);
        quickSortRand(arr, pindex + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n), arr2(n);
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    arr2 = arr; 

  
    quickSortDet(arr, 0, n - 1);
    srand(time(0)); 
    quickSortRand(arr2, 0, n - 1);

    cout << "\nSorted using Deterministic Quick Sort:\n";
    for(int x : arr) cout << x << " ";

    cout << "\n\nSorted using Randomized Quick Sort:\n";
    for(int x : arr2) cout << x << " ";

    cout << "\n";
    return 0;
}
