##############################################################################  Question  ####################################################################################################################################

Given two sorted matrices mat1 and mat2 of size n x n of elements. Each matrix contains numbers arranged in strictly ascending order, with each row sorted from left to right, and the last element of a row being smaller than the first element of the next row. You're given a target value, x, your task is to find and count all pairs {a, b} such that a is from mat1 and b is from mat2 where sum of a and b is equal to x.

Example 1:

Input: 
n = 3, x = 21
mat1 = {{1, 5, 6},
        {8, 10, 11},
        {15, 16, 18}}
mat2 = {{2, 4, 7},
        {9, 10, 12},
        {13, 16, 20}}
OUTPUT: 4
Explanation: The pairs whose sum is found to be 21 are (1, 20), (5, 16), (8, 13), (11, 10).
Example 2:

Input:
n = 2, x = 10
mat1 = {{1, 2},
        {3, 4}}
mat2 = {{4, 5},
        {6, 7}}
Output: 2
Explanation: The pairs whose sum found to be 10 are (4, 6), (3, 7).
User Task:
Your task is to complete the function countPairs() which takes 4 arguments mat1, mat2, n, x, and returns the count of pairs whose sum equals to x. You don't need to take any input or print anything.

Expected Time Complexity: O(n2).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ mat1[i][j] , mat2[i][j] ≤ 105
1 ≤ n ≤ 100
1 ≤ x ≤ 105

##############################################################################  Solution  ####################################################################################################################################
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{    int i1 = 0, j1 = 0, i2 = n - 1, j2 = n - 1, ans = 0;
while (i1 < n && j1 < n && i2 >= 0 && j2 >= 0) {
    if (mat1[i1][j1] + mat2[i2][j2] == x) {
        ans++;
        if (j1 != n - 1) {
            j1++;
        } else {
            i1++;
            j1 = 0;
        }
        if (j2 != 0) {
            j2--;
        } else {
            i2--;
            j2 = n - 1;
        }
    } else if (mat1[i1][j1] + mat2[i2][j2] < x) {
        if (j1 != n - 1)
            j1++;
        else {
            i1++;
            j1 = 0;
        }
    } else if (mat1[i1][j1] + mat2[i2][j2] > x) {
        if (j2 != 0)
            j2--;
        else {
            i2--;
            j2 = n - 1;
        }
    }
    
}
return ans;
	}
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends

