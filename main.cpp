#include <filesystem>
#include <fstream>
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <chrono>
#include <vector>
#include "include/leftist_heap.h"
#include "include/rp_heap.h"
namespace fs = std::filesystem;

class Timer {
    std::chrono::time_point<std::chrono::system_clock> begin;
    std::chrono::time_point<std::chrono::system_clock> end;
public:

    void startTimer() {
        begin = std::chrono::high_resolution_clock::now();;
    }
    void endTimer() {
        end = std::chrono::high_resolution_clock::now();
    }
    float getElapsedTime() {
        std::chrono::duration<float> diff = end - begin;
        return diff.count();
    }
};
void rpheap(auto path) {
    std::ifstream cin(path);
    int q, val, n;
    RP::Node *nod;
    cin >> n >> q;
    std::vector<RP::rp_heap> h(n+3);
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
            // cout << -h[m].top() << "\n";
            h[m].pop();
        }
        else
        {
            int a, b;
            cin >> a >> b;
            h[a].merge(h[b]);

        }
    }
    cin.close();
}
void leftistHeap(auto path) {
    std::ifstream cin(path);
    int n, q;
    cin>>n>>q;
    std::vector<Leftist::leftist_heap> heaps(n+3);
    while (q--) {
        int c;
        cin>>c;
        if (c==1) {
            int m,x;
            cin>>m>>x;
            heaps[m].insert(x);
        }else if (c==2) {
            int m;
            cin>>m;
            //g<<heaps[m].findMin()<<"\n";
            heaps[m].deleteMin();
        }else {
            int a,b;
            cin>>a>>b;
            heaps[a].Merge(heaps[b]);
            heaps[b].makeEmpty();
        }
    }
}
int main() {
    std::string path = "../tests";
    std::cout << "CWD: " << fs::current_path() << "\n";
    for (const auto & entry : fs::directory_iterator(path)) {
        std::ifstream cin(entry.path());
        Timer t;
        std::cout << entry.path() << std::endl;
        t.startTimer();
        leftistHeap(entry.path());
        t.endTimer();
        std::cout << "leftist-heap: " << t.getElapsedTime() << std::endl;

        t.startTimer();
        rpheap(entry.path());
        t.endTimer();
        std::cout <<"rank-pairing-heap: " << t.getElapsedTime() << std::endl;

    }

    return 0;
}
