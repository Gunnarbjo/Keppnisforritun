#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string inp;
    ll loc;
    vector<char> chars;
    getline(cin, inp);

    for (ll i = 0; i < inp.length(); i++)
    {
        if (isupper(inp[i]))
        {
            loc = i;
            chars.push_back(inp[i]);
        }
    }
    if (chars.size() < 2)
    {
        cout << inp;
    }
    else
    {

        string lname = inp.substr(loc, inp.length());
        cout << lname << ", ";

        for (ll i = 0; i < chars.size() - 1; i++)
        {
            cout << chars[i] << ". ";
        }
    }

    cout << "\n";
}