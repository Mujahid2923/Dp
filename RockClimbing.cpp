**************************-------------------------------------LOJ1047 -----------------------------------********************
ll n, a, b, c, test ;
ll arr[ 25 ][ 5 ] ,dp[ 25 ][ 5 ] ;

void Reset()
{
    zero( dp ) ;
}

void Input()
{
    scanf( "%lld", &n ) ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= 3 ; j ++ )
        {
            scanf( "%lld", &arr[ i ][ j ] ) ;
        }
    }
}

void Calculation()
{
    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= 3 ; j ++ )
        {
            if( j == 1 ) dp[ i ][ j ] = min( arr[ i ][ j ] + dp[ i - 1 ][ 2 ], arr[ i ][ j ] + dp[ i - 1 ][ 3 ] ) ;
            if( j == 2 ) dp[ i ][ j ] = min( arr[ i ][ j ] + dp[ i - 1 ][ 1 ], arr[ i ][ j ] + dp[ i - 1 ][ 3 ] ) ;
            if( j == 3 ) dp[ i ][ j ] = min( arr[ i ][ j ] + dp[ i - 1 ][ 1 ], arr[ i ][ j ] + dp[ i - 1 ][ 2 ] ) ;
        }
    }
    pf( "Case %lld: %lld\n", ++ test , min( { dp[ n ][ 1 ], dp[ n ][ 2 ], dp[ n ][ 3 ] } ) ) ;
}

***************************------------------------------Recursive--------------------------------******************************

ll arr[ 1005 ][ 1005 ] ;
ll DP[ 1005 ][ 1005 ] ;
ll row, col ;

ll calling( ll i, ll j )
{
    if( i >= 0 && i < row && j >= 0 && j < col )
    {
        if( DP[ i ][ j ] != -1 )
        {
            return DP[ i ][ j ] ;
        }
        ll ans = INT_MIN ;
        ans = max( ans, calling( i + 1, j ) + arr[ i ][ j ] ) ;
        //cout << "F -> " << ans << endl ;
        ans = max( ans, calling( i + 1, j - 1 ) + arr[ i ][ j ] ) ;
        //cout << "S -> " << ans << endl ;
        ans = max( ans, calling( i + 1, j + 1 ) + arr[ i ][ j ] ) ;
        //cout << "T -> " << ans << endl ;
        return DP[ i ][ j ] = ans ;
    }
    else
    {
        return 0 ;
    }
}

int main()
{
    cin >> row >> col ;
    for( int i = 0 ; i < row ; i ++ )
    {
        for( int j = 0 ; j < col ; j ++ )
        {
            cin >> arr[ i ][ j ] ;
        }
    }
    memset( DP, -1, sizeof DP ) ;
    cout << calling( 0, 0 ) << endl ;

    return 0 ;
}

/*
3 3
-1 2 5
4 -2 3
1 2 10
*/
