#include <bits/stdc++.h>
using namespace std;

int max(int X, int Y) {
    if (X > Y)
        return X;
    else
        return Y;
}

int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int val[n], wt[n];
    cout << "Enter the values of items:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter the weights of items:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    int W;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    cout << "Total profit is " << knapSack(W, wt, val, n) << endl;

    return 0;
}
