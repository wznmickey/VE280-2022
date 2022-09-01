#ifndef DICT_HPP
#define DICT_HPP
#endif

// Template need source file to complete code, so the template code is needed to be included.

template < class K, class V > V *Dict< K, V >::find( K k )
{
    auto it = values.begin( );
    for ( decltype( keys.size( ) ) i = 0; i < keys.size( ); i++ )
    {
        if ( ( keys [ i ] ) == k )
        {
            return &( *it );
        }
        it++;
    }
    return nullptr;
}
template < class K, class V > void Dict< K, V >::insert( K k, V v )
{
    auto i = find( k );
    if ( i == nullptr )
    {
        keys.push_back( k );
        values.push_back( v );
    }
    else
    {
        *i = v;
    }
    return;
}
template < class K, class V > void Dict< K, V >::remove( K k )
{
    auto it = values.begin( );
    for ( decltype( keys.size( ) ) i = 0; i < keys.size( ); i++ )
    {
        if ( ( keys [ i ] ) == k )
        {
            values.erase( it );
            keys.erase( keys.begin( ) + i );
        }
        it++;
    }
    return;
}
template < class K, class V > unsigned int Dict< K, V >::size( )
{
    return keys.size( );
}