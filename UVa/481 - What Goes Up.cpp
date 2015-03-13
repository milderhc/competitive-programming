#include <bits/stdc++.h>

using namespace std;

int main ( ) {
    vector<int> a;
    int n;
    while ( cin >> n ) a.push_back(n);
    vector<int> m, dp(a.size());
    dp[0] = 1;
    m.push_back(a[0]);
    for ( int i = 1; i < a.size(); ++i ) {
        int pos = lower_bound(m.begin(), m.end(), a[i]) - m.begin();
        if ( pos == m.size() ) m.push_back(a[i]);
        else m[pos] = a[i];
        dp[i] = pos + 1;
    }
    int k = dp.size() - (max_element(dp.rbegin(), dp.rend()) - dp.rbegin()) - 1;
    vector<int> sol;
    int bf = dp[k];
    sol.push_back(a[k]);
    for ( int i = k; sol.size() < m.size(); --i )
        if ( dp[i] + 1 == bf ) {
            sol.push_back(a[i]);
            bf = dp[i];
        }
    cout << m.size() << "\n-\n";
    for ( int i = sol.size() - 1; i >= 0; --i )
        cout << sol[i] << '\n';
}
