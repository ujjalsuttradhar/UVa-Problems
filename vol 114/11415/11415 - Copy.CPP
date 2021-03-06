#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

const int ggg=1e7 + 1e3;

#define SIZE 3000000

int dp[SIZE];
vector<int> p;

#define LIM 10000

bool prime[LIM];

int calc(int x){
    int cnt = 0;
    for ( int i=0;p[i]*p[i] <= x ;++i ){
        while ( x%p[i]==0 ){
            x/=p[i];
            cnt++;
        }
    }
    if ( x != 1 )cnt++;
    return cnt;
}



int main(){

    for (int i=2;i<LIM;++i){
        prime[i] = true;
    }
    for (int i=2;i*i<=LIM;++i){
        if ( prime[i] ){
            for (int j=i+i;j<LIM;j+=i){
                prime[j]=false;
            }
        }
    }

    for (int i=2;i<LIM;++i){
        if ( prime[i] ){
            p.PB( i );
        }
    }

    dp[1]=0;

    int shaon=2;
    for (;true;++shaon){
        dp[shaon] = dp[shaon-1]+ calc(shaon);
        if ( dp[shaon]>ggg )break;
    }

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        int n;
        scanf("%d",&n);
        int ans = -1;
        int low= 1,high = shaon;
        int mid ;
        while ( low<=high ){
            mid = (low+high)/2;
            if ( dp[mid] <= n ){
                low = mid+1;
            }else{
                high = mid-1;
                ans = mid;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
