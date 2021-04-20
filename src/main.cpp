/**
 * @file main.cpp
 * @brief This is a test of CMake, doxygen, and GitHub.
 * @details This is the long brief at the top of main.cpp.
 * @author Seth McNeill
 * @date 1/28/2021
 * 
 */

#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;

class Graph{
private:
    int n;
    int **matrix;

public:
    //http://www.cplusplus.com/forum/articles/7459/ was used to understand how to make a variable matrix
    Graph(int x){
        n = x;
        matrix = new int*[n];
        for (int i=0; i<n; i++)
            matrix[i] = new int[n];

    }

    void addEdge(int i, int j, int dist) {
        matrix[i][j] = dist;
        matrix[j][i] = dist;
    }
    void removeEdge(int i, int j) {
        matrix[i][j] = -1;
        matrix[i][j] = -1;
    }
    int distance(int i, int j) {
        return matrix[i][j];
    }


    vector<int> outEdges(int i) {
        vector<int> edges;
        for (int j=0; j<n; j++) {
            if (matrix[i][j]) {
                edges.push_back(j);
            }
        }
        return edges;
    }
    void inEdges(int i, vector<int> &edges) {
        for (int j=0; j<n; j++) {
            if (matrix[j][i]) {
                edges.push_back(j);
            }
        }
    }

    int length(){
        return n;
    }

    bool matrixOut(){
        return matrix;
    }
};


Graph Dijkstra(Graph g, int source) {
    int dist[g.length()];
    bool used[g.length()];
    for (int i=0; i<g.length(); i++){
        dist[i] = INF;
        used[i] = false;
    }
    dist[source] = 0;
    for (int i=0; i<g.length(); i++) {
        vector<int> edge = g.outEdges(i);
        
    }
    

}


int main(int, char**) {
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(1,2,8);
    g.addEdge(2,3,7);
    g.addEdge(3,4,9);
    g.addEdge(4,5,10);
    g.addEdge(5,6,2);
    g.addEdge(6,7,1);
    g.addEdge(7,8,7);
    g.addEdge(7,0, 8);
    g.addEdge(1,7,11);
    g.addEdge(2,5,4);
    g.addEdge(3,5,14);
    g.addEdge(2,8,2);
    g.addEdge(6,8,6);
    g.addEdge(0,7,8);

    for (int i=0; i<g.length(); i++) {
        cout << g.distance(i, i+1) << ' ';
    }
    cout << endl;
}