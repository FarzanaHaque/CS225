/**
 * @file common_words.cpp
 * Implementation of the CommonWords class.
 *
 * @author Zach Widder
 * @date Fall 2014
 */

#include "common_words.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::feof;

string remove_punct(const string& str)
{
    string ret;
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(ret),
                        std::ptr_fun<int, int>(&std::ispunct));
    return ret;
}

CommonWords::CommonWords(const vector<string>& filenames)
{
    // initialize all member variables
    init_file_word_maps(filenames);
    init_common();
}

void CommonWords::init_file_word_maps(const vector<string>& filenames)
{
    // make the length of file_word_maps the same as the length of filenames
    file_word_maps.resize(filenames.size());

    // go through all files
    for (size_t i = 0; i < filenames.size(); i++) {
        // get the corresponding vector of words that represents the current
        // file
        vector<string> words = file_to_vector(filenames[i]);
        /* Your code goes here! */
//in a specific file, making the vector of strings, words is a temp variable to be placed into file_word_maps, hmmm need to look over mapping again

//    vector<map<string, unsigned int>> file_word_maps;

//go through this vector and map integer, 

    	for (size_t j = 0; j < words.size(); j++) {
	//need an iterator 
		string tstring=words[j]; //specific word
		map<string, unsigned int>::iterator lookup = file_word_maps[i].find(tstring);
//
    		if (lookup != file_word_maps[i].end()) {
        		lookup->second=lookup->second +1;// if in the list already increment by one
    		} else {
			file_word_maps[i][tstring]=1;
    		}
///
	}


    }
}

void CommonWords::init_common()
{
    /* Your code goes here! */
    /**
     * #common maps a word to the number of documents that word appears in
     */
//    std::map<std::string, unsigned int> common;
//go through file map check each string, if it's not in common add 1
/*    map<unsigned long, unsigned long>::iterator lookup = memo.find(n);
    if (lookup != memo.end()) {
        return lookup->second;
    } else {
        unsigned long result = memoized_fib(n - 1)+memoized_fib(n-2);
        memo[n] = result;
        return result;
    }
*/


//map<string, unsigned int>::iterator lookup = common.find();
	for(size_t i=0;i< file_words_maps.size();i++){
	//in a specific map, want to get every word	
	}




}

/**
 * @param n The number of times to word has to appear.
 * @return A vector of strings. The vector contains all words that appear
 * in each file >= n times.
 */
vector<string> CommonWords::get_common_words(unsigned int n) const
{
    vector<string> out;
    /* Your code goes here! */
    return out;
}

/**
 * Takes a filename and transforms it to a vector of all words in that file.
 * @param filename The name of the file that will fill the vector
 */
vector<string> CommonWords::file_to_vector(const string& filename) const
{
    ifstream words(filename);
    vector<string> out;

    if (words.is_open()) {
        std::istream_iterator<string> word_iter(words);
        while (!words.eof()) {
            out.push_back(remove_punct(*word_iter));
            ++word_iter;
        }
    }
    return out;
}
