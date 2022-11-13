#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct nodetype {
    float key;
    nodetype* left;
    nodetype* right;
};

typedef nodetype* node_pointer;
int R[6][5];
float key[5] = {0, 3.0/8.0, 2.0/8.0, 2.0/8.0, 1.0/8.0};

int level  = 0;
int tmp = 0;
int tmp2 = 0;
void optsearchtree(int n, const float p[5], float& minavg, int R[6][5]) {
    int i, j, k, diagonal,mink;
    float min,sum;
    float A[n+2][n+1] = {0,};
    for(i=1; i<=n; i++) {
        A[i][i-1] = 0; A[i][i] = p[i]; R[i][i] = i; R[i][i-1] = 0; 
    }
    A[n+1][n] = 0; R[n+1][n] = 0;

    for(diagonal=1; diagonal<= n-1; diagonal++){
        for(i=1; i <= n-diagonal; i++) {
            j = i + diagonal;
            min = 10000;
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
        
    }
    // 테스트 출력
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
    minavg = A[1][n];
}

node_pointer tree(int i, int j) {
    int k;
    node_pointer p;
    k = R[i][j];
    if(k==0)
        return NULL;
    else{
        p = new nodetype;
        p -> key = key[k];
        p -> left = tree(i, k-1);
        p -> right = tree(k+1, j);
        return p;
    }
}

void preorder(struct nodetype* T) {
	if (T != NULL) {
		printf(" %f -> ", T->key);
		printf("%d level", level);

		if (level == 0) //root
			printf("(root)");

		else if (level != 0 && tmp2 == 0) //left, right 구별
			printf("(left)");
		else if (level != 0 && tmp2 == 1)
			printf("(right)");
		printf("\n");
		level++;
		tmp2 = 0;
		preorder(T->left);
		level++;
		tmp2 = 1;
		preorder(T->right);
	}

	else {
		tmp++;
		level--;

		if (tmp == 2) {
			level--;
			tmp = 0;
		}
	}
}
int main(void) 
{   
    int n = 4;
    float min = 0;
    float p[5] = {0, 3.0/8.0, 3.0/8.0, 1.0/8.0, 1.0/8.0};
    optsearchtree(n, p, min, R);
    cout<< min << endl;
    node_pointer t = tree(1,4);
    //inorder(t);
    preorder(t);
}