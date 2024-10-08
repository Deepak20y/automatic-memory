#include<bits/stdc++.h>
using namespace std;
using ll =long long int;
using ull=unsigned long long;
/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/

 char matrix[1005][1005];
 int dist[2][1005][1005];
 bool vis[2][1005][1005];

int n,m;

 void bfs(int p,queue<pair<int,int>>&q)
 {      

     

       while(!q.empty())
       {
           int x=q.front().first;
           int y=q.front().second;
            q.pop();
            if(vis[p][x][y])continue;
             vis[p][x][y]=true;

            if(p==1)
            {
              
              if(x+1<=n&&matrix[x+1][y]!='#')
              {  
                if(dist[p][x+1][y]>dist[p][x][y]+1)
                 {dist[p][x+1][y]=dist[p][x][y]+1;
                 q.push({x+1,y});
                 }
              }

                if(y+1<=m&&matrix[x][y+1]!='#')
              {
                  if(dist[p][x][y+1]>dist[p][x][y]+1)
                 {dist[p][x][y+1]=dist[p][x][y]+1;
                 q.push({x,y+1});
                 }
              }
                if(x-1>=1&&matrix[x-1][y]!='#')
              {
                if(dist[p][x-1][y]>dist[p][x][y]+1)
                 {dist[p][x-1][y]=dist[p][x][y]+1;
                 q.push({x-1,y});
                 }
              }
                if(y-1>=1&&matrix[x][y-1]!='#')
              {
                 if(dist[p][x][y-1]>dist[p][x][y]+1)
                 {dist[p][x][y-1]=dist[p][x][y]+1;
                 q.push({x,y-1});
                 }
              }




            } 
            else{


              if(x+1<=n&&matrix[x+1][y]!='#')
              {  
                if((dist[p][x+1][y]>dist[p][x][y]+1)&&min(dist[p][x][y]+1,dist[p][x+1][y])<dist[p+1][x+1][y])
                 {dist[p][x+1][y]=dist[p][x][y]+1;
                 q.push({x+1,y});
                 }
              }
                      
                if((y+1<=m&&matrix[x][y+1]!='#'))
              {
                  if(dist[p][x][y+1]>dist[p][x][y]+1&&min(dist[p][x][y]+1,dist[p][x][y+1])<dist[p+1][x][y+1])
                 {dist[p][x][y+1]=dist[p][x][y]+1;
                 q.push({x,y+1});
                 }
              }
                if((x-1>=1&&matrix[x-1][y]!='#')&&min(dist[p][x][y]+1,dist[p][x-1][y])<dist[p+1][x-1][y])
              {
                if(dist[p][x-1][y]>dist[p][x][y]+1)
                 {dist[p][x-1][y]=dist[p][x][y]+1;
                 q.push({x-1,y});
                 }
              }
                if((y-1>=1&&matrix[x][y-1]!='#')&&min(dist[p][x][y]+1,dist[p][x][y-1])<dist[p+1][x][y-1])
              {
                 if(dist[p][x][y-1]>dist[p][x][y]+1)
                 {dist[p][x][y-1]=dist[p][x][y]+1;
                 q.push({x,y-1});
                 }
              }



            }
          

     

       }
       return;


 }


//  void pathmatrix(queue<pair<int,int>>&q)
//  {


//     while(!q.empty())
//     {
//       int x=q.front().first;
//       int y=q.front().second;

//        if(x+1<=n&&dist[0][x+1][y]<dist[1][x+1][y])
        
//     }





//  }

 void solve(){
       cin>>n;cin>>m;
           
           queue<pair<int,int>>a,b,c;
       for(int i=1;i<=n;i++)
       { 
        for(int j=1;j<=m;j++)
        {cin>>matrix[i][j];
           dist[0][i][j]=1e9;
           dist[1][i][j]=1e9;
           vis[0][i][j]=false;
           vis[1][i][j]=false;
           // path[i][j]='.';
           if(matrix[i][j]=='A'){a.push({i,j});dist[0][i][j]=0;}
           if(matrix[i][j]=='M'){b.push({i,j});dist[1][i][j]=0;}
        }
       }

       bfs(1,b);
       bfs(0,a);

    

 for(int i=1;i<=n;i++)
    if(dist[0][i][m]!=1e9)c.push({i,m});
    
     for(int i=1;i<=n;i++)
    if(dist[0][i][1]!=1e9)c.push({i,1});

     
 for(int i=1;i<=m;i++)
    if(dist[0][1][i]!=1e9)c.push({1,i});
    
     for(int i=1;i<=m;i++)
    if(dist[0][n][i]!=1e9)c.push({n,i});
 string ans="";

 if(c.size()==0)cout<<"NO"<<endl;
 else{
    cout<<"YES"<<endl;
    while(c.size()>1)c.pop();
    int x=c.front().first;
    int y=c.front().second;
  //  cout<<x<<" "<<y<<endl;
      cout<<dist[0][x][y]<<endl;

      while(dist[0][x][y]>0)
      { //cout<<x<<" "<<y<<endl;

        if(x-1>=1&&dist[0][x-1][y]==dist[0][x][y]-1)
        {
           ans.push_back('D');
           x--;
        }
        else if(y-1>=1&&dist[0][x][y-1]==dist[0][x][y]-1)
           {
              ans.push_back('R');
              y--;
           }
        else if(x+1<=n&&dist[0][x+1][y]==dist[0][x][y]-1)
        {
           ans.push_back('U');
           x++;
        }
        else if(y+1<=m&&dist[0][x][y+1]==dist[0][x][y]-1)
        {
           ans.push_back('L');
           y++;
        }
        

      }
      reverse(ans.begin(),ans.end());
      cout<<ans;


 }



  





return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
solve();
return 0;
}