#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool helper(string &s, string &p, int i, int j)
{
    //both string and pattern have been consumed completely, then return true.
    if (i < 0 && j < 0)
    {
        return true;
    }

    //string is not consumed completely but the pattern is, then return false.
    if (i >= 0 && j < 0)
    {
        return false;
    }
    // string consumed, pattern not consumed
    if (i < 0 && j >= 0)
    {
        for (int k = 0; k <= j; k++)
        {
            if (p[k] != '*')   //check if the remaining pattern characters are all '*'. If they are, then return true, else return false.

            {
                return false;  
            }
        }
        return true; //* can be replaced by any character
    }
    

    // matching
    if (s[i] == p[j] || p[j] == '.')
    {
        return helper(s, p, i - 1, j - 1);
    }
    else if (p[j] == '*')  //it checks two cases - either the * matches with the current character in the string, 
    //in which case it calls the helper function recursively with i-1 and j to continue checking the next 
    //character in the string, or the * matches with an empty string, in which case it calls the helper 
    //function recursively with i and j-1 to continue checking the next character in the pattern.


    {
        return (helper(s, p, i - 1, j) || helper(s, p, i, j - 1)); 
    }
    else
    {
        return false;
    }
}
bool isMatch(string s, string p)
{
    return helper(s, p, s.length() - 1, p.length() - 1);
}

int main()
{
    string s, p;
    cin >> s >> p;

    cout << isMatch(s,p) << endl;
}