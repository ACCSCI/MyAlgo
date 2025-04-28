#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &vec){
    for(auto i:vec){
        cout<<i<<" ";
    }
    cout<<endl;
}

void merge(vector<int> &vec,int left,int mid,int right){
    //左序列[left,mid],右序列[mid+1,right]
    //创建一个临时序列保存结果
    vector<int> tmp(right-left+1);
    
    int i=left,j=mid+1,t=0;
    while(i<=mid and j<=right){
        if(vec[i]<=vec[j]){
            tmp[t]=vec[i];
            t++;
            i++;
        }else{
            tmp[t]=vec[j];
            t++;
            j++;
        }
    }
    while (i<=mid)
    {
        tmp[t]=vec[i];
        t++;
        i++;
    }
    while(j<=right){
        tmp[t]=vec[j];
        t++;
        j++;
    }
    for(int i=0;i<tmp.size();i++){
        vec[left+i]=tmp[i];
    }
}

void mergeSort(vector<int> &vec,int left,int right){
    if(left>=right){
        return;
    }
    int mid = (left + right)/2;
    mergeSort(vec,left,mid);
    mergeSort(vec,mid+1,right);
    merge(vec,left,mid,right);
   
}
int main()
{
    int len;
    cin>>len;
    vector<int> vec;
    for(int i=0;i<len;i++){
        int k;
        cin>>k;
        vec.push_back(k);
    }
    mergeSort(vec,0,vec.size()-1);
    printVec(vec);
    return 0;
}