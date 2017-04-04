#ifndef SPARSE_GRAPH_H
#define SPARSE_GRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class sparse_graph{

private:
    int n, m;
    bool directed;
    vector<vector<int>> g;

public:
    sparse_graph(int n, bool directed){
        this->n = n;
        this->m = m;
        this->directed = directed;
        for(int i = 0; i < n; ++i){
            g.push_back(vector<int>());
        }

        ~sparse_graph(){}

        int v(){return n;}
        int e(){return m;}

        void add_edge(int v, int w){
            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);

            g[v].push_back(w);
            if(v != w && !directed)
                g[w].push_back(v);

            m++;
        }

        bool has_edge(int v, int w){
            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);
            for(int i = 0; i  < g[v].size(); ++i)
                if(g[v][i] == w)
                    return true;
            return false;
        }
    }

    class adj_iterator{
    private:
        sparse_graph& G;
        int v;
        int index;
    public:
        adj_iterator(sparse_graph& graph, int v)
        :G(graph){
            this->v = v;
            this->index = 0;
        }
    };


};

#endif //SPARSE_GRAPH_H