#include<bits/stdc++.h>
using namespace std;
//typedef 
typedef pair<int, int>pii;

//range
const int N= 1e5+5;

//vector pair array
vector<pii>v[N];
//boolean visited
bool visited[N];

//edge class
class Edge{
    public:
    int a,b,w;
    Edge(int a, int b, int w){
        this->a=a;
        this->b=b;
        this->w=w;
    }
};


//custom compare class instead of greater

class cmp{
    public:
    bool operator()(Edge a, Edge b){
        return a.w > b.w;
    }
};
//prims implementation
void prims(int s){
    priority_queue<Edge, vector<Edge>, cmp>pq;
    pq.push(Edge(s,s,0));
    vector<Edge>edge_list;
    while(!pq.empty()){
        Edge parent=pq.top();
        pq.pop();
        int a= parent.a;
        int b= parent.b;
        int w= parent.w;
        if(visited[b]) continue;
        visited[b]=true;
        edge_list.push_back(parent);
        for(int i=0; i<v[b].size(); i++){
            pii child= v[b][i];
            if(!visited[child.first]){
                pq.push(Edge(b, child.first, child.second));
            }
        }
    }

    //ignore initiall edge
    edge_list.erase(edge_list.begin());

    //display every edge_list
    for(Edge val: edge_list){
        cout<<val.a<<" "<<val.b<<" "<<val.w<<endl;
    }


}
int main(){
    int n, e;
    cin>>n>>e;
    while(e--){
        int a, b, w;
        cin>>a>>b>>w;
        v[a].push_back({b,w});
        v[b].push_back({a,w});
    }
    
    //prims algorithm invoke
    prims(1);
    return 0;
}