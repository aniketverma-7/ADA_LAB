#include<bits/stdc++.h>
using namespace std;
const int N = 5;



void displaytheSolution(int path[]);

bool isSafe(int n, bool g[N][N], int path[], int pos) {
   if (g [path[pos-1]][n] == 0)
      return false;
   for (int i = 0; i < pos; i++)
      if (path[i] == n)
         return false;
   return true;
}
bool hamiltonianCycle(bool g[N][N], int path[], int pos) 
{

   if (pos == N) {
      if (g[ path[pos-1] ][ path[0] ] == 1)
         return true;
      else
         return false;
   }
   for (int n = 1; n < N; n++) 
   {
      if (isSafe(n, g, path, pos))
      {
         path[pos] = n;
         if (hamiltonianCycle (g, path, pos+1) == true)
            return true;
         path[pos] = -1;
      }
   }
   return false;
}

bool hamCycle(bool g[N][N]) 
{
   int *path = new int[N];
   for (int i = 0; i < N; i++)
      path[i] = -1;
   
   path[0] = 0;
   if (hamiltonianCycle(g, path, 1) == false) 
   {
      cout<<"\nCycle does not exist"<<endl;
      return false;
   }

   displaytheSolution(path);
   return true;
}

void displaytheSolution(int p[]) 
{
   cout<<"Cycle Exists:";
   cout<<" Following is one Hamiltonian Cycle \n"<<endl;
   for (int i = 0; i < N; i++)
      cout<<p[i]<<" ";

      cout<< p[0]<<endl;
}

int main() {
   bool g[N][N] = {
      {0, 1, 0, 1, 1},
      {0, 0, 1, 1, 0},
      {0, 1, 0, 1, 1},
      {1, 1, 1, 0, 1},
      {0, 1, 1, 0, 0},
   };
   hamCycle(g);
   return 0;
}