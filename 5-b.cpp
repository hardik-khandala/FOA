#include <bits/stdc++.c>
using namespace std;

struct Item {
    int weight;
    int profit;
};

bool compare(Item a, Item b) {
    double ratio1 = (double)a.profit / a.weight;
    double ratio2 = (double)b.profit / b.weight;
    return ratio1 > ratio2;
}

double knapsackGreedy(int totalWeight, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double maxProfit = 0.0;
    int currentWeight = 0;

    for (const Item& item : items) {
        if (currentWeight + item.weight <= totalWeight) {
            currentWeight += item.weight;
            maxProfit += item.profit;
        } else {
            int remainingWeight = totalWeight - currentWeight;
            maxProfit += (double)item.profit / item.weight * remainingWeight;
            break;
        }
    }

    return maxProfit;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter weight and profit for item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].profit;
    }

    int totalWeight;
    cout << "Enter the total weight capacity of the knapsack: ";
    cin >> totalWeight;

    double maxProfit = knapsackGreedy(totalWeight, items);

    cout << "Maximum profit that can be obtained: " << maxProfit << endl;

    return 0;
}
