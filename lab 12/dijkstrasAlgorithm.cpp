#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dijkstraAlgo(vector<vector<int>> graph,int start){

    int nodeCount = graph.size();
    vector<int> shortest_distance(nodeCount,INT_MAX);
    vector<bool> visited(nodeCount,false);
    vector<int> predecessor(nodeCount,-1);
    queue<int> q;
    
    //initiallize
    shortest_distance[start]=0;
    q.push(start);

    int currentNode;
    int calulatedDistance;
    vector<int> neighbours_list;

    while (!q.empty())
    {
        currentNode=q.front();
        q.pop();

        for(int neighbour = 0 ; neighbour < nodeCount ; neighbour++ ){
            if(graph[currentNode][neighbour]>0){
                calulatedDistance = shortest_distance[currentNode] + graph[currentNode][neighbour];
                //relaxing
                if(calulatedDistance<shortest_distance[neighbour]){
                    shortest_distance[neighbour]=calulatedDistance;
                    predecessor[neighbour]=currentNode;
                }
                //getting next possible nodes for visiting
                if(!visited[neighbour]){
                    neighbours_list.push_back(neighbour);
                }
            }
        }
        //find the minimum weighed path if available
        if(!neighbours_list.empty()){
            int i = 0;
            int mini = graph[currentNode][neighbours_list[i]];
            for(int j=1;j<neighbours_list.size();j++){
                if(mini>graph[currentNode][neighbours_list[j]]){
                    mini = graph[currentNode][neighbours_list[j]];
                    i=j;
                }
            }
            q.push(neighbours_list[i]);//push to queue
        }
        
        visited[currentNode]=true;
        neighbours_list.clear();
    }
    cout<<"source node - "<<start<<endl;
    int n = 0;
    for(int i:shortest_distance){
        cout<<"distance of node "<<n<<" - "<<i<<endl;
        n++;
    }
}


int main(){
   vector<vector<int>> graph ={
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    dijkstraAlgo(graph,5);
}