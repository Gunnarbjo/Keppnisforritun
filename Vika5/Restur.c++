#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

// Calculate the answer for a given order, given the vector of values and the vector of costs
void calc(vector<ll> &myV, vector<ll> costV, ll ord)
{
    // Create a vector to store the answer
    vector<ll> ansV;
    
    // Check if the order is impossible
    if (myV[ord] == -2)
    {
        cout << "Impossible\n";
        return;
    }
    
    // Check if the order is ambiguous
    if (myV[ord] == -1)
    {
        cout << "Ambiguous\n";
        return;
    }
    
    // Trace back the path to the root (order 0)
    while (ord > 0)
    {
        // Add the current node to the answer vector
        ansV.push_back(myV[ord] + 1);
        // Move to the parent node by subtracting the cost of the current node
        ord -= costV[myV[ord]];
    }
    
    // Check if the order is ambiguous
    if (ord < 0)
    {
        cout << "Ambiguous\n";
        return;
    }
    
    // Sort and print the answer vector
    sort(ansV.begin(), ansV.end());
    for (auto i : ansV)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int main()
{
    // Create a vector to store the values of each order
    vector<ll> myV(30003, -2);
    // Set the value of the root (order 0) to 0
    myV[0] = 0;
    
    // Read in the number of orders and the costs of each order
    ll inp;
    cin >> inp;
    vector<ll> costV(inp);
    for (auto &i : costV)
    {
        cin >> i;
    }

    // Loop over each order, updating the values in the vector
    for (ll i = 0; i < inp; i++)
    {
        ll cost = costV[i];
        // Loop over each node in the vector
        for (ll j = 0; j <= 30000; j++)
        {
            // If the node is reachable, update its child nodes
            if (myV[j] >= 0)
            {
                // If the child node has not been reached before, set its value to the current order
                if (myV[j + cost] == -2)
                {
                    myV[j + cost] = i;
                }
                // If the child node has been reached before, set its value to -1 (ambiguous)
                else
                {
                    myV[j + cost] = -1;
                }
            }
            // If the node is ambiguous, set its child nodes to -1 (ambiguous)
            if (myV[j] == -1)
            {
                myV[j + cost] = -1;
            }
        }
    }

    // Read in the number of queries and calculate the answer for each query
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll ord;
        cin >> ord;
        calc(myV, costV, ord);
    }
    return 0;
}
