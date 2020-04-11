//https://acm.timus.ru/problem.aspx?space=1&num=1167

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

ll n , k ;
vector < ll > v ;
ll dp[ 505 ][ 505 ] ;
ll Fun( int pos , int taken )
{
    if( pos == n ) return 0 ;
    if( taken == k ) return INT_MAX ;


    if( dp[ pos ][ taken ] != -1 )
    {
        return dp[ pos ][ taken ] ;
    }

    ll one = 0 , zero = 0 , mn = INT_MAX ;
    for( int i = pos ; i < n ; i ++ )
    {
        if( v[ i ] ) one ++ ;
        else zero ++ ;
        mn = min( mn , one * zero + Fun( i + 1 , taken + 1 ) ) ;
    }
    return dp[ pos ][ taken ] = mn ;
}

int main()
{
    memset( dp , -1 , sizeof dp ) ;

    scln2( n , k ) ;
    int a ;
    for( int i = 0 ; i < n ; i ++ )
    {
        scln( a ) ;
        v.push_back( a ) ;
    }

    ll ans = Fun( 0 , 0 ) ;
    pf( "%lld\n" , ans ) ;

    return 0 ;
}
