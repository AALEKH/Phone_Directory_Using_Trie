#ifndef utilities 
#define utilities

#include <vector>
#include <string>
#include <iostream>     // cout
#include <algorithm> 

using namespace std;
/**
 * @brief Here the elements of the given vector denotes the totoal permissible letter's possible for user input,
 * in order to add more elements just insert more elements
 */
vector<int> p_elements { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', ' ', '_'};

/**
 * @brief checkPermissibleEle is used to check if the user input for name has valid characters, as denoted on p_elements
 * vector in utilities.h
 *
*/
bool checkPermissibleEle(string str){
    vector<int>::iterator it;
    for(int i = 0; i < str.size(); i++){
        it = find (p_elements.begin(), p_elements.end(), (int)str[i]);
        if (it == p_elements.end()) return false;
    }
    return true;
}

// Just to seperate sentense to white spaces

unsigned int split(const string &txt, vector<string> &strs, char ch)
{
    unsigned long pos = txt.find( ch );
    unsigned int initialPos = 0;
    strs.clear();

    // Decompose statement
    while( pos != string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos + 1 ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back( txt.substr( initialPos, min( pos, static_cast<unsigned long>(txt.size()) ) - initialPos + 1 ) );

    return strs.size();
}

#endif

// map<char, bool> p_elements {
//     make_pair ('A', true),
//     make_pair ('B', true),
//     make_pair ('C', true),
//     make_pair ('D', true),
//     make_pair ('E', true),
//     make_pair ('F', true),
//     make_pair ('G', true),
//     make_pair ('H', true),
//     make_pair ('I', true),
//     make_pair ('J', true),
//     make_pair ('K', true),
//     make_pair ('L', true),
//     make_pair ('M', true),
//     make_pair ('N', true),
//     make_pair ('O', true),
//     make_pair ('P', true),
//     make_pair ('Q', true),
//     make_pair ('R', true),
//     make_pair ('S', true),
//     make_pair ('T', true),
//     make_pair ('U', true),
//     make_pair ('V', true),
//     make_pair ('W', true),
//     make_pair ('X', true),
//     make_pair ('Y', true),
//     make_pair ('Z', true),
//     make_pair ('a', true),
//     make_pair ('b', true),
//     make_pair ('c', true),
//     make_pair ('d', true),
//     make_pair ('e', true),
//     make_pair ('f', true),
//     make_pair ('g', true),
//     make_pair ('h', true),
//     make_pair ('i', true),
//     make_pair ('j', true),
//     make_pair ('k', true),
//     make_pair ('l', true),
//     make_pair ('m', true),
//     make_pair ('n', true),
//     make_pair ('o', true),
//     make_pair ('p', true),
//     make_pair ('q', true),
//     make_pair ('r', true),
//     make_pair ('s', true),
//     make_pair ('t', true),
//     make_pair ('u', true),
//     make_pair ('v', true),
//     make_pair ('w', true),
//     make_pair ('x', true),
//     make_pair ('y', true),
//     make_pair ('z', true),
//     make_pair (' ', true),
//     make_pair ('_', true),
//   };