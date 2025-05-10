#include <vector>
#include <math.h>
#include <unordered_map>
#include "include/rp_heap.h"
#include <fstream>
#include <iostream>

std::unordered_map<int, Node *> poz;
Node * v[200005];

int main() {
    rp_heap h[150];
    int q, val, n;
    Node *nod;
    std::ifstream cin("mergeheap.in");
    std::ofstream cout("mergeheap.out");
    cin >> n >> q;
    for(int i = 1; i <= q; i ++)
    {
        int cer;
        cin >> cer;
        if(cer == 1)
        {
            int m, val;
            cin >> m >> val;
            h[m].push(-val);
        }
        else if(cer == 2)
        {
            int m;
            cin >> m;
            cout << -h[m].top() << "\n";
            h[m].pop();
        }
        else
        {
            int a, b;
            cin >> a >> b;
            h[a].merge(h[b]);

        }
    }

    return 0;
}
