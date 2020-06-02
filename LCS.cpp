int Fun( int i, int j )
{
   if( i == s1.size() || j == s2.size() ) return 0 ;
   if( dp[ i ][ j ] != -1 ) return dp[ i ][ j ] ;
   int ans = 0 ;
   if( s1[ i ] == s2[ j ] )
   {
       ans = 1 + Fun( i + 1, j + 1 ) ;
   }
   else
   {
       int r1 = Fun( i + 1, j ) ;
       int r2 = Fun( i, j + 1 ) ;
       ans = max( r1, r2 ) ;
   }
   return dp[ i ][ j ] = ans ;
}



///https://www.spoj.com/problems/CRSCNTRY/en/
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

int t, n, m, temp ;
vector < int > A, B ;

int Fun()
{
    int n = A.size() ;
    int m = B.size() ;
    int dp[ n + 2 ][ m + 2 ] ;
    zero( dp ) ;

    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= m ; j ++ )
        {
            if( A[ i - 1 ] == B[ j - 1 ] )
            {
                dp[ i ][ j ] = 1 + dp[ i - 1 ][ j - 1 ] ;
            }
            else
            {
                dp[ i ][ j ] = max( dp[ i ][ j - 1 ], dp[ i - 1 ][ j ] ) ;
            }
        }
    }
    return dp[ n ][ m ] ;
}

int main()
{
    scin( t ) ;
    while( t-- )
    {
        while( scin( temp ) && temp != 0 )
        {
            A.pb( temp ) ;
        }

        int val, res, ans = 0 ;
        while( scin( val ) && val != 0 )
        {
            B.pb( val ) ;
            int in ;
            while( scin( in ) && in != 0  )
            {
                B.pb( in ) ;
            }
            int res = Fun() ;
            ans = max( ans, res ) ;
            B.clear() ;
        }
        pf( "%d\n", ans ) ;
        A.clear() ;
    }


    return 0 ;
}
