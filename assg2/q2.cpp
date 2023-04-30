#include<iostream>
using namespace std;

int power(int a, int b){
    if(b==0){
        return 1;
    }
    else{
        return a*power(a,b-1);
    }
}

int main(){
    int a,b;
    cin>>a>>b;;
    std::cout<<power(a,b)<<endl;
}

//time complexity: O(b)
//space complexity: O(b)
