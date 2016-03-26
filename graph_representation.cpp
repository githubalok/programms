#include<bits/stdc++.h>
using namespace std;


int main()
{

	//using adjacency matrix

	/*
	int node,edge;
	cout<<"\nenter the nodes\t";
	cin>>node;
	cout<<"\nenter the edges\t";
	cin>>edge;

	int a[node][node];
	for(int i=0;i<node;i++)
		for(int j=0;j<node;j++)
			a[i][j]=0;

	int u,v;
	for(int i=0;i<edge;i++)
	{
		cout<<"\nenter the connected nodes\n";
		cin>>u>>v;
		a[u][v]=1;
	}
	cout<<"\ngraph is \n";

	 for(int i=0;i<node;i++){
		for(int j=0;j<node;j++){
			cout<<a[i][j]<<"  ";
		}
		cout<<"\n";
	}
    */

//using adjacency list

int V,E;
cout<<"\n enter the virtex\t";
cin>>V;
cout<<"\n enter the edges\t";
cin>>E;

vector< list<int> > adjacency_list(V+1);

for(int i=1;i<=E;i++)
{
	int u,v;
	cout<<"\nenter the connected virtex\n";
	cin>>u>>v;
	adjacency_list[u].push_back(v);

}

for(int i=0;i<V;i++)
{
	list<int> :: iterator itr =  adjacency_list[i].begin();
	cout<<i<<"   ";
	while(itr !=adjacency_list[i].end())
	{
		cout<<"->"<<*itr;
		itr++;

	}
	cout<<"\n";
}










return 0;



}