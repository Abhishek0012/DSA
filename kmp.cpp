#include<iostream>
using namespace std;
class match_algorithm
{
    public:
    bool kmp(string pattern , string to_match)
    {
       int n=pattern.length();
       int arr[n];
       arr[0]=0;
       for(int i=1;i<n;i++)
       {
           int x = arr[i-1];
           if(arr[x]==arr[i]) arr[i]=arr[x-1]+1;
           else arr[i]=0;
       }
       int st=0;
       for(int i=0;i<to_match.length();i++)
       {
           if(st==n) return true;
           if(to_match[i]==pattern[st]) st++;
           else if(st==0)
           {
               continue;
           }
           else
           {
               while(to_match[i]!=pattern[st])
               {
                   st=arr[st-1];
               }
           }
       }
       cout<<st<<endl;
       if(st==n) return true;
       return false;
    }

};
void solve()
{
    string s = "Abhishek";
    string p = "bhis";
    match_algorithm obj;
    cout<<obj.kmp(p,s)<<endl;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        solve();
    }
}