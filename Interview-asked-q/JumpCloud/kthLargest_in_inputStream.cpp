/*
Real Life usecase is : Backend Monitoring or E-commerce etc.
Where we need to rank a real time data 


APPROACH : 

TC : O(n logk)[logk -> min heap processing , n = input size ] SC : O(k) [min heap]

1. track the top k largest elements using a min heap 
2. As the input comes if the element is greater than the minimum valued element in the min heap 
   we put that one instead of the lesser element in min heap
3. lastly we return the min heap top element which is the kth largest element.
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int k; // k>0
    cin >>k;
    priority_queue<int, vector<int>, greater<int>> pq;
    int x;

    while(cin >> x){
        if(pq.size() < k){
            pq.push(x);
        }else if(x>pq.top()){
            pq.pop();
            pq.push(x);
        }

        if(pq.size() == k){
            cout<< "For x : "<< x <<" "<< k<<"th max = " <<pq.top()<<"\n";
        }
    }

    

    return 0;
}