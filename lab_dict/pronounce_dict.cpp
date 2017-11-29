/**
 * @file pronounce_dict.cpp
 * Implementation of the PronounceDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "pronounce_dict.h"

#include <iterator>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>

using std::string;
using std::map;
using std::vector;
using std::ifstream;
using std::istream;
using std::istream_iterator;
using std::stringstream;

/**
 * Constructs a PronounceDict from a CMU pronunciation dictionary
 * file. See http://www.speech.cs.cmu.edu/cgi-bin/cmudict .
 * @param pronun_dict_filename Filename of the CMU pronunciation
 * dictionary.
 */
PronounceDict::PronounceDict(const string& pronun_dict_filename)
{
    ifstream pronun_dict_file(pronun_dict_filename);
    string line;
    if (pronun_dict_file.is_open()) {
        while (getline(pronun_dict_file, line)) {
            /* Used to break the line by whitespace. The CMU Dict does this for
             * separating words from their pronunciations. */
            stringstream line_ss(line);
            istream_iterator<string> line_begin(line_ss);
            istream_iterator<string> line_end;
            if (line[0] != '#' && *line_begin != ";;;") {
                /* Associate the word with the rest of the line
                 * (its pronunciation). */
                istream_iterator<string> temp_itr = line_begin;
                dict[*temp_itr] = vector<string>(++line_begin, line_end);
            }
        }
    }
    /* If it's not open then... well... just don't do anything for the sake
     * of simplicity. */
}

/**
 * Constructs a PronounceDict from a CMU std::map mapping the word
 * to a vector of strings which represent the pronunciation.
 * @param pronun_dict Maps a string word to a vector of strings
 * representing its pronunciation.
 */
PronounceDict::PronounceDict(const map<string, vector<string>>& pronun_dict)
    : dict(pronun_dict)
{
    /* Nothing to see here. */
}

/**
 * Uses the dictionary to determine if the two words are homophones.
 * @param word1 First word to be tested.
 * @param word2 Second word to be tested.
 * @return true if the two words are homophones, false otherwise (or
 * one or both words weren't in the dictionary).
 * Note: The word keys in the dictionary are stored in uppercase.
 */
bool PronounceDict::homophones(const string& word1, const string& word2) const
{
    /* Your code goes here! */
	string str1Cpy;
	string str2Cpy;
	str1Cpy = word1;
	std::transform(str1Cpy.begin(), str1Cpy.end(), str1Cpy.begin(), toupper);
	str2Cpy = word2;
	std::transform(str2Cpy.begin(), str2Cpy.end(), str2Cpy.begin(), toupper);
	if(dict.find(str1Cpy) != dict.end() && dict.find(str2Cpy) != dict.end())	{
		if(dict.find(str1Cpy)->second == dict.find(str2Cpy)->second)	{
			return true;
		}
	}
	//auto iter = dict.find(str2Cpy)->second.begin();
//	for(auto it = dict.find(str1Cpy)->second.begin(); it != dict.find(str1Cpy)->second.end(); it++)	{
		//for(auto iter = dict.find(str2Cpy)->second.begin(); iter != dict.find(str2Cpy)->second.end(); iter++)	{
			//if(*it == *iter)	{
			//	return true;
			//}
		//}
		//iter++;
//	}
	return false;	
    //return true;
}
