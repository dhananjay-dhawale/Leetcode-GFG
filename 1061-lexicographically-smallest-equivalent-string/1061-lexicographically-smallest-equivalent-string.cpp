class dsu {
    public:
        std::vector <int> p, r;
        int n;
    dsu(int _n) : n(_n) {
        p.resize(n);
        r.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if(r[x] < r[y])
            p[x] = y;
        else if(r[x] > r[y])
            p[y] = x;
        else{
            p[y] = x;
            r[x] += 1;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string s) {
        int n = s1.size();
        dsu d(26);
        for(int i = 0; i < n; i++) {
            d.unite(s1[i] - 'a', s2[i] - 'a');
        }
        int v[26] = {0};
        vector <int> adj[26];
        for(int i = 0; i < 26; i++) {
            adj[d.get(i)].push_back(i);
        }
        for(int i = 0; i < 26; i++) {
            if(adj[i].size()) {
                int mn = *min_element(adj[i].begin(), adj[i].end());
                for(auto &j : adj[i]) {
                    v[j] = mn;
                }
                v[i] = mn;
            }
        }
        for(auto &i : s) {
            i = v[i - 'a'] + 'a';
        }
        return s;
    }
};