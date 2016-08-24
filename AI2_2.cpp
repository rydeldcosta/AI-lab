#include<bits/stdc++.h>

using namespace std;

void printpath(int src, int dest, vector<int> &parent)
{
	if(dest != src)
	{
		printpath(src, parent[dest], parent);
	}
	cout<<dest<<" ";
}
bool compare2D(vector<vector<int> > A, vector<vector<int> > B)
{
	
	int n = A.size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(A[i][j]!=B[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
void rotate_row(vector<vector<int> > &v, int x)
{
	
	int t2 = v[x][0], t1;
	for(int i =1;i<v.size();i++)
	{
		t1 = v[x][i];
		v[x][i] = t2;
		t2 = t1;
	}
	v[x][0] = t1;
//	for(int i=0;i<v.size();i++)
//		cout<<v[x][i]<<" ";
//	cout<<endl;
	
}
void rotate_col(vector<vector<int> > &v, int x)
{
	
	int t2 = v[0][x], t1;
	for(int i =1;i<v.size();i++)
	{
		t1 = v[i][x];
		v[i][x] = t2;
		t2 = t1;
	}
	v[0][x] = t1;
//	for(int i=0;i<v.size();i++)
//		cout<<v[i][x]<<" ";
//	cout<<endl;
	
}
int sumk(vector<vector<int> > v)
{
	int sum = 0;
	for(int i=0;i<v.size();i++)
	{
		sum += v[0][i];
	}
//	cout<<sum<<"s"<<endl;
	return sum;
}
void printpath(vector<vector<int> > source, vector<vector<int> > destination, map<vector<vector <int> >, vector<vector<int> > > parent)
{
	if(destination != source)
	{
		printpath(source, parent[destination], parent);
	}
	for(int i=0;i<source.size();i++)
	{
		for(int j=0;j<source.size();j++)
		{
			cout<<destination[i][j]<<" ";
		}
	}
	cout<<endl;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n;
		vector<vector<int> > source(n, vector<int>(n));
		vector<vector<int> > destination(n, vector<int>(n));
		map<vector<vector <int> >, int > visited;
		map<vector<vector <int> >, vector<vector<int> > > parent;
		queue< vector <vector<int> > > Q;
		
		for(int i =0;i<n;i++)
		{
			
			for(int j=0;j<n;j++)
			{
				cin >> source[i][j];
				
			}
		}
		cin >> k;

		Q.push(source);
		vector<vector<int> > tmp;
		while(!Q.empty())
		{
			tmp = Q.front();
			Q.pop();
			visited[tmp] = 1;
			
			if(sumk(tmp) == k)
			{
				break;
			}
			
			vector<vector<int> > tmp2(tmp);
			for(int i=0;i<n;i++)
			{
				//find break point for rotation
				tmp2 = tmp;
				
				for(int j = 0; j<n ;j++)
				{
					rotate_row(tmp2, i);
					if(visited[tmp2]==0)
					{
						parent[tmp2] = tmp;
						visited[tmp2] = 1;
						Q.push(tmp2);
					}
					
				}
				
			}
			
			//tmp2 = tmp;
			for(int i=0;i<n;i++)
			{
				tmp2 = tmp;
				//find break point for rotation
				for(int j = 0; j<n-1 ;j++)
				{
					rotate_col(tmp2, i);
					if(visited[tmp2]==0)
					{
						parent[tmp2] = tmp;
						visited[tmp2] = 1;
						Q.push(tmp2);
					}
					
				}
			}
		}

		printpath(source, tmp, parent);

	
	}

}
