#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
//find_by_order
//order_of_key

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }


double ha,hb,hc;

double func( int a,int b,int c ){
    return a * 1.0/ha + b * 1.0/hb + c * 1.0/hc;
}

const double EPS = 1e-8;

int main(){

    int kase;
    scanf("%d",&kase);

    while ( kase >0 ){

        scanf("%lf %lf %lf",&ha,&hb,&hc);

        if ( ha <EPS || hb <EPS || hc <EPS ){
            printf("These are invalid inputs!\n");
            kase--;
            continue;
        }

        double val = func(1,1,1) * func( 1,1,-1 ) * func( 1,-1,1 ) * func( -1,1,1 );
        if ( val <0 ){
            printf("These are invalid inputs!\n");
            kase--;
            continue;
        }

        printf("%.3f\n",1.0/sqrt( val ));

    }

    return 0;
}
