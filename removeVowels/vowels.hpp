#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

const std::string VOWELS { "aeyuioAEYUIO" };

std::vector<std::string> removeVowels( std::vector<std::string> words )
{
    std::transform( std::begin( words ), std::end( words ), 
                    std::begin( words ), 
                    []( std::string & word ){
                        auto it = std::remove_if( std::begin( word ),
                                                  std::end( word ),
                                                  []( char letter ){ 
                                                      return std::find( std::begin( VOWELS ), std::end( VOWELS ), letter ) != std::end( VOWELS ); 
                                                  });
                        word.erase( it, std::end( word ) );
                        return word;
                    }); 
    return words;
}