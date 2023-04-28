#include <iostream>
#include<climits>
using namespace std;

int findMinVertex(int *weight, bool *visited, int v){ // The findMinVertex function is then called to get the vertex with the minimum weight that has not been visited yet.
    int minVertex=-1;
    for(int i=0;i<v;i++){
        if(!visited[i] && (minVertex==-1 || weight[i]<weight[minVertex])){
            minVertex=i;
        }
    }
    return minVertex;
}

void prims(int **edges, int v){
    int *parent=new int[v];    
    int *weight=new int[v];
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
        weight[i]=INT_MAX;
    }
    parent[0]=-1;   //The parent array of the first vertex is set to -1 as it has no parent
   
    weight[0]=0; //the weight array of the first vertex is set to 0 as it is the starting vertex.
    for(int i=0;i<v;i++){
        int minVertex=findMinVertex(weight,visited,v);
        visited[minVertex]=true;
        for(int j=0;j<v;j++){  //for each unvisited vertex j that is adjacent to minVertex, the code checks if the weight of the edge connecting minVertex 
            //and j is less than the current weight weight[j] of vertex j
            if(edges[minVertex][j] != 0 && !visited[j]){
                if(edges[minVertex][j]<weight[j]){
                    weight[j]=edges[minVertex][j];
                    parent[j]=minVertex;
                }
            }
        }
        
    }
    for(int i=1;i<v;i++){
        if(parent[i]<i){ 

            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else{ 


            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
}

int main() {
    int v,e;
    cin>>v>>e;
    int **edges=new int*[v];
    for(int i=0;i<v;i++){
        edges[i]=new int[v];
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        edges[s][d]=w;
        edges[d][s]=w;
    }
    cout<<"Output : "<<endl;
    prims(edges, v);
}
   
