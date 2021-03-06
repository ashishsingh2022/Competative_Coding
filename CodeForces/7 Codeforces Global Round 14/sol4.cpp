#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
INT mod=1000000007;
INT p=0;
bool is_prime[3];
void prime_upto_n(INT,bool*);


void pre_process()
{

}
bool once=false;
void solve()
{
    INT n;
    INT l,r;
    INT ans1=0;
    INT ans2=0;
    cin>>n>>l>>r;
    unordered_map<INT,INT>mp;
    INT i,j;
    INT left=0;
    INT right=0;
    for(i=0;i<l;i++)
        {
            INT temp;
            cin>>temp;
            mp[temp]++;
        }
    for(i=0;i<r;i++)
        {
            INT temp;
            cin>>temp;
            mp[temp]--;
        }
    unordered_map<INT,INT>::iterator itr;
    for(itr=mp.begin();itr!=mp.end();itr++)
        {
            INT num=itr->second;
            if(num>0)left+=num;
            if(num<0)right+=abs(num);
        }
    INT diff=left-right;
    INT rem_left=0;
    INT rem_right=0;
    INT cost=0;
    for(itr=mp.begin();itr!=mp.end();itr++)
        {
            INT num=itr->second;
            INT minn=0;
            if(diff>0 && num>0)
                {
                    minn=min((num/2)*2,(diff/2)*2);
                    itr->second-=minn;
                    diff-=minn;
                }
            else if(diff<0 && num<0)
                {
                    minn=min(abs((num/2)*2),abs(diff/2)*2);
                    itr->second+=minn;
                    diff+=minn;
                }
            cost+=minn/2;
            if(itr->second>0)rem_left+=itr->second;
            if(itr->second<0)rem_right+=abs(itr->second);
        }
    cost+=min(rem_left,rem_right)+max(rem_left,rem_right)-min(rem_left,rem_right);
    cout<<cost<<endl;



}








int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pre_process();
    if(once)
        {
            solve();
        }
    else
        {
            INT t;
            cin>>t;
            while(t--)
                {
                    solve();
                }
        }
    return 0;
}



void prime_upto_n(INT n,bool is_prime[])
{
    INT i;
    for(i=0;i<=n;i++)is_prime[i]=true;
    is_prime[1]=false;
    is_prime[0]=false;
    for(INT p=2;p*p<=n;p++)
        {
            if(is_prime[p])
                {
                    for(INT i=p*p;i<=n;i+=p)
                        {
                            is_prime[i]=false;
                        }
                }
        }
    for(INT i=0;i<=n;i++)
        {
            if(is_prime[i])cout<<i<<" ";
        }
}
