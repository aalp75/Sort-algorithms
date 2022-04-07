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

void insertion_sort(int a[], int n){
    for (int i = 1 ; i < n ; i ++){
        int j = i;
        while (j> 0 && a[j] < a[j-1]){
            swap(a,j,j-1);
            j--;
        }
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
    insertion_sort(a,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Execution time for insertion sort: " << float(duration.count())*scale <<  " secs" << endl;
}