#include<bits/stdc++.h>
using namespace std;

int table[ 100 ][ 100 ] ;

int nCr(int n,int r)
{
    if( r == 1 )
    {
        return n;
    }
    if( r == n )
    {
        return 1;
    }

    if( table[ n ][ r ] != -1 )
    {
        return table[ n ][ r ] ;
    }
    else
    {
        table[ n ][ r ] = nCr( n - 1 , r ) + nCr( n - 1 , r - 1 ) ;
        return table[ n ][ r ] ;
    }
}

int main()
{
    int n,r;
    cin >> n >> r ;
    memset( table , -1 , sizeof table ) ;
    nCr( n , r ) ;
    cout << table[ n ][ r ] << endl ;
    return 0 ;
}

