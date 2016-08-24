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
		int n;
		cin >> n;
		vector<vector<int> > source(n, vector<int>(n));
		vector<vector<int> > destination(n, vector<int>(n));
		map<vector<vector <int> >, int > visited;
		map<vector<vector <int> >, vector<vector<int> > > parent;
		queue< pair<vector <vector<int> >,  int> > Q;
		
		for(int i =0;i<n;i++)
		{
			
			for(int j=0;j<n;j++)
			{
				cin >> source[i][j];
				
			}
		}
		for(int i =0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin >> destination[i][j];
				
			}
		}
		
		//0 - dont replace with 0
		
		Q.push(make_pair(source, 1));
		vector<vector<int> > tmp;
		while(!Q.empty())
		{
			tmp = Q.front().first;
			int flag = Q.front().second;
			Q.pop();
			visited[tmp] = 1;
			
			if(tmp == destination)
			{
				break;
			}
			vector<vector<int> > tmp2(tmp);
			int flag2 = (flag+1)%2;
			
			if(flag2 == 0)
			{
			
			for(int i=0;i<n;i++)
			{
				tmp2 = tmp;
				
				for(int j = 0; j<n ;j++)
				{
					
					rotate_row(tmp2, i);
					
					if(visited[tmp2]==0)
					{
						parent[tmp2] = tmp;
						visited[tmp2] = 1;
						Q.push(make_pair(tmp2, (flag2)));
					}
					
				}
				
			}
		}
		else
		{
		
			
			for(int i=0;i<n;i++)
			{
				tmp2 = tmp;
				
				for(int j = 0; j<n-1 ;j++)
				{
					rotate_col(tmp2, i);
					
					if(visited[tmp2]==0)
					{
						parent[tmp2] = tmp;
						visited[tmp2] = 1;
						Q.push(make_pair(tmp2, (flag2)));
					}
					
				}
			}
		}
		}
	

		printpath(source, destination, parent);

	
	}

}
