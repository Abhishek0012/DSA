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
           else
           {
               //
           }
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
               while(to_match[i]!=pattern[st] && st>=1)
               {
                   st=arr[st-1];
               }
           }
       }
       if(st==n) return true;
       return false;
    }

};
void solve()
{
    string s = "AABAACAADAABAABA";
    string p = "AABA";
    match_algorithm obj;
    if(obj.kmp(p,s)) cout<<"milgyi re bawa"<<endl;
    else cout<<"nhi mili bhai"<<endl;
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
