#include <iostream>
#include <vector>
using namespace std;

void merge(vector<long long> &vec,long long left,long long mid,long long right,long long &count){
    vector<long long> tmp;
    long long i=left,j=mid+1;
    while(i<=mid and j<=right){
        if(vec[i]<=vec[j]){
            tmp.push_back(vec[i]);
            i++;
        }else{//左大于右
            tmp.push_back(vec[j]);
            j++;
            count+=mid-i+1;
        }
        
    }
    while(i<=mid){
        tmp.push_back(vec[i]);
        i++;
    }
    while(j<=right){
        tmp.push_back(vec[j]);
        j++;
    }
    for(long long k=0;k<tmp.size();k++){
        vec[left+k]=tmp[k];
    }
}

void mergeSort(vector<long long> &vec,long long left,long long right,long long &count){
    if(left>=right){
        return;
    }
    long long mid = (left+right)/2;
    mergeSort(vec,left,mid,count);
    mergeSort(vec,mid+1,right,count);
    merge(vec,left,mid,right,count);
}



int main()
{
    long long len;
    cin>>len;
    vector<long long> vec;
    for(long long i=0;i<len;i++){
        long long n;
        cin>>n;
        vec.push_back(n);
    }
    long long count=0;
    mergeSort(vec,0,len-1,count);
    cout<<count;
    return 0;
}