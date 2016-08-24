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
		vector<vector<int> > destination2(n, vector<int>(n));
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
		for(int i =0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin >> destination2[i][j];
				
			}
		}
		int k;
		cin >> k;
		//0 - dont replace with 0
		
		Q.push(make_pair(source, 0));
		vector<vector<int> > tmp;
		int flag;
		while(!Q.empty())
		{
			tmp = Q.front().first;
			flag = Q.front().second;
			Q.pop();
			visited[tmp] = 1;
			
			if(flag == 0)
			{
			
				if(tmp == destination)
				{
					break;
				}
			}
			else
			{
				
				if(tmp == destination2)
				{
					break;
				}
			}
			vector<vector<int> > tmp2(tmp);
				
			
			for(int i=0;i<n;i++)
			{
				tmp2 = tmp;
				int found = 0;
				for(int j = 0;j<n && !flag ;j++)
				{
					if(tmp2[i][j] == k)
					{
						found = 1;
						break;
					}
				}
				for(int j = 0; j<n ;j++)
				{
					
					rotate_row(tmp2, i);
					
					if(visited[tmp2]==0)
					{
						parent[tmp2] = tmp;
						visited[tmp2] = 1;
						if(found || flag)
							Q.push(make_pair(tmp2, 1));
						else
							Q.push(make_pair(tmp2, 0));
					}
					
				}
				
			}
			
			for(int i=0;i<n;i++)
			{
				tmp2 = tmp;
				int found = 0;
				for(int j = 0;j<n && !flag;j++)
				{
					if(tmp2[j][i] == k)
					{
						found = 0;
						break;
					}
				}
				for(int j = 0; j<n-1 ;j++)
				{
					rotate_col(tmp2, i);
					if(visited[tmp2]==0)
					{
						parent[tmp2] = tmp;
						visited[tmp2] = 1;
						if(found || flag)
							Q.push(make_pair(tmp2, 1));
						else
							Q.push(make_pair(tmp2, 0));
					}
					
				}
			}
		}
		if(!flag)
			printpath(source, destination, parent);
		else
			printpath(source, destination2, parent);

	
	}

}
