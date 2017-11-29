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
    //init_common();
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

filenum=filenames.size();
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
//doing init common 		
		map<string, unsigned int>::iterator lookup2 = common.find(tstring);
    		if (lookup2 != common.end()) {//already in common, now need to check it's the first instance in the file
			if(file_word_maps[i][tstring]==1){        		
				lookup2->second=lookup2->second +1;// if in common already increment by one
			}
    		} else {
			common[tstring]=1;
			mywords.push_back(tstring);
    		}
//hmm i think i won't use common at all bc yolo
	
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




/*	for(size_t i=0;i< file_word_maps.size();i++){
	//in a specific map, want to get every word
	vector<string> words=file_to_vector(filenames[i]); //all the words in the file, including repeats
	
	}

*/


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
//go through each word in common, check to see if it's in all 
    for(size_t i=0;i<mywords.size();i++){
	string mstring=mywords[i];
	bool insert = true;
	auto lookup2=common.find(mstring);
	//map<string, unsigned int>::iterator lookup2=common.find(mstring);
	if(lookup2->second!= filenum) insert=false;
	while(insert){
		for(size_t j=0;j<file_word_maps.size();j++){
		auto lookup=file_word_maps[j].find(mstring);
		//map<string, unsigned int>::iterator lookup=file_word_maps[j].find(mstring);
		//is this necessary, only doing common words... if(lookup==file_word_maps[j].end()) insert=false; //means it's not in the file
		if(lookup->second<n) insert=false; //why does this do nothing????
		}
	//finished for loop and insert still true
	if(insert)out.push_back(mstring);
	insert=false;
	}
    }



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
