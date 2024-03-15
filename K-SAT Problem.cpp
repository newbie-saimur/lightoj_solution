#include <bits/stdc++.h>
using namespace std;
#define int   long long
int _;

void solve()
{
    int wish[31][31];
    memset(wish, 0, sizeof wish);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> wish[i][j];
        }
    }
    int filled[31] = {0};
    int p; cin >> p;
    for (int i = 0; i < p; i++) {
        int x; cin >> x;
        filled[x] = 1;
    }
    for (int i = 0; i < n; i++) {
        bool wish_filled = false;
        for (int j = 0; j < k; j++) {
            int x = wish[i][j];
            if (x > 0 && filled[x] == 1) {
                wish_filled = 1;
                break;
            }
            else if (x < 0 && filled[-x] == 0) {
                wish_filled = 1;
                break;
            }
        }
        if (!wish_filled) {
            cout << "Case " << _ << ": No\n";
            return;
        }
    }
    cout << "Case " << _ << ": Yes\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    cin >> test;
    for (_ = 1; _ <= test; _++)
    {
        solve();
    }
    return 0;
}
