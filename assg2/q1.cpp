#include <iostream>
#include<vector>
using namespace std;

bool palindrome(vector<char> &arr, int length)
{
    int n=arr.size();
    int i=0;
    int j=n-1;
    
   
    while(i<=j){
        if(arr[i] != arr[j]){
            return false;
        }
        else{
            return true;
        }
    }
    return true;
    
}

int main()
{
    vector<char> arr;
    int n;
    cin>>n;
    char a;
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }
    cout<< palindrome(arr, n)<<endl;
}