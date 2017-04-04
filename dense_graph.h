#ifndef DENSE_GRAPH_H
#define DENSE_GRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class dense_graph{

private:
    int n, m;
    bool directed;
    vector<vector<bool>> g;

public:
    dense_graph(int n, bool directed){
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for(int i = 0; i < n; ++i)
            g.push_back(vector<bool>(n, false));
    }

    ~dense_graph(){}

    int v(){return n;}
    int e(){return m;}

    void add_edge(int v, int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        if(has_edge(v, w))
            return;
        g[v][w] = true;
        if(!directed)
            g[w][v] = true;

        m++;
    }

    bool has_edge(int v, int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return g[v][w];
    }
};

#endif //DENSE_GRAPH_H