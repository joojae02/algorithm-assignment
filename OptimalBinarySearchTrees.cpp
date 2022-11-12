#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
#define INT_MAX 2147483647

void optsearchtree(int n, const float p[5], float& minavg, int R[6][5]) {
    int i, j, k, diagonal, min, sum, mink;
    float A[n+1][n];
    for(i=1; i<=n; i++) {
        A[i][i-1] = 0; A[i][i] = p[i]; R[i][i] = i; R[i][i-1] = 0; 
    }
    A[n+1][n] = 0; R[n+1][n] = 0;

    for(diagonal=1; diagonal<= n-1; diagonal++){
        for(i=1; i <= n-diagonal; i++) {
        j = i + diagonal;
        min = INT_MAX;
        sum = 0;
        mink = i;
        for(k = i; k <= j; k++){
            if(min > (A[i][k -1] + A[k+1][j])){
                min = A[i][k -1] + A[k+1][j];
                mink = k;
            }
            sum += p[k];
        }
        
        A[i][j] = min + sum;
        R[i][j] = mink;
        }
        for(int q = 1; q <= n+1; q++){
            for(int w = 0; w < q - 1; w++){
                cout.precision(4);
                cout <<"  ";
            }
            for(int w = q -1; w <= n; w++)
            {
                cout.precision(4);
                cout<<A[q][w] << " ";
            }
            cout<<endl;
        }
        cout<<endl;

        for(int q = 1; q <= n+1; q++){
            for(int w = 0; w < q - 1; w++){
                cout.precision(4);
                cout <<"  ";
            }
            for(int w = q -1; w <= n; w++)
            {
                cout.precision(4);
                cout<<R[q][w] << " ";
            }
            cout<<endl;
        }
    }
    
    minavg = A[1][n];
}

int main(void) 
{
    float p[5] = {0, 3.0/8.0, 3.0/8.0, 1.0/8.0, 1.0/8.0};
    int R[6][5];
    int n = 4;
    float min;
    
    optsearchtree(n, p, min, R);

}