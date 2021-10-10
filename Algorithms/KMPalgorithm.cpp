//Given a text s[0..n-1] and a pattern a[0..m-1]. Find pos at which a occurs in s
//Example:
//   Input:  s[] = "THIS IS A TEST TEXT"
//           a[] = "TEST"
//   Output: Pattern found at index 10

#include<bits/stdc++.h>
using namespace std;
void prefix(string s, vector<int>&pre){
    int n=s.length();
    pre[0]=0;
    for(int i=1;i<n;i++){
       int j=pre[i-1];
       while(j>0 && s[i]!=s[j]){
           j=pre[j-1];
       }
       if(s[i]==s[j]){
           j++;
       }
       pre[i]=j;
    }
}
int main(){
    //s is the text and a is the pattern we need to search
    string s, a;
    cin>>s>>a;
    int n=s.length();
    int m=a.length();
    
   // create pre[] that will hold the longest prefix suffix values for pattern
   vector<int>pre(m);
    prefix(a,pre);
   int i=0, // index for s[] 
   int j=0,   // index for a[]
   int pos=0;   
   while(i<n){
       if(s[i]==a[j]){
           i++, j++;
           
       }
       else{
           if(j!=0){
               j=pre[j-1];
           }
           else{
               i++;
           }
       }
       if(j==m){
           pos=i-m;
           break;
       }
   }
   cout<<pos;
    return 0;
}
