#include<iostream>
#include<vector>
add_vertex(std::vector<int> Adj[],int v1,int v2)
{
    Adj[v1].push_back(v2);
    Adj[v2].push_back(v1);
}
print_list(std::vector<int> Adj[],int Vertex)
{
    for(int i=0;i<Vertex;i++)
    {
        std::cout << "\nList of Vertex " << i << " : ";
        for(auto x:Adj[i]){
            std::cout << "->" << x;
        }
    }
}
main()
{
    int vertex=5;
    std::vector<int> Adj[vertex];
    add_vertex(Adj,0,1);
    add_vertex(Adj,0,4);
    add_vertex(Adj,1,1);
    add_vertex(Adj,2,3);
    add_vertex(Adj,1,2);
    print_list(Adj,vertex);
}

/*#include<iostream>

using namespace std;
struct list_node{
int vertex_no;
list_node* next;
};
struct graph{
    int Vertex;
    int Edge;
    list_node* Adj;
};

graph* generate_matrix(int vertex,int edges)
{
    int source,destination;
    list_node *temp,*t;
    graph* G = new graph;
    G->Vertex=vertex;
    G->Edge=edges;
    G->Adj = new list_node[G->Vertex];
    for(int i=0;i<G->Vertex;i++){
        G->Adj[i]->vertex_no = i;
        G->Adj[i]->next = G->Adj + i;
    }
    for(int i=0;i<G->Edge;i++){
        cout<<"Enter Edge (Source and Destination) : ";
        cin>>source>>destination;
        temp = new list_node;
        temp->vertex_no=destination;
        temp->next = G->Adj[source];
        t=G->Adj[source];
        while(t->next!=G->Adj[source])
            t=t->next;
        t->next=temp;
    }
    return G;
}


print_graph(const graph *G)
{

}

int main()
{
    graph *G = generate_matrix(4,5);
//    print_graph(G);
}
*/
