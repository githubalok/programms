#include <bits/stdc++.h>
using namespace std;
#define INF 99999


void floyd(int g[4][4],int V)
{
	int dist[4][4];

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			dist[i][j]=g[i][j];
	}

	for(int k=0;k<V;k++)
	{
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				if(dist[i][k]+dist[k][j] < dist[i][j])
					dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}


	cout<<"\n\n";

    for(int i=0;i<V;i++)
    {
    	for(int j=0;j<V;j++){
    		if(dist[i][j]==INF)
    			cout<<"INF\t";
    		else
              	cout<<dist[i][j]<<"\t";
    	}
    	cout<<"\n";
    }
    cout<<"\n\n";

}


int main()
{
	//int V,E;
	
	/*cout<<"\nenter the number of nodes\t";
	cin>>V;
	cout<<"\nenter the number of edges\t";
	cin>>E;  */
   
	int g[4][4]={   {0,5,INF,10},
	                {INF,0,3,INF},
	                {INF,INF,0,1},
	                {INF,INF,INF,0}
	            };

	/*for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			cout<<"\nenter weight for "<<i<<"->"<<j<<"\t";
			cin>>g[i][j];
		}
	}  */



	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			//cout<<"\nenter weight for "<<i<<"->"<<j<<"\t";
			cout<<g[i][j]<<"\t";
		}
		cout<<"\n";
	}

	floyd(g,4);
	return 0;
}