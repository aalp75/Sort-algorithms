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

void bubble_sort(int a[], int n){
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < n-i-1 ; j ++){
            if (a[j] > a[j+1]){
                swap(a,j,j+1);
            }
        }
    }
}

// int main(){
//     int n;
//     ifstream inputfile("input.txt");
//     if (!inputfile.is_open()) 
//         cout<<"Error opening file" << endl; ;
//     inputfile >> n ;
//     int a[n];
//     for (int i = 0 ; i < n; i ++){
//         inputfile >> a[i];
//     }
//     float scale = 1e-6;
//     auto start = high_resolution_clock::now();
//     bubble_sort(a,n);
//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(stop - start);
//     cout << "Execution time for bubble sort: " << float(duration.count())*scale <<  " secs" << endl;
// }