
#include <iostream>
#include <string>
#include <sstream>


using namespace std;
#define MAX 10000
struct edge{
    int v1, v2;
    int size;
};
void dijkstra (int n, int W[5][5], edge F[5]) {
    int i=0, vnear=0;
    int num=0;
    int s=0;
    edge e={0,};
    int* touch=new int[n-1]; 
    int* length=new int[n-1];

    for(i=0; i < n-1; i++) {  
        touch[i] = 0;   
        length[i] = W[0][i+1];   
    }

    while(num<n-1) {   
        int min = 10000;
        for(i=0; i < n-1; i++) {   
            if (0 <= length[i] && length[i] <= min) {
                min = length[i];
                vnear = i+1;
            }
        }
        e.v1=touch[vnear-1]+1;
        e.v2=vnear+1;
        e.size=W[touch[vnear-1]][vnear];
        F[s]=e;
        s++;
        for(i=0; i < n-1; i++) {
            if (length[vnear-1] + W[vnear][i+1] < length[i]) {
                length[i] = length[vnear-1] + W[vnear][i+1];
                touch[i] = vnear;   
                cout<<"length "<<i<<" : "<<length[i]<<endl;

            }   
        }
        length[vnear-1] = -1;

        cout<<"vnear : "<<vnear<<endl;

        for(int i=0;i<n-1;i++){
            cout<<"(V"<<F[i].v1<<", V"<<F[i].v2<<") "<<F[i].size<<endl;
        }
        for(int i=0;i<n-1;i++){
            cout<< "touch " << i << ": " <<touch[i] <<endl;
        }
        for(int i=0;i<n-1;i++){
            cout<< "length " << i << ": " <<length[i] <<endl;
        }
        cout<<endl;
        num++;   
    }
    for(int i=0;i<n-1;i++){
        cout<<"(V"<<F[i].v1<<", V"<<F[i].v2<<") "<<F[i].size<<endl;
    }
}

int main(){
    int num=0;
    int number = 5;

    int tok=0;
    int W[5][5] = {
        {0, 6, 3, 1, 8},
        {MAX, 0, MAX, MAX, 5},
        {MAX, 2, 0, MAX, MAX},
        {MAX, MAX, MAX, 0, 5},
        {MAX, MAX, MAX, MAX, 0}
        // {0, 7, 4, 6, 1},
        // {MAX, 0, MAX, MAX, MAX},
        // {MAX, 2, 0, 6, MAX},
        // {MAX, 3, MAX, 0, MAX},
        // {MAX, MAX, MAX, 1, 0}
    };
    
    edge F[5] = {0,};
    dijkstra (number, W, F);


    return 0;

}