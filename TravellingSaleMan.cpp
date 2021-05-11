#include<bits/stdc++.h>
using namespace std;

#define MAX 9999

int n=4;

int distance[10][10] = 
{                
  {0, 10, 15, 20},
  {10, 0, 35, 25},
  {15, 35, 0, 30},
  {20, 25, 30, 0}
};
int completedVisit = (1<<n) -1;

int arr[16][4];


int  TSP(int mark,int position)
{

  if(mark==completed_visit)
  {      
                                  
    return distan[position][0];
  }
  if(arr[mark][position]!=-1)
  {
     return arr[mark][position];
  }

 
  int answer = MAX;

  
  for(int city=0;city<n;city++)
  {

    if((mark&(1<<city))==0)
    {
       int newAnswer = distan[position][city] + TSP( mark|(1<<city),city);
       answer = min(answer, newAnswer);
    }

  }

  return arr[mark][position] = answer;
}

int main()
{
  for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j] = -1;
        }
    }
  cout<<"Minimum Distance Travelled by you is "<<TSP(1,0);

  return 0;
}