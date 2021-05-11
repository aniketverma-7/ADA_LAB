#include<bits/stdc++.h>
using namespace std;

#define N 8
long long int inf = INT_MAX;

int shortestDist(int graph[N][N]) 
{

	int dist[N];

	dist[N-1] = 0;

	for (int i = N-2 ; i >= 0 ; i--)
	{

		dist[i] = inf;
		for (int j = i ; j < N ; j++)
		{

			if (graph[i][j] == inf)
				continue;

			dist[i] = min(dist[i], graph[i][j] + dist[j]);
		}
	}

	return dist[0];
}


int main()
{

	int graph[N][N] =
	{{inf, 1, 21, 3, inf, inf, inf, inf},
	{inf, inf, inf, inf, 4, 11, inf, inf},
	{inf, inf, inf, inf, 9, 5, 3, inf},
	{inf, inf, inf, inf, inf, inf, 2, inf},
	{inf, inf, inf, inf, inf, inf, inf, 5},
	{inf, inf, inf, inf, inf, inf, inf, 1},
	{inf, inf, inf, inf, inf, inf, inf, 2}};

	cout << shortestDist(graph);
	return 0;
}
