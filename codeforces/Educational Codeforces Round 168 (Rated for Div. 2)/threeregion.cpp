x
       char a[n+5][3];
       for(int i=1;i<=n;i++)cin>>a[i][0];
       for(int i=1;i<=n;i++)cin>>a[i][1];

       a[0][0]=a[0][1]=a[n+1][0]=a[n+1][1]='x';
 int sp=1;
 int cnt=0;
 map<int,int>mp;
 

 for(int i=1;i<=n+1;i++)
 {
    if(a[i][0]==a[i][1]&&a[i][1]=='.')cnt+=2;
    else if(a[i][1]!=a[i][0])
    {
       if((a[i][1]==a[i-1][1]&&a[i][1]=='.')||(a[i][0]==a[i-1][0]&&a[i][0]=='.'))cnt++;
       else 
       { 
        if(cnt>0)
         mp[++sp]=cnt;
         cnt++;
       }

       
    }
    else{
        
         if(cnt>0)
         mp[++sp]=cnt;
         cnt=0;
    }
 }
 int ans=0;
 

  if(mp.size()==1)
  {        string s="...";
           string t="x.x";
           
           
        for(int i=1;i<=n-1;i++)
        {  
                bool ok=true;
                for(int j=0;j<3;j++)
                { 
                    if(s[j]!=a[i+j][0])ok=false;
                     if(t[j]!=a[i+j][1])ok=false;


                }

                if(ok)ans++;
 ok=true;
                for(int j=0;j<3;j++)
                { 
                    if(s[j]!=a[i+j][1])ok=false;
                     if(t[j]!=a[i+j][0])ok=false;


                }

                if(ok)ans++;


            
        }
  }
  else if(mp.size()==2)
  {
      string s="...";

      for(int i=0;i<=n;i++)
      {  
         if(a[i+1][0]=='x')
         {
             bool ok=true;
            for(int j=0;j<3;j++)
            {
                if(s[j]!=a[i+j][1])ok=false;
            }
              if(ok)ans++;
         }

         if(a[i+1][1]=='x')
         {
             bool ok=true;
            for(int j=0;j<3;j++)
            {
                if(s[j]!=a[i+j][0])ok=false;
            }
              if(ok)ans++;
         }


      }

  }
  else if(mp.size()==3){
    for(auto &[x,y]:mp)
    {
        ans+=y-1;
    }
  }
    else if(mp.size()==4)
    {

         for(auto &[x,y]:mp)
    {
        ans+=(y==1);
    }
    }
  
  cout<<ans<<endl;
 
return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;
cin>>t;
// t=1;
while(t--)
solve();
return 0;
}