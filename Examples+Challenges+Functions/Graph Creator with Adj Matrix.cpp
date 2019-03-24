#include<iostream>

using namespace std;

struct graph{
    int Vertex;
    int Edge;
    int **Adj;
};

graph* generate_matrix(int vertex)
{
    graph *G = new graph;
    G->Vertex = vertex;
    std::cout<<"Enter NO of Edges: ";
    std::cin>>G->Edge;

///Throwing Exception
    if(G->Edge>vertex*vertex){
        std::cout << "Edges Can not more than "<<vertex*vertex<<" For "<<vertex <<" Vertexes";
        return NULL;
    }

///creating  Adj matrix for graph G
    G->Adj = new int* [vertex];
    for(int i=0;i<vertex;i++)
        G->Adj[i] = new int[vertex];

///Initializing graph matrix to zero
    for(int i=0;i<vertex;i++)
        for(int j=0;j<vertex;j++)
            G->Adj[i][j]=0;

    cout<<"Enter "<<G->Edge<<" pairs of  vertexes : ";

    for(int i=0,v1,v2;i<G->Edge;i++){
        std::cin>>v1>>v2;
        G->Adj[v1][v2]=1;
        G->Adj[v2][v1]=1;
    }

    return G;
}
print_graph(const graph *G)
{
for(int i=0;i<G->Vertex;i++,std::cout<<"\n")
    for(int j=0;j<G->Vertex;j++)
        cout<<G->Adj[i][j];
}

int main()
{
    graph *G = generate_matrix(4);
    print_graph(G);
}
