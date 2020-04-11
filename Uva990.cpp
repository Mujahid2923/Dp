///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define          CIN                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ld                     long double
#define          ull                    unsigned long long int
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          vi                     vector<int>
#define          vl                     vector<ll>
#define          pb                     push_back
#define          sc                     scanf
#define          pf                     printf
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scin3(x,y,z)           scanf("%d %d %d",&(x),&(y),&(z))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
#define          scln3(x,y,z)           scanf("%lld %lld %lld",&(x),&(y),&(z))
#define          min3(a,b,c)            min(a,min(b,c))
#define          min4(a,b,c,d)          min(d,min(a,min(b,c)))
#define          max3(a,b,c)            max(a,max(b,c))
#define          max4(a,b,c,d)          max(d,max(a,max(b,c)))
#define          ms(a,b)                memset(a,b,sizeof(a))
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
//#define          input                  freopen("input.txt","rt", stdin)
#define          output                 freopen("output.txt","wt", stdout)
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
#define segment_tree int Lnode = node << 1 , Rnode = Lnode + 1 , mid = ( b + e ) >> 1 ;


///bool operator < ( const Node& p ) const{ return cost < p.cost ; }
///priority_queue<int,vector<int>,greater<int> >pq;
///string str = "abcdefghijklmnopqrstuvwxyz";
///string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
///string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
///string s = std::bitset<64>(n).to_string();
///---------------Order set-------------------
///template<typename T> using orderset =tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
///#include <ext/pb_ds/assoc_container.hpp>
///using namespace __gnu_pbds;
///*os.find_by_order(index) os.order_of_key(value)

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

#define mx 1005
vi vec ;

ll n, t, w, a, b, c ;
int d[ mx ], v[ mx ], dp[ 32 ][ mx ], path[ 32 ][ mx ] ;

int Fun( int pos, int cap_now )
{
    if( pos == n )
    {
        return 0 ;
    }

    if( dp[ pos ][ cap_now ] != -1 )
    {
        return dp[ pos ][ cap_now ] ;
    }

    int r1 = 0, r2 ;
    if( cap_now + ( 3 * w * d[ pos ] ) <= t )
    {
        r1 = v[ pos ] + Fun( pos + 1, cap_now + ( 3 * w * d[ pos ] ) ) ;
    }

    r2 = Fun( pos + 1, cap_now ) ;
    if( r1 > r2 )
    {
        path[ pos ][ cap_now ] = 1 ;
    }
    else
    {
        path[ pos ][ cap_now ] = 2 ;
    }

    return dp[ pos ][ cap_now ] = max( r1, r2 ) ;
}

int print_path( int pos, int cap_now )
{
    if( path[ pos ][ cap_now ] == -1 )
    {
        return 0 ;
    }

    if( path[ pos ][ cap_now ] == 1 )
    {
        vec.pb( pos ) ;
        return 1 + print_path( pos + 1, cap_now + ( 3 * w * d[ pos ] ) ) ;
    }
    else
    {
        return print_path( pos + 1, cap_now ) ;
    }
}

int main()
{
    //output ;
    bool ok = false ;
    while( cin >> t >> w ) // scin2( t , w ) == 2
    {
        if( ok )
        {
            pf( "\n" ) ;
        }
        ok = true ;
        scin( n ) ;
        for( int i = 0 ; i < n ; i ++ )
        {
            scin2( d[ i ], v[ i ] ) ;
        }
        memset( dp, -1, sizeof dp ) ;
        memset( path, -1, sizeof path ) ;
        int profit = Fun( 0, 0 ) ;
        int ans = print_path( 0, 0 ) ;

        pf( "%d\n", profit ) ;
        pf( "%d\n", ans ) ;

        for( int i = 0 ; i < vec.size() ; i ++ )
        {
            pf( "%d %d\n", d[ vec[ i ] ], v[ vec[ i ] ] ) ;
        }
        vec.clear() ;
    }
    return 0 ;
}

