#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printParentheses(int i, int j, const vector<vector<int>>& brackets, char& name) {
    if (i == j) {
        cout << name++;
        return;
    }
    
    cout << "(";
    printParentheses(i, brackets[i][j], brackets, name);
    printParentheses(brackets[i][j] + 1, j, brackets, name);
    cout << ")";
}

void optimalMatrixChainOrder(const vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> brackets(n, vector<int>(n, 0));

    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    brackets[i][j] = k;
                }
            }
        }
    }

    char name = 'A';
    cout << "Optimal Parenthesization: ";
    printParentheses(0, n - 1, brackets, name);
    cout << endl;
    cout << "Minimum Scalar Multiplications: " << dp[0][n - 1] << endl;
}

int main() {
    vector<int> dimensions = {10, 30, 5, 60};
    optimalMatrixChainOrder(dimensions);

    return 0;
}
