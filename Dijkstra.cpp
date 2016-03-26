#include<bits/stdc++.h>
using namespace std;
//#define INF 0x3f3f3f3f

 void dijkstra(vector< list< pair<int,int> > > adj,int s,int V)
 {
 	int x=INT_MAX;
 	 
 	set< pair<int,int> > setds;
 	vector<int> dist(V,x);

 	setds.insert(make_pair(0,s));
 	dist[s]=0;
    
 	while(! setds.empty())
 	{
 		pair<int,int> temp = *(setds.begin());
 		setds.erase(setds.begin());

 		int u=temp.second;
 		list<pair<int,int> > :: iterator i=adj[u].begin();

 		while(i!=adj[u].end())
 		{
 			int v=(*i).second;
 			int w=(*i).first;

 			if(dist[v]>dist[u]+w){
 				if(dist[v]!=x)
 					setds.erase(setds.find(make_pair(dist[v],v)));

 				dist[v]=dist[u]+w;
 				setds.insert(make_pair(dist[v],v));
 			}
 			i++;
 		}	
 	}


 	cout<<"\ndisance from source======\n";
 	for(int i=0;i<V;i++)
 	{
 		cout<<i<<"\t"<<dist[i]<<"\n";
 	}
 	cout<<"\n";

 }

int main()
{
	int V,E;
	cout<<"\nenter the number of vertices\t";
	cin>>V;
	cout<<"\nenter the number of edges\t";
	cin>>E;
    
    
	 vector< list< pair<int,int> > > adj(V);

	for(int i=1;i<=E;i++)
	{
		int u,v,w;
		cout<<"\nentr connected nodes and related weight\n";
		cin>>u>>v>>w;
		adj[u].push_back(make_pair(w,v));
		//adj[v].push_back(make_pair(w,u));
	}

    //cout<<"\nparent_node\t"<<"\tweight"<<"\tnode\n";

	for(int i=0;i<V;i++)
	{
		cout<<i<<"  ";
		 
		list<pair<int,int> >  :: iterator itr = adj[i].begin();
		while(itr!=adj[i].end())
		{
			cout<<"->"<<"("<<(*itr).first<<")"<<(*itr).second;
			itr++;
		}
		cout<<"\n";
	}   
	dijkstra(adj,0,V);
	return 0;
}