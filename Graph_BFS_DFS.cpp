#include<bits/stdc++.h>
using namespace std;

class Graph
{	
	int v;
	map<int,list<int>> edges;
	
	public:
		Graph(int v){this->v=v;}
		void addEdge(int v,int u)
		{
			edges[v].push_back(u);
			edges[u].push_back(v);
		}

		void bfs(int src) // breath first search
		{
			map<int,bool> visited;
			queue<int> wait;

			wait.push(src);
			visited[src]=true;

			while(!wait.empty())
			{
				int temp = wait.front();
				wait.pop();

				for(auto ver:edges[temp])
				{
					if(!visited[ver])
					{
						wait.push(ver);
						visited[ver]=true;
					}
				}
				cout<<temp<<" ";
			}
			cout<<"\n";
		}

		void helper(int src)
		{
			map<int,bool> visited;
			dfs(src,visited);
			cout<<"\n";
		}

		void dfs(int src,map<int,bool> &visited)//depth first search
		{
			cout<<src<<" ";
			visited[src]=true;

			for(auto temp:edges[src])
			{
				if(!visited[temp])dfs(temp,visited);
			}
		}

		
};

int main()
{

	Graph g(5);

	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(0,4);
	g.addEdge(3,4);
	g.addEdge(1,2);

	g.bfs(0);
	g.helper(0);
	
	return 0;
}


