//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find the maximum possible amount of money we can win.
class Solution
{
public:
    long long dp[1001][1001];

    long long f(int i, int j, int arr[], int n)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i > j)
            dp[i][j] = 0;
        else
        {
            dp[i][j] = max(arr[i] + min(f(i + 1, j - 1, arr, n), f(i + 2, j, arr, n)),
                           arr[j] + min(f(i, j - 2, arr, n), f(i + 1, j - 1, arr, n)));
        }
        return dp[i][j];
    }

    long long maximumAmount(int n, int arr[])
    {
        // Your code here
        memset(dp, -1, sizeof(dp));
        return f(0, n - 1, arr, n);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maximumAmount(n, a) << endl;
    }
    return 0;
}
// } Driver Code Ends