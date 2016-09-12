#include <bits/stdc++.h>
using namespace std;
#define ok printf("Ok\n")
#define pf printf
#define sf scanf
#define ne printf("\n")
#define vi(x) vector<int>x
#define vs(x) vector<string>x
#define pb(x,i) x.push_back(i)
#define rep(i,j) for(i=0;i<j;i++)
#define repe(i,j) for(i=1;i<=j;i++)
#define per(i,j) for(i=j;i>=0;i--)
#define case(x) pf("Case %d: ",x)
#define all(x) x.begin(),x.end()
#define clr(x) x.erase(all(x));
#define srt(x) sort(all(x))
#define sum(x) accumulate(all(x),0)
#define SET(x) memset(x,0,sizeof(x))
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define po(base,power) pow(base+0.0,power)
#define Ms 10000
int prec(char c)
{
    if(c=='+' || c=='-')
        return 1;
    if(c=='*' || c=='/')
        return 2;
        else if(c=='^')
            return 3;
        else
            return 0;
}
int main()
{
  string A,B;
  stack<char>C;
  int t;
  cin>>t;
  for(int k=0;k<t;k++)
  {
  cin>>A;
  int l=A.size();
  for(int i=0;i<l;i++)
  {
      if(A[i]>=97 && A[i]<=124) {
        B+=A[i];
//        cout<<B<<endl;
//        cout<<"C:"<<C.top()<<endl;
      }
      else
      {
          if(A[i]==')')
          {
              while(C.top()!='(')
              {
                  B+=C.top();
                  C.pop();
              }
              C.pop();
//              cout<<C.top()<<endl;
          }

            else if(A[i]=='(') {
                    C.push(A[i]);}
            else
              {
                  int p=prec(A[i]);int vp;
                  if(C.size()!=0)
                   vp=prec(C.top());
                else
                    vp=0;
                  if(p<=vp)
                  {
                      if(C.size()!=0 && C.top()!='(' && A[i]!='(') {
                      B+=C.top();
                      C.pop();}
                      C.push(A[i]);

                  }
                  else if( C.size()>0 && ((C.top()>=42 &&C.top()<=47)|| C.top()=='^') && p>vp ){
                        B+=A[i+1];
                  B+=A[i];
                  i++;
//                    C.push(A[i]);
                  }
                  else
                    C.push(A[i]);
              }
      }
//      cout<<B<<endl;
//      if(C.size()!=0)
//        cout<<i<<" "<<C.top()<<endl;
//      else
//        cout<<i<<": E"<<endl;
  }
  while(C.size()!=0)
  {
      B+=C.top();
      C.pop();
  }
  cout<<B<<endl;
  C=stack<char>();
  clr(B);
  }
}

