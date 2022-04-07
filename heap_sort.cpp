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

void heapify(int a[], int root, int n){
    int l = 2*root + 1;//left node
    int r = 2*root + 2;//right node

    int largest = root;

    if (l < n && a[l] > a[largest]){
        largest = l;
    }
    if (r < n && a[r] > a[largest]){
        largest = r;
    }
    if (largest != root){
        swap(a, root, largest);
        heapify(a,largest,n);//push the node at the right place
    }
}

void heap_sort(int a[], int n){
    //build max heap
    for (int i = min(n/2,n-1)  ; i >=0 ; i --){
        heapify(a,i,n);
    }
    //extract top element of max heap and rearrange max heap
    for (int i = n-1 ; i > 0; i --){
        swap(a,0,i);
        heapify(a,0,i);
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
    heap_sort(a,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Execution time for heap sort: " << float(duration.count())*scale <<  " secs" << endl;
}