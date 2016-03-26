#include<bits/stdc++.h>
using namespace std;


void dfs(vector<list<int> > adjlist,int V,int s)
{
	bool visited[V];
	for(int i=0;i<V;i++)
		visited[i]=false;

	list<int> S;
	S.push_back(s);
	visited[s]=true;

	while(!S.empty())
	{
		int s=S.back();
		cout<<s<<"  ";
		S.pop_back();

		list<int> :: iterator i=adjlist[s].begin();

		while(i!=adjlist[s].end())
		{
			if(visited[*i]==false)
			{
				visited[*i]=true;
				S.push_back(*i);
			}
			i++;
		}
	}

  cout<<"\n";
}



int main()
{
	int u,v,V,E;

	cout<<"\nenter the number of vertices\t";
	cin>>V;
	cout<<"\nenter the number of edges\t";
	cin>>E;
	vector<list<int> > adjlist(V);

	for(int i=1;i<=E;i++)
	{
		cout<<"\nenter connected edges\n";
		cin>>u>>v;
		adjlist[u].push_back(v);
	}

	for(int v=0;v<V;v++)
	{
		cout<<v<<"  ";
		list<int> :: iterator i=adjlist[v].begin();
		while(i!=adjlist[v].end())
		{
			cout<<"->"<<*i;
			i++;
		}
		cout<<"\n";
	}

	dfs(adjlist,V,2);
	return 0;
}