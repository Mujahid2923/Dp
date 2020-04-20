#include<bits/stdc++.h>
using namespace std;

#define          CIN                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ld                     long double
#define          ull                    unsigned long long int
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          ff                     first
#define          ss                     second
#define          pb                     push_back
#define          sc                     scanf
#define          pf                     printf
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scin3(x,y,z)           scanf("%d %d %d",&(x),&(y),&(z))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
#define          scln3(x,y,z)           scanf("%lld %lld %lld",&(x),&(y),&(z))
#define          min3(a,b,c)            min( { a, b , c } )
#define          min4(a,b,c,d)          min(d,min(a,min(b,c)))
#define          max3(a,b,c)            max(a,max(b,c))
#define          max4(a,b,c,d)          max(d,max(a,max(b,c)))
#define          ms(a,b)                memset(a,b,sizeof(a))
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
//#define          input                  freopen("input.txt","rt", stdin)
//#define          output                 freopen("output.txt","wt", stdout)
#define          PI                     acos(-1.0)
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Max(v)                 *max_element(all(v))
#define          Min(v)                 *min_element(all(v))
#define          Upper(c,x)             (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)             (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)              (X).erase(unique(all(X)),(X).end())
#define          no                     cout << "NO" << endl ;
#define          yes                    cout << "YES" << endl ;
#define          DBG                    cout << endl << "---------------" << endl ;
#define segment_trele int Lnode = node << 1 , Rnode = Lnode + 1 , mid = ( b + e ) >> 1 ;

#define siz 10005
int cap, n ;
int P[ siz ], W[ siz ] ;
int dp[ siz ][ siz ] ;

int main()
{
    scin2( cap, n ) ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        scin2( W[ i ], P[ i ] ) ;
    }

    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= cap ; j ++ )
        {
            if( j >= W[ i ] )
            {
                dp[ i ][ j ] = max( dp[ i - 1 ][ j ] , P[ i ] + dp[ i - 1 ][ j - W[ i ] ] ) ;
            }
            else
            {
                dp[ i ][ j ] = dp[ i - 1 ][ j ] ;
            }
        }
    }

    pf( "%d\n", dp[ n ][ cap ] ) ;
    return 0 ;
}


