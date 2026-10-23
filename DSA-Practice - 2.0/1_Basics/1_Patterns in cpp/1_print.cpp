#include<iostream>
#include<chrono>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<"Hello !!!";
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i< 100000; i++){
        cout << "\nThis is loop: " << i;
    }
    auto end = chrono::high_resolution_clock::now();

    auto start1 = chrono::high_resolution_clock::now();
    for(int i = 0; i< 100000; i++){
        cout <<endl << "This is loop: " << i;
    }
    auto end1 = chrono::high_resolution_clock::now();
    cout<<"\n \\n Time : "<< chrono::duration_cast<chrono::milliseconds>(end - start).count()<< " ms";

    cout<<"\nEndl Time : "<< chrono::duration_cast<chrono::milliseconds>(end1 - start1).count()<< " ms";
    return 0;
}