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
    if (left>=right){
        return;
    }
    cout<<"本次排序范围是"<<left<<"-"<<right<<endl;
    // int pivot;
    // pivot = left + rand()%(right - left+1);
    // cout<<"选择的pivot是："<<pivot<<endl;
    // cout<<"选择的vec[pivot]是："<<vec[pivot]<<endl;
    // cout<<"即将交换"<<vec[pivot]<<"和"<<vec[left]<<endl;
    // swap(vec[left],vec[pivot]);
    // cout<<"交换过pivot后的数组是: ";
    // printVec(vec);

    
    int i=left;
    int j=right;
    while(i<j){//在左右指针相遇前一直扫描
        while(i<j and vec[i]<=vec[left]){//确定从左往右第一个比pivot大的数字
            i++;
        }
        cout<<"左边往右遇到的第一个比"<<vec[left]<<"大的数字是"<<vec[i]<<"所以i停在"<<i<<endl;
        while(i<j and vec[j]>=vec[left]){//确定从右往左第一个比pivot小的数字
            j--;
        }
        cout<<"右边往左遇到的第一个比"<<vec[left]<<"小的数字是"<<vec[j]<<"所以j停在"<<j<<endl;
        if (i<j){
            cout<<"即将交换的是"<<vec[i]<<","<<vec[j]<<endl;
            swap(vec[i],vec[j]);//因为要交换，所以下一次开始时i所指的数一定是小于j所指的数的
            printVec(vec);
        }else{
            cout<<"不交换"<<endl;
        }
    }
    cout<<"即将交换基准值"<<vec[left]<<"和"<<vec[j-1]<<endl;
    swap(vec[left],vec[j-1]);
    printVec(vec);
    quickSort(vec,left,j-2);
    quickSort(vec,j,right);
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
    cout<<"原数组： ";
    printVec(vec);
    quickSort(vec,0,vec.size()-1);
    printVec(vec);
    return 0;
}