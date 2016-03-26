#include<bits/stdc++.h>
using namespace std;
  

void bfs(vector<list<int> > adjlist, int V,int s)
{
	bool visited[V];
	for(int i=0;i<V;i++)
		visited[i]=false;

	list<int> q;
	visited[s]=true;
	q.push_back(s);

	while(!q.empty())
	{
		int s=q.front();
		cout<<s<<"  ";
		q.pop_front();

		list<int> :: iterator i=adjlist[s].begin();

		while(i!=adjlist[s].end())
		{
			if(visited[*i]==false)
			{
				visited[*i]=true;
				q.push_back(*i);
			}
			i++;
		}
	}
	cout<<endl;
}
 
 

int main()
{
	 
	int V,E;
	int u,v;

	cout<<"\nenter the number of vertices\t";
	cin>>V;
	cout<<"\nenter the number of edges\t";
	cin>>E;
	//g.Graph(V);

	vector<list<int> > adjlist(V);

	for(int i=1;i<=E;i++)
	{
		cout<<"\nenter connected edge\n";
		cin>>u>>v;
		adjlist[u].push_back(v);
	}

	cout<<"\ngraph--------------------------------------\n";
	for(int v=0;v<V;v++)
	{
		cout<<v<<"   ";
		list<int> :: iterator i=adjlist[v].begin();
		while(i!= adjlist[v].end())
		{
			cout<<"->"<<*i;
			i++;
		}
		cout<<"\n";
	}
	cout<<"\nbredth first search in graph \n";

    bfs(adjlist,V,0);

return 0;
}