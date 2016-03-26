#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
	if(a.first>b.first)
		return 1;
	else
		return 0;
}



void jsp(vector<pair<int ,int> > job,int N)
{
	sort(job.begin(),job.end(),compare);




	cout<<"\njob\t"<<"profit\t"<<"deadline\n";
    int i=0;

	while(i!=N)
	{
		cout<<i+1<<"\t"<<job[i].first<<"\t"<<job[i].second<<"\n";
		i++;
	}
	cout<<endl;




    int max=job[0].first;
    
    for(int i=1;i<N;i++)                                     //getting maximum deadline
    {
    	
    	if(max<job[i].first)
    		max=job[i].first;    	 
    }

    vector<int> v(max,0);

    for(int i=0;i<N;i++)
    {
    	int d=job[i].second;
    	for(int k=d-1;k>=0;k--)
    	{
    		if(v[k]==0){
    			v[k]=job[i].first;
    			break;
    		}
    	}
    }
    
    int sum=0;

    for(int i=0;i<N;i++)
    	sum+=v[i];
    cout<<"\nmaximum_profit======    "<<sum<<"\n";
}






int main()
{
	int N;

	cout<<"\nenter the number of jobs\t";
	cin>>N;
    int p,d;
    vector<pair<int,int> > job;

	for(int i=0;i<N;i++)
	{
		cout<<"\nenter the profit and deadline\n";
		cin>>p>>d;
		job.push_back(make_pair(p,d));
	}
	

    cout<<"\njob\t"<<"profit\t"<<"deadline\n";
    int i=0;

	while(i!=N)
	{
		cout<<i+1<<"\t"<<job[i].first<<"\t"<<job[i].second<<"\n";
		i++;
	}
	cout<<endl;

    /*i=0;
    while(i!=N)
	{
		cout<<i+1<<"\t"<<job[i].first<<"\t"<<job[i].second<<"\n";
		i++;
	}
	cout<<endl;   */

	jsp(job,N);
          



	return 0;   
}