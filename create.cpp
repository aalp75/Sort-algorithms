#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int max = 100;
    int min = -max;
    int n = 1e5;
    freopen("input.txt","w",stdout);
    cout << n << endl;
    for (int i = 0 ; i < n ; i ++){
        if (rand() %2 == 0){
            cout << rand() % max << " ";
        }
        else{
            cout << - (rand() % max) << " ";
        }
    }
    return 0;
}