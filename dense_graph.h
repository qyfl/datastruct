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

    class adj_iterator{
    private:
        dense_graph &G;
        int v;
        int index;
    public:
        adj_iterator(dense_graph& graph, int v)
        :G(graph){
            this->v = v;
            this->index = -1;
        }

        int begin(){
            index = -1;
            return next();
        }

        int next(){
            for(index += 1; index < G.v(); ++index)
                if(G.g[v][index])
                    return index;
                return -1;
        }

        bool end(){
            return index >= G.v();
        }

    };


};

#endif //DENSE_GRAPH_H
