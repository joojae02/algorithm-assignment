#include <iostream>
#include <algorithm>

using namespace std;
#define INT_MAX 2147483647
int P[7][7];

int minmult(int n, const int d[], int P[7][7]) {
    int i, j, k, diagonal;
    int M[n+1][n+1];
    for(i=1; i <= n; i++)
        M[i][i] = 0;
    for(diagonal = 1; diagonal <= n-1; diagonal++)
        for(i=1; i <= n-diagonal; i++) {
            j = i + diagonal;
            M[i][j] = INT_MAX;
            int mink;
            for(k = i; k<= j -1 ; k++){
                if(M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j] < M[i][j]){
                    M[i][j] = M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j];
                    mink = k;   
                }
            }
            P[i][j] = mink;
        }
    // for(i=1; i <= n; i++){
    //     for(j =1; j< i; j++){
    //         cout.width(3);
    //         cout.fill(' ');
    //         cout << " ";
    //         cout << " ";
    //     }
    //     for(j=i; j <= n; j++){
    //         cout.width(3);
    //         cout.fill(' ');
    //         cout << M[i][j] << " ";
    //     }
    //     cout << endl;        
    // }
    return M[1][n];
}

void order(int i, int j) {
    if (i == j) cout << "A" << i;
    else {
        int k = P[i][j];
        cout << "(";
        order(i,k);
        order(k+1,j);
        cout << ")";
    }
}
int main(void) {
    int d[7] = {5,2,3,4,6,7,8};
    int n = 6;
    int minCost = minmult(6, d, P);
    cout << minCost << endl;
    int i, j;
    // for(i=1; i <= n; i++){
    //     for(j =1; j< i; j++){
    //         cout.width(3); 
    //         cout.fill(' '); 
    //         cout << " ";
    //         cout << " ";
    //     }
    //     for(j=i; j <= n; j++){
    //         cout.width(3); 
    //         cout.fill(' ');
    //         cout << P[i][j] << " ";
    //     }
    //     cout << endl;        
    // }
    order(2,5);
}