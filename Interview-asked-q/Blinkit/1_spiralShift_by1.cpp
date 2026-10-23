/*
1 2 3 4 5 
6 7 8 9 7
5 4 3 2 1
9 8 7 5 3

   scol    ecol
    |       |
 -  1 2 3 4 5    srow
    6 7 8 9 7
    5 4 3 2 1
 -  9 8 7 5 3    erow

After shift 1

6 1 2 3 4
5 4 7 8 5
9 3 2 9 7
8 7 5 3 1

*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5},
                  {6, 7, 8, 9, 7},
                  {5, 4, 3, 2, 1},
                  {9, 8, 7, 5, 3}};
    int srow = 0, scol = 0, erow = matrix.size()-1, ecol = matrix[0].size()-1;

    while(srow<=erow && scol<=ecol){
        int currElement = matrix[srow][scol];
        // left -> right
        for(int i=scol+1; i<=ecol; i++){
            swap(matrix[srow][i], currElement);
        }
        // top -> bottom
        for(int i=srow+1; i<=erow; i++){
            swap(matrix[i][ecol], currElement);
        }
        // right -> left
        for(int i=ecol-1; i>=scol; i--){
            swap(matrix[erow][i], currElement);
        }
        // bottom -> top
        for(int i=erow-1; i>=srow; i--){
            swap(matrix[i][scol], currElement);
        }
        // Add the last element of iteration to the 1st place
        swap(currElement, matrix[srow][scol]);

        srow++; scol++;
        erow--; ecol--;
    }

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}