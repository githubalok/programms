#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int ,double> a,pair<int,double> b)
{
	 
	if(a.second/a.first>b.second/b.first)
		return 1;
	else
		return 0;
}



int knapsak(vector<pair<int,double> > v,int N,int S)
{
	int k;
	double profit=0.00;

	for(k=0;k<N;k++)
	{
		if(S>0 && v[k].first<=S)
		{
			S=S-v[k].first;
			profit+=v[k].second;
		}
		else
			break;
	}
	if(S>0)
	  profit+=v[k].second/v[k].first*S;                     

	return profit;
}


int main()
{
	vector<pair<int,double> > v;
	int N,S;

	cout<<"\nenter the number of objects\t";
	cin>>N;
	cout<<"\nenter the maximum weight\t";
	cin>>S;

	for(int i=1;i<=N;i++)
	{
		double y;
		int x;
		cout<<"\nenter weight and profit\n";
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	cout<<"\nweight"<<"\t"<<"profit\n";

	for(int i=0;i<N;i++)
	{
		cout<<v[i].first<<"\t"<<v[i].second<<"\n";
	}



	sort(v.begin(),v.end(),compare);



	cout<<"\nweight"<<"\t"<<"profit\n";

	for(int i=0;i<N;i++)
	{
		cout<<v[i].first<<"\t"<<v[i].second<<"\n";
	} 

	cout<<"\ntotal profit\t"<<knapsak(v,N,S);
	cout<<"\n"; 
	
	return 0;

}