#include<bits/stdc++.h>
using namespace std;

int DP[ 100 ] ;

///Recursive way

int fun1( int n )
{
    if( n <= 1 )
    {
        return n ;
    }

    if( DP[ n ] != -1 )
    {
        return DP[ n ] ;
    }
    else
    {
        DP[ n ] = fun1( n - 1 ) + fun1( n - 2 ) ;
        return DP[ n ] ;
    }
}

///Iterative way

int fun2( int n )
{
    if( n <= 1 )
    {
        return n;
    }
    DP[ 0 ] = 0 ;
    DP[ 1 ] = 1 ;

    for( int i = 2 ; i <= n ; i ++ )
    {
        DP[ i ] = DP[ i - 2 ] + DP[ i - 1 ] ;
    }
    return DP[ n ] ;
}

int main()
{
    int n;
    cin>>n;
    memset( DP, -1, sizeof DP ) ;
    fun1(n);
    //fun2(n);
    cout<<DP[n]<<endl;
    return 0;
}




