#include <bits/stdc++.h>
using namespace std;


void prim(vector<list<pair<int,int> > > adj , int V)
{
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	vector<int> key(V,INT_MAX);
	vector<int> parent(V); 
	vector<bool> inMST(V,false);

	int s=0;

	pq.push(make_pair(0,s));

	while(!pq.empty())
	{
		int u=pq.top().second;
		inMST[u]=true;
		pq.pop();

		list<pair<int,int> > :: iterator i=adj[u].begin();
		while(i!=adj[u].end())
		{
			int v=(*i).second;
			int w=(*i).first;

			if(inMST[v]==false && key[v]>w)
			{
				parent[v]=u;
				pq.push(make_pair(w,v));
				key[v]=w;
			}
			i++;
		}
	}

    for(int i=1;i<V;i++)
    {
    	cout<<parent[i]<<"->\t"<<i<<"\n";

    }
    cout<<"\n";

}



int main()
{
	
	int node,edge;

	cout<<"\nenter the nodes and edges\n";
	cin>>node>>edge;
	vector<list<pair<int,int> > > adj(node);

	for(int i=1;i<=edge;i++)
	{
		int x,y;
		int w;
		cout<<"\nenter connected nodes\n";
		cin>>x>>y>>w;
		adj[x].push_back(make_pair(w,y));
		//adj[y].push_back(make_pair(w,x));
	}

	cout<<"\ngraph-----------------------------\n";
	for(int u=0;u<node;u++)
	{
		cout<<u<<"  ";
		list<pair<int,int> > :: iterator i=adj[u].begin();
        while(i!=adj[u].end())
        {
        	cout<<"->"<<"("<<(*i).first<<")"<<(*i).second;                          //not adj[i].first
        	i++;
        }
        cout<<"\n";

	}

	prim(adj , node);
	return 0;
}