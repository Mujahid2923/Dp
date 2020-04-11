#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;


#define          CIN                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          pf                     printf
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
#define          Min(v)                 *min_element(v.begin() , v.end())
#define          output                 freopen("output.txt","wt", stdout)

int t, n, k, sum ;
vector < int > v, v1 ;
int dp[ 105 ][ 50005 ] ;
int Fun( int pos, int total )
{
    if( pos == n + 1 || 2 * total > sum ) return 0 ;
    if( dp[ pos ][ total ] != -1 ) return dp[ pos ][ total ] ;

    if( sum - 2 * total >= 0 )
    {
        v1.push_back( sum - 2 * total ) ;
    }

    Fun( pos + 1, v[ pos ] + total ) ;
    Fun( pos + 1, total ) ;
    return dp[ pos ][ total ] = total ;
}

int main()
{
    scin( t ) ;
    while( t-- )
    {
        sum = 0 ;
        memset( dp, -1, sizeof dp ) ;
        scin( n ) ;
        int a ;
        for( int i = 0 ; i < n ; i ++ )
        {
            scin( a ) ;
            sum += a ;
            v.push_back( a ) ;
        }

        int ans = Fun( 0, 0 ) ;
        pf( "%d\n", Min( v1 ) ) ;


        v.clear() ;
        v1.clear() ;
    }


    return 0 ;
}

