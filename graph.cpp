#include <iostream>
#include <ctime>
#include "sparse_graph.h"
#include "dense_graph.h"

using namespace std;

int main(void){
    int n = 20;
    int m = 100;

    srand(time(NULL));

    //sparse graph
    sparse_graph g1(n, false);
    for(int i = 0; i < m; ++i){
        int a = rand()%n;
        int b = rand()%n;
        g1.add_edge(a, b);
    }

    for(int v = 0; v < n; ++v){
        cout << v << " : ";
        sparse_graph::adj_iterator adj(g1, v);
        for(int w = adj.begin(); !adj.end(); w = adj.next())
            cout << w << " ";
        cout << endl;
    }

    cout << endl;

    //dense graph
    dense_graph g2(n, false);
    for(int i = 0; i < m; ++i){
        int a = rand()%n;
        int b = rand()%n;
        g2.add_edge(a, b);
    }

    for(int v = 0; v < n; ++v){
        cout << v << " : ";
        dense_graph::adj_iterator adj(g2, v);
        for(int w = adj.begin(); !adj.end(); w = adj.next())
            cout << w << " ";
        cout << endl;
    }

    cout << endl;

    return 0;
}
