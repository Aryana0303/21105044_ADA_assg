#include<iostream>
#include<vector>
#include <set>
using namespace std;



vector<int> sortsq(vector<int> &a)
{
    set<int> sets;
    for(auto i : a)  // set automatically sorts the elements in ascending order. Therefore, the elements will be inserted in sorted order based on their squared values.
    {
        sets.insert((i*i));
    }
    vector<int> ans;
    for(auto i : sets)
    {
        ans.push_back(i);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> A;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        A.push_back(temp);
    }
    vector<int> result = sortsq(A);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
} 
