#include <iostream>
#include <vector>

using namespace std;

void inquire(vector<int> vec, int key)
{
    bool found = false;
    int start = -1, end = -1;
    for (int i = 0; i < vec.size(); i++)
    {
        
    }
    cout << start << " " << end << endl;
}
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> vec, query;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vec.push_back(k);
    }
    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        query.push_back(k);
    }
    for (auto it : query)
    {
        inquire(vec, it);
    }

    return 0;
}