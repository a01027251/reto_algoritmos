#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

template <class T>
class GraphVertex
{
private:
    T val;
    std::vector<int> adj;

public:
    ~GraphVertex(){};
    GraphVertex(){};
    GraphVertex(T _val) { val = _val; };

    T get_val() { return val; };
    void set_val(T _val) { val = _val; };

    std::vector<int> get_adj() { return adj; };
    void add_to_adj(int idx) { adj.push_back(idx); };
};

// A B C D E F G H
// 0 1 2 3 4 5 6 7
// Lista adj a: 1, 2, 3
// Lista adj b: 0
// Lista adj c: 0, 3

template <class T>
class Graph
{
private:
    std::vector<GraphVertex<T>> nodes;
    bool is_directed;

public:
    ~Graph(){};
    Graph() { is_directed = true; };
    std::vector<GraphVertex<T>> get_nodes() { return nodes; }

    void add_node(T val)
    {
        GraphVertex<T> node(val);
        nodes.push_back(node);
    };

    void add_edge(int src, int dst)
    {
        nodes[src].add_to_adj(dst);
        if (!is_directed)
            nodes[dst].add_to_adj(src);
    };

    void add_edge_generic(T src, T dst)
    {
        int cont = 0;
        int src_idx = 0;
        int dst_idx = 0;
        for (int i = 0; i < nodes.size(); i++)
        {
            if (src == nodes[i].get_val())
            {
                src_idx = i;
            }

            if (dst == nodes[i].get_val())
            {
                dst_idx = i;
            }
        }
        bool x = true;

        for (auto node : nodes[src_idx].get_adj())
        {
            if (node == dst_idx)
            {
                x = false;
            }
        }

        if (x == true)
        {
            nodes[src_idx].add_to_adj(dst_idx);
        }
    };

    void BFS(int start_vertex)
    {
        std::vector<int> visited;
        std::queue<int> searching;
        std::vector<int> temp;
        bool condition = true;
        do
        {
            if (condition)
            {
                std::cout << nodes[start_vertex].get_val() << " ";
                temp = nodes[start_vertex].get_adj();
                for (int i = 0; i < temp.size(); i++)
                {
                    searching.push(temp[i]);
                }
                visited.push_back(start_vertex);
                start_vertex = searching.front();
                searching.pop();
                for (int i = 0; i < visited.size(); i++)
                {
                    if (visited[i] == start_vertex)
                    {
                        condition = false;
                        i = visited.size();
                    }
                    else
                        condition = true;
                }
            }
            else
            {
                start_vertex = searching.front();
                searching.pop();
                for (int i = 0; i < visited.size(); i++)
                {
                    if (visited[i] == start_vertex)
                    {
                        condition = false;
                        i = visited.size();
                    }
                    else
                        condition = true;
                }
            }

        } while (searching.empty() != true);
    };

    void DFS(int start_vertex)
    {
        std::vector<int> visited;
        std::stack<int> searching;
        std::vector<int> temp;
        bool condition = true;
        do
        {
            if (condition)
            {
                std::cout << nodes[start_vertex].get_val() << " ";
                temp = nodes[start_vertex].get_adj();
                for (int i = 0; i < temp.size(); i++)
                {
                    searching.push(temp[i]);
                }
                visited.push_back(start_vertex);
                start_vertex = searching.top();
                searching.pop();
                for (int i = 0; i < visited.size(); i++)
                {
                    if (visited[i] == start_vertex)
                    {
                        condition = false;
                        i = visited.size();
                    }
                    else
                        condition = true;
                }
            }
            else
            {
                start_vertex = searching.top();
                searching.pop();
                for (int i = 0; i < visited.size(); i++)
                {
                    if (visited[i] == start_vertex)
                    {
                        condition = false;
                        i = visited.size();
                    }
                    else
                    {
                        condition = true;
                        searching.push(0);
                    }
                }
            }

        } while (searching.empty() != true);
    }

    void print_edge()
    {
        for (auto node : nodes)
        {
            cout << node.get_val() << " : ";
            for (auto edge : node.get_adj())
            {
                cout << nodes[edge].get_val() << " -> ";
            }
            cout << node.get_adj().size();
            cout << endl;
        }
    }

    void print_conteo(string ip)
    {

        int cont = 0;
        for (auto node : nodes)
        {

            if (node.get_val() == ip)
            {
                // cout<<node.get_adj().size()<<endl;
                cont = node.get_adj().size();
                cout << "Numero de conexiones Salientes: " << cont << endl;
            }
        }
    }

    void conteo_inversa(string ip)
    {
        int contador = 0;
        for (auto node : nodes)
        {

            for (auto pablito : node.get_adj())
            {
                if (nodes[pablito].get_val() == ip)
                {
                    contador++;
                }
            }
        }
        cout << "Numero de conexiones entrantes: " << contador << endl;
    }
};

#endif