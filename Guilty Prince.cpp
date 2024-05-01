#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _;
const int N = 22;
vector<vector<char>> g(N, vector<char> (N));
vector<pair<int, int>> moves = {{0, 1}, {0, -1}, { -1, 0}, {1, 0}};
bool visited[N][N];
int n, m, cnt;

bool isValid(int i, int j) {
    return i >= 0 and j >= 0 and i < m and j < n and !visited[i][j] && g[i][j] == '.';
}

void dfs(int i, int j) {
    visited[i][j] = 1;
    cnt++;
    for (auto [x, y] : moves) {
        if (isValid(i + x, j + y)) dfs(i + x, j + y);
    }
}

void solve()
{
    memset(visited, 0, sizeof visited);
    for (int i = 0; i < N; i++) {
        g[i].clear();
    }
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            if (g[i][j] == '@') {
                x = i; y = j;
            }
        }
    }
    cnt = 0;
    dfs(x, y);
    cout << cnt << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    cin >> test;
    for (_ = 1; _ <= test; _++)
    {
        cout << "Case " << _ << ": ";
        solve();
    }
    return 0;
}
