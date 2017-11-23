#include <iostream>
#include <vector>

std::vector <int> e[101];
int k = 1;
int u;
bool used[101];
int dfs(int v)
    {
        used[v] = true;
        for (auto u: e[v])
            if(!used[u]) {
                ++k;
                dfs(u);
            }
    return k;
    }

int main() {
    int N, S, a;
    std::cin >> N >> S;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            std::cin >> a;
            if (a == 1)
                e[i].push_back(j);
        }
    dfs(S - 1);
    std::cout << k;
    return 0;
}
