#include <forward_list>
#include <deque>
#include <algorithm>
#include <string>

std::deque<std::string> lengthSort( std::forward_list<std::string> words )
{
    words.sort( 
        []( const std::string& fw, const std::string& sw ){
            return fw.size() < sw.size() || ( fw.size() == sw.size() && fw < sw ); 
    });
    
    std::deque<std::string> sorted_words;
    for( auto & el : words )
        sorted_words.push_back( el );
    return sorted_words;
}