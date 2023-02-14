#include <iostream>
#include <algorithm>

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int n, m;
    std::cin >> n >> m;

    int sum = 0;
    std::cin >> sum;

    int a[n * m];

    for(int i = 0; i < n * m; i++) {
        a[i] = i + 1;
    }

    do {
        int diag1[n + m] = {0}, diag2[n + m] = {0}, row[n] = {0}, col[m] = {0};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                row[i] += a[i + n*j];
                col[j] += a[i + n*j];
                diag1[j - i] += a[i + n*j];
                diag2[i + j] += a[i + n*j];
            }
        }
        bool ok = true;
        for(int i = 0; i < n; i++) {
            ok &= row[i] == sum;
        }
        for(int i = 0; i < m; i++) {
            ok &= col[i] == sum;
        }
        ok &= (diag1[0] == sum && diag2[n - 1] == sum);
        if(ok) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    std::cout << a[i + n*j] << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n";
        }
    }
    while(std::next_permutation(a, a + n * m));

    return 0;
}