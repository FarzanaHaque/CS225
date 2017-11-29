/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"
#include <iostream>
using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of (string, string, string) tuples
 * Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<std::tuple<std::string, std::string, std::string>> cartalk_puzzle(PronounceDict d,
                                    const string& word_list_fname)
{
    vector<std::tuple<std::string, std::string, std::string>> ret;

    /* Your code goes here! */
	ifstream filePtr(word_list_fname);
	string currWord;
	//filePtr.open(word_list_fname);
	vector<string> temp;
	if(filePtr.is_open())	{
	while(getline(filePtr, currWord))	{
		//ret.push_back(currWord);
		temp.push_back(currWord);
	}	
	}
	vector<string>::iterator it;
	vector<string>::iterator secondWord;
	vector<string>::iterator thirdWord;
	for(it = temp.begin(); it != temp.end(); it++)	{
		for(secondWord = it; secondWord != temp.end(); secondWord++)	{
			if(*it != *secondWord)	{
				if(d.homophones(*it, *secondWord))	{
					for(thirdWord = secondWord; thirdWord != temp.end(); thirdWord++)   {
						if(*secondWord != *thirdWord)	{
							if(d.homophones(*secondWord, *thirdWord))	{
								ret.push_back(std::make_tuple(*it, *secondWord, *thirdWord));
							}
						}
                        		}
				}
			}
			/*for(thirdWord = temp.begin(); thirdWord != temp.end(); thirdWord++)	{

			}*/
		}
	}
	if(ret.size() == 0)	{
		return vector<std::tuple<std::string, std::string, std::string>>();
	}
    return ret;
}
