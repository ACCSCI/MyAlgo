#include<iostream>
#include<vector>

using namespace std;
void printVec(vector<int> &vec){
    for (auto i : vec){
        cout<<i<<" ";
    }
    cout<<endl;
}
void findKth(vector<int> &vec,int k,int start,int end){
    if(k<0 or k>vec.size()-1){
        return;
    }
    if(start >= end ){
        // printVec(vec);
        cout<<vec[start];
        return;
    }
    int i=start,j=end;
    while(i<j){
        while(i<j and vec[j]>=vec[start]){
            j--;
        }
        while(i<j and vec[i]<=vec[start]){
            i++;
        }
        swap(vec[i],vec[j]);
    }
    swap(vec[start],vec[i]);
    if(i==k){
        // printVec(vec);
        cout<<vec[i];
        return;
    }else if(i<k){
        findKth(vec,k,i+1,end);
    }else if(i>k){
        findKth(vec,k,start,i-1);
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> vec;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        vec.push_back(num);
    }
    findKth(vec,k-1,0,n-1);
    return 0;
}