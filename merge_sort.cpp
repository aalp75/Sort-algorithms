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

void merge(int a[], int first, int mid, int last){
    int len = last - first +1;
    int res[len];
    int i = 0 ;//iterate on 1st array
    int j = 0 ;//iterate on second array
    int n1 = mid - first +1;//length first array
    int n2 = last - mid;//length second array
    while(i < n1 && j < n2){//compare element of first array vs second array
        if (a[first+i] < a[mid + 1 + j]){
            res[i+j] = a[first+i];
            i ++;
        }
        else{
            res[i+j] = a[mid+1+j];
            j++;
        }
    }
    if (i == n1){//fill with last values of second array
        while (j < n2){
            res[i+j] = a[mid+1+j];
            j++;
        }
    }
    if (j == n2){//fill with last values of first array
        while (i < n1){
            res[i+j] = a[first+i];
            i++;
        }
    }
    //copy new array in original array
    for (int i = 0 ; i < len ; i ++){
        a[first+i] = res[i];
    }
}

void merge_sort(int a[], int first, int last){
    if (first < last){
        int mid = (first+last)/2;
        merge_sort(a, first, mid);
        merge_sort(a, mid +1, last);
        merge(a, first, mid , last);
    }
}

int main(){
    int n;
    ifstream inputfile("input.txt");
    if (!inputfile.is_open()) 
        cout<<"Error opening file" << endl; ;
    inputfile >> n ;
    int a[n];
    for (int i = 0 ; i < n; i ++){
        inputfile >> a[i];
    }
    float scale = 1e-6;
    auto start = high_resolution_clock::now();
    merge_sort(a,0,n-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Execution time for merge sort: " << float(duration.count())*scale <<  " secs" << endl;
    //show(a,n);
}