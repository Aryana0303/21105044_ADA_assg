#include <iostream>
using namespace std;
#include <cstring>


int editDistance(string s, string t) {
int m = s.size();
int n = t.size();
int **output = new int*[m+1];
for(int i = 0; i <= m; i++) {
output[i] = new int[n+1];
}
// Fill 1st row
for(int j = 0; j <= n; j++) {
output[0][j] = j; //convert empty string to that character
}
// Fill 1st col
for(int i = 1; i <= m; i++) {
output[i][0] = i;  // //convert empty string to that character
}
for(int i = 1; i <= m; i++) {
for(int j = 1; j <= n; j++) {
if(s[m-i] == t[n-j]) { // checking the first characters
output[i][j] = output[i-1][j-1];  //fill the diagonally opposite value
}
else {
int a = output[i-1][j]; //insertion
int b = output[i][j-1]; //deletion
int c = output[i-1][j-1]; //replace
output[i][j] = min(a, min(b, c)) + 1;
}
}
}
return output[m][n]; // final answer
}


int main()
{
    string s, t;
    cin >> s >> t;

    cout << editDistance(s, t) << endl;
}