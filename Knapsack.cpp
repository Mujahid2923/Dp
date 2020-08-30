***************** -------------------------Knapsack Iterative---------------------------------------****************
    
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


***********************---------------------------------------Knapsack Recursive --------------------------------------------***********************
vl v ;

int t, n, m, a ;
int cap ;
int P[ 1005 ], W[ 1005 ] ;
int DP[ 1005 ][ 50 ] ;

int Fun( int pos, int cap_now )
{
    if( pos == n + 1 )
    {
        return 0 ;
    }
    if( DP[ pos ][ cap_now ] != 0 )
    {
        return DP[ pos ][ cap_now ] ;
    }
    ll r1 = 0, r2 ;
    if( W[ pos ] + cap_now <= cap )
    {
        r1 = P[ pos ] + Fun( pos + 1, cap_now + W[ pos ] ) ;
    }
    r2 = Fun( pos + 1, cap_now ) ;
    return DP[ pos ][ cap_now ] = max( r1, r2 ) ;
}

int main()
{
    CIN ;

    cin >> t ;
    while( t-- )
    {
        cin >> n ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            cin >> P[ i ] >> W[ i ] ;
        }
        cin >> m ;
        ll sum = 0 ;
        for( int i = 1 ; i <= m ; i ++ )
        {
            cin >> a ;
            v.pb( a ) ;
        }
        sort( all( v ) ) ;
        for( int i = 0 ; i < m ; i ++ )
        {
            cap = v[ i ] ;
            zero( DP ) ;
            sum += Fun( 1, 0 ) ;
        }
        cout << sum << endl ;
        v.clear() ;
        zero( DP ) ;
    }

    return 0 ;
}


*****************--------------------------------------------- Unbound Khanpsack -------------------------------**************************
https://www.spoj.com/problems/PIGBANK/en/



int t, a, b, n, cap ;
int dp[ 10005 ] ;
int P[ 505 ], W[ 505 ] ;

int main()
{
    scin( t ) ;
    while( t-- )
    {
        scin2( a, b ) ;
        cap = b - a ;
        scin( n ) ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            scin2( P[ i ], W[ i ] ) ;
        }

        for( int i = 1 ; i <= cap ; i ++ )
        {
            dp[ i ] = 1e8 ;
        }
        for( int i = 1 ; i <= n ; i ++ )
        {
            for( int j = 0 ; j <= cap ; j ++ )
            {
                if( j >= W[ i ] )
                {
                    dp[ j ] = min( dp[ j ], P[ i ] + dp[ j - W[ i ] ] ) ;
                }
            }
        }

        if( dp[ cap ] == 1e8 )
        {
            pf( "This is impossible.\n" ) ;
        }
        else
        {
        pf( "The minimum amount of money in the piggy-bank is %d.\n", dp[ cap ] ) ;
        }
    }

    return 0 ;
}






