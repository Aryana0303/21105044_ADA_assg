#include <iostream>
using namespace std;
#include <vector>

void transform(string s, vector<string> &v, string t = "")
{
    if (s.empty())
    {
        v.push_back(t);
        return;
    }
    if (s[0] - '0' <= 9) //to check if element is a digit
    {
        transform(s.substr(1), v, t + s[0]);
        return;
    }
    char a = tolower(s[0]);
    char b = toupper(s[0]);

    transform(s.substr(1), v, t + a);
    transform(s.substr(1), v, t + b);
}

int main()
{
    string s;
    cin >> s;

    vector<string> v;
    transform(s, v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
}

// time complexity=O(2^n*n);