#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int n,q[100010]={0};

void qs(int *vec,int left,int right){
    if(left >= right){
        return;
    }
    int pivotIndex = left + rand() % (right - left + 1);
    swap(vec[left], vec[pivotIndex]);

    int i=left,j=right;
    while(i<j){
        while(i<j and vec[j] >=vec[left]){
            j--;
        }
        while(i<j and vec[i]<=vec[left]){
            i++;
        }
        swap(vec[i],vec[j]);
    }
    swap(vec[left],vec[j]);
    qs(vec,left,j-1);
    qs(vec,j+1,right);
}


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    qs(q,0,n-1);
    for(int i=0;i<n;i++) cout<<q[i]<<' ';
    return 0;
}