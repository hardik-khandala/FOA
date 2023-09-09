#include <bits/stdc++.h>
using namespace std;

int minCoinsRequired(const vector<int>& coins, int amount, vector<int>& usedCoins) {
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= coins[j] && dp[i - coins[j]] != INT_MAX && dp[i - coins[j]] + 1 < dp[i]) {
                dp[i] = 1 + dp[i - coins[j]];
            }
        }
    }

    int currentAmount = amount;
    while (currentAmount > 0) {
        for (int j = 0; j < n; ++j) {
            if (currentAmount >= coins[j] && dp[currentAmount] == 1 + dp[currentAmount - coins[j]]) {
                usedCoins.push_back(coins[j]);
                currentAmount -= coins[j];
                break;
            }
        }
    }

    reverse(usedCoins.begin(), usedCoins.end());
    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000}; 
    int amount; 
    cout<<"Enter a value of N: ";
    cin>>amount;

    vector<int> usedCoins;
    int minCoins = minCoinsRequired(coins, amount, usedCoins);
    
    cout << "Minimum number of coins needed: " << minCoins << endl;
    cout << "Coins used: ";
    for (int coin : usedCoins) {
        cout << coin << " ";
    }
    cout << endl;

    return 0;
}
