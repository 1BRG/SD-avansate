#include <vector>
#include <math.h>
#include <unordered_map>
#include "include/rp_heap.h"
#include <fstream>
#include <iostream>

std::unordered_map<int, Node *> poz;
Node * v[200005];

int main() {
    rp_heap h;
    int q, val;
    Node *nod;
    std::ifstream cin("../input.txt");
    // if (cin.is_open()) {
    //     std::cout << "ceva";
    // }
    cin >> q;
   // std::cout << "1->PUSH / 2->TOP/ 3->DECREASE / 4->POP \n";
    int ct = 0;
    for (int i = 1; i <= q; i++) {
        int cer;
        cin >> cer;
        if (cer == 1)
            cin >> val, v[++ct] = h.push(val);
        if (cer == 2) {
            cin >> val;
            h.decrease(v[val], -1000000000);
            h.pop();
           // h.pop(v[val]);
        }
        if (cer == 3) {
            std::cout << h.top() << '\n';
        }

    }

    return 0;
}
