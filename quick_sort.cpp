#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void show(int a[], int n){
    for (int i = 0 ; i < n ;i ++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void swap(int a[], int i, int j){
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int partition(int a[], int first, int last){
    int j = first;
    for (int i = first ; i < last  ; i ++){
        if (a[i] < a[last]){
            swap(a,i,j);
            j++;
        }
    }
    swap(a,j,last);
    return j ;
}

void quick_sort(int a[], int first, int last){
    if (first < last){
        int pivot = partition(a,first,last);
        quick_sort(a, first, pivot-1);
        quick_sort(a, pivot + 1, last);
    }
}

int main(){
    int n;
    ifstream inputfile("input.txt");
    if (!inputfile.is_open()) 
        cout<<"Error opening file" << endl;
    inputfile >> n ;
    int a[n];
    for (int i = 0 ; i < n; i ++){
        inputfile >> a[i];
    }
    float scale = 1e-6;
    auto start = high_resolution_clock::now();
    quick_sort(a,0,n-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Execution time for quick sort: " << float(duration.count())*scale <<  " secs" << endl;
}