#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int len;
    cin>>len;
    vector<int> vec;
    for(int i=0;i<len;i++){
        int n;
        cin>>n;
        vec.push_back(n);
    }
    int count=0;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(vec[i]>vec[j]){
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}