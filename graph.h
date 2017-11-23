#include <iostream>
#include <vector>

class Graph{
  public:
    vector <bool> used;
    vector <vector <int>> nodes;
    int u, v;

    Graph(int size_, int number) {
        std::cin >> size_ >> number;
        int a, b;
        for (int i = 0; i <= number - 1; ++i) {
            std::cin >> a >> b;
            nodes[a-1].push_back(b-1);
        }
    }

    void dfs(int v)
    {
        used[v]=true;
        for (auto u: nodes[v])
            if(!used[u])
                dfs(u);
    }

    int bfs(int sourse, int dest, int size_){
        int d[size_];
        vector <int> Q;
        for (int i = 0; i < size_; ++i)
            d[i] = size_ + 1;
        d[sourse] = 0;
        Q.push_back(sourse);
        while (!Q.is_empty) {
            v = Q.pop_front();
            for (auto u: nodes[v]) {
                if (d[u] == size_ + 1) {
                    d[u] = d[v] + 1;
                    Q.push_back(u);
                }
            }
        }
    return d[dest];
    }
};
