#include <bits/stdc++.h>
#include <sys/time.h>

using namespace std;
vector<int> bellman_ford(int V,int src,vector<pair<int,int>> Adj[]){
	vector<int> Dist(V,INT_MAX);
	Dist[src]=0;
	for(int i=0;i<V-1;i++){
		for(int j=0;j<V;j++){
			for(pair<int,int> edge:Adj[j]){
				int k=edge.first;int wt=edge.second;
				if(Dist[j]!=INT_MAX)Dist[k]=min(Dist[k],Dist[j]+wt);
			}
		}
	}
	//checking for negative cycle
	for(int j=0;j<V;j++){
			for(pair<int,int> edge:Adj[j]){
				int k=edge.first;int wt=edge.second;
				if(Dist[j]!=INT_MAX && (Dist[j]+wt)<Dist[k])assert(0);
			}
		}
		return Dist;
}

int main(){
	int t,V,src,E,u,v,wt;
	cin>>t;
	while(t!=0){
	cin>>V>>E;
	vector<pair<int,int> > *Adj=new vector<pair<int,int> >[V];
    vector<int>ans;
    for(int i=0;i<E;i++){
	    cin>>u>>v>>wt; 
	    Adj[u-1].push_back(make_pair(v-1,wt));
	}
	cin>>src;
	clock_t startTime = clock();
	ans=bellman_ford(V,src-1,Adj);
	cout <<(V*E)<<" "<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	t--;
}return 0;
}
