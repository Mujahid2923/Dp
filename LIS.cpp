///Uva481
***********************************--------------------------------Nlogn------------------------------------******************************
vector < ll > v1, v2, v3 ;
map < ll, ll > Mp ;
ll n ;

void Fun()
{
    ll n = v1.size() ;
    ll LIS[ n + 2 ] ;
    LIS[ 0 ] = 0 ;

    v2.eb( v1[ 0 ] ) ;
    for( int i = 1 ; i < n ; i++ )
    {
        if( v1[ i ] > v2.back() )
        {
            LIS[ i ] = v2.size() ;
            v2.eb( v1[ i ] ) ;
        }
        else
        {
            int pos = Lower( v2, v1[ i ] ) ;
            LIS[ i ] = pos ;
            v2[ pos ] = v1[ i ] ;
        }
    }

    ll k = v2.size() - 1 ;
    for( int i = n - 1 ; i >= 0 ; i -- )
    {
        if( LIS[ i ] == k )
        {
            v3.eb( v1[ i ] ) ;
            k -- ;
        }
    }
}

int main()
{
    ll a ;
    while( scln( a ) != EOF )
    {
        v1.pb( a ) ;
        Mp[ a ] = -1 ;
    }

    Fun() ;

    reverse( all( v3 ) ) ;

    pf( "%d\n", v3.size() ) ;
    pf( "-\n" ) ;
    for( ll x : v3 )
    {
        pf( "%lld\n", x ) ;
    }
    return 0 ;
}


**************************---------------------------------------N^2-----------------------****************************


vl v , v1 ;
ll arr[ 100005 ] ;

void check()
{
    for( int i = 0 ; i < v.size() ; i ++ )
    {
        ll mx = 0 ;
        for( int j = 0 ; j < i ; j ++ )
        {
            if( v[ j ] <= v[ i ] )
            {
                mx = max( mx, arr[ j ] ) ;
            }
        }
        arr[ i ] += mx ;
    }

    ll ans = INT_MIN ;
    for( int i = 0 ; i < v.size() ; i ++ )
    {
        ans = max( ans, arr[ i ] ) ;
    }
    cout << ans << endl ;
}

int main()
{
    CIN ;
    ll n, a ;
    cin >> n ;
    for( int i = 0 ; i < n ; i ++ )
    {
        cin >> a ;
        arr[ i ] = 1 ;
        v.pb( a ) ;
    }

    check() ;
    int ck = 0, val = INT_MIN ;
    for( int i = 0 ; i < n ; i ++ )
    {
        if( arr[ i ] > val )
        {
            ck = i ;
            val = arr[ i ] ;
        }
    }

    v1.pb( v[ ck ] ) ;
    for( int i = ck ; i >= 0 ; i -- )
    {
        if( arr[ i ] == val - 1 )
        {
            val -- ;
            v1.pb( v[ i ] ) ;
        }
    }

    reverse( all( v1 ) ) ;
    for( auto x : v1 )
    {
        cout << x << " " ;
    }
    return 0 ;
}

/*
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
ans : 6
7
3 4 -1 0 6 2 3
ans : 4
*/


