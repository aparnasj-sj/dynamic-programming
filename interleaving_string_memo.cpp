//Given A, B, C, find whether C is formed by the interleaving of A and B.
int dp[151][151][151];
int helper(int i,int j,int k,string a, string b, string c){
   // mistakes : 3 case: 1) both string has char left 
   // 2) if a is over , need to try make rest from b alone
    // 2) if b is over , need to try make rest from a alone
    if(i==a.length()&&j==b.length()&&k==c.length()){
        return 1;
    }
     if(k==c.size()) return 0;

    if(i==a.size() && j==b.size())

        return 0;
  
     if(dp[i][j][k]!=-1){return dp[i][j][k];}
    int ans=0;
    if(i==a.length()){
        if(b[j]==c[k])
        return helper(i,j+1,k+1,a,b,c);
        return 0;
    }
     if(j==b.length()){
        if(a[i]==c[k])
        return helper(i+1,j,k+1,a,b,c);
        return 0;
    }
 
    if(a[i]==c[k]){
        //cout<<a[i]<<" "<<c[k]<<endl;
        ans=max(ans,helper(i+1,j,k+1,a,b,c));

    }
    if(b[j]==c[k]){//cout<<b[j]<<" "<<c[k]<<endl;
        ans=max(ans,helper(i,j+1,k+1,a,b,c));

    }
    return dp[i][j][k]=ans;

}
int Solution::isInterleave(string a, string b, string c) {
  for(int i=0;i<151;i++)

        for(int j=0;j<151;j++)

            for(int k=0;k<151;k++)

                dp[i][j][k]=-1;
    return helper(0,0,0,a,b,c);
}
