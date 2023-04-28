#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> solve(int sum, vector<int> &nums)
{
    vector<int> dp(sum + 1, 0);
    vector<int> index(sum + 1, 0);

    for (int i = 1; i <= sum; i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i - nums[j] >= 0)
            {
                if (dp[i] < 1 + dp[i - nums[j]])
                {
                    dp[i] = 1 + dp[i - nums[j]];
                    index[i] = j;
                }
            }
        }
    }

    int curr_sum = sum;
    vector<int> res;

    while (curr_sum > 0 && curr_sum >= nums[index[curr_sum]])
    {
        res.push_back(index[curr_sum]);
        curr_sum -= nums[index[curr_sum]];
    }

    sort(res.begin(), res.end());

    return res;
}

int main()
{
    int sum;
    cin >> sum;

    vector<int> v = {6, 8, 5, 4, 7};

    vector<int> ans = solve(sum, v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans.at(i) << " ";
    }
    cout << endl;
}
