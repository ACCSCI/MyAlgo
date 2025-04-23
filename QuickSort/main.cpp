#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &vec){
    for (auto i : vec){
        cout<<i<<" ";
    }
    cout<<endl;
}
void quickSort(vector<int> &vec,int left,int right){
    if (left==right){
        return;
    }
    int pivot;
    pivot = left + rand()%(right - left+1);
    cout<<"选择的pivot是："<<pivot<<endl;
    int i=left;
    int j=right;
    while(i<j){
        if(i<j and vec[i]<vec[pivot]){
            i++;
        }
        if(i<j and vec[j]>vec[pivot]){
            j--;
        }
        cout<<"即将交换的是"<<vec[i]<<","<<vec[j]<<endl;
        swap(vec[i],vec[j]);
        printVec(vec);
    }
    quickSort(vec,left,pivot-1);
    quickSort(vec,pivot+1,right);
}

int main()
{
    int i;
    cout<<"请输入要排序的序列长度"<<endl;
    cin>>i;
    vector<int> vec;
    for(int j=0;j<i;j++){
        int k;
        cin>>k;
        vec.push_back(k);
    }
    quickSort(vec,0,vec.size());
    return 0;
}