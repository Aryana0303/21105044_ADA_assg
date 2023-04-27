#include <iostream>
#include<vector>
using namespace std;

bool palindrome(vector<char> &arr, int length)
{
    int n=arr.size();
    for (int i = 0; i < length / 2; i++)
    {
        if (arr[i] != arr[length - i - 1])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
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
