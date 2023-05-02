#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

void motuPatlu(int n)
{
    int sum = 0;
    int i = 0;
    while (sum + 3 * i < n)   //calculates the number of bricks placed by both Motu and Patlu in each round until the total number of bricks is at least n
    {
        sum += 3 * i;
        i++;
    }

    if (n - sum - i > 0) //remaining - i
    {
        cout << "Motu" << endl;
    }
    else
    {
        cout << "Patlu" << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    motuPatlu(n);
}
