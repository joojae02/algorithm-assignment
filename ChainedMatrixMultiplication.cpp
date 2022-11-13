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
    for(diagonal = 1; diagonal <= n-1; diagonal++){
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
        cout <<" M[][]" << endl;        

        for(int o=1; o <= n; o++){
            for(int u =1; u< o; u++){
                cout.width(3);
                cout.fill(' ');
                cout << " ";
                cout << " ";
            }
            for(int u=o; u <= n; u++){
                cout.width(3);
                cout.fill(' ');
                cout << M[o][u] << " ";
            }
            cout << endl;        
        }
        cout <<" P[][] " << endl;        

        for(int o=1; o <= n; o++){
            for(int u =1; u< o; u++){
                cout.width(3);
                cout.fill(' ');
                cout << " ";
                cout << " ";
            }
            for(int u=o; u <= n; u++){
                cout.width(3);
                cout.fill(' ');
                cout << P[o][u] << " ";
            }
            cout << endl;        
        }
    }
    // M[][] P[][] 출력
    cout << endl;        
    cout << endl;        
    
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
    int d[7] = {6,5,2,3,7,4,9};
    int n = 6;
    int minCost = minmult(6, d, P);
    cout << minCost << endl;
    int i, j;

    order(1,6);
}