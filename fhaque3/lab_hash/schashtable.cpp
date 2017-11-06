/**

 * @file schashtable.cpp
 * Implementation of the SCHashTable class.
 *
 * @author Chase Geigle
 * @date Spring 2011
 * @date Summer 2012
 */

#include "schashtable.h"
#include <iostream>
using hashes::hash;
using std::list;
using std::pair;
template <class K, class V>
SCHashTable<K, V>::SCHashTable(size_t tsize)
{
    if (tsize <= 0)
        tsize = 17;
    size = findPrime(tsize);
    table = new list<pair<K, V>>[size];
    elems = 0;
}

template <class K, class V>
SCHashTable<K, V>::~SCHashTable()
{
    delete[] table;
}

template <class K, class V>
SCHashTable<K, V> const& SCHashTable<K, V>::
operator=(SCHashTable<K, V> const& rhs)
{
    if (this != &rhs) {
        delete[] table;
        table = new list<pair<K, V>>[rhs.size];
        for (size_t i = 0; i < rhs.size; i++)
            table[i] = rhs.table[i];
        size = rhs.size;
        elems = rhs.elems;
    }
    return *this;
}

template <class K, class V>
SCHashTable<K, V>::SCHashTable(SCHashTable<K, V> const& other)
{
    table = new list<pair<K, V>>[other.size];
    for (size_t i = 0; i < other.size; i++)
        table[i] = other.table[i];
    size = other.size;
    elems = other.elems;
}

template <class K, class V>
void SCHashTable<K, V>::insert(K const& key, V const& value)
{
    ++elems;
    if (shouldResize())
        resizeTable();
    pair<K, V> p(key, value);
    size_t idx = hash(key, size);
    table[idx].push_front(p);
}

template <class K, class V>
void SCHashTable<K, V>::remove(K const& key)
{
    typename list<pair<K, V>>::iterator it;

	size_t index;
	index = hash(key, size);
	for(it = table[index].begin(); it != table[index].end(); it++)	{
		if(it->first == key)	{
			table[index].erase(it);
			elems = elems - 1;
			break;
		}
	}

    /**
     * @todo Implement this function.
     *
     * Please read the note in the lab spec about list iterators and the
     * erase() function on std::list!
     */

    //(void) key; // prevent warnings... When you implement this function, remove this line.
}

template <class K, class V>
V SCHashTable<K, V>::find(K const& key) const
{
    size_t idx = hash(key, size);
    typename list<pair<K, V>>::iterator it;
    for (it = table[idx].begin(); it != table[idx].end(); it++) {
        if (it->first == key)
            return it->second;
    }
    return V();
}

template <class K, class V>
V& SCHashTable<K, V>::operator[](K const& key)
{
    size_t idx = hash(key, size);
    typename list<pair<K, V>>::iterator it;
    for (it = table[idx].begin(); it != table[idx].end(); it++) {
        if (it->first == key)
            return it->second;
    }

    ++elems;
    if (shouldResize())
        resizeTable();

    idx = hash(key, size);
    pair<K, V> p(key, V());
    table[idx].push_front(p);
    return table[idx].front().second;
}

template <class K, class V>
bool SCHashTable<K, V>::keyExists(K const& key) const
{
    size_t idx = hash(key, size);
    typename list<pair<K, V>>::iterator it;
    for (it = table[idx].begin(); it != table[idx].end(); it++) {
        if (it->first == key)
            return true;
    }
    return false;
}

template <class K, class V>
void SCHashTable<K, V>::clear()
{
    delete[] table;
    table = new list<pair<K, V>>[17];
    size = 17;
    elems = 0;
}

template <class K, class V>
void SCHashTable<K, V>::resizeTable()
{
    typename list<pair<K, V>>::iterator it;
	typename list<pair<K, V>>::iterator myIt;
	size_t newSize;
	size_t originalSize;
	size_t index;
	//newSize = findPrime(2*hash(key, size));
	//newSize = findPrime(2*this->tableSize());
	newSize = findPrime(2*size);
	
	list<pair<K, V>> *temp = new list<pair<K, V>>[newSize];
	//pair<K,V> *pair;
	for(index = 0; index < size; index++)	{
		//temp[index] = NULL;
		temp[index].resize(table[index].size());
		myIt = temp[index].begin();
		for(it = table[index].begin(); it != table[index].end(); it++)	{
			size_t count = hash(it->first, newSize);
			pair<K, V> pair(it->first, it->second);
			temp[count].push_back(pair);
			//myIt->first = it->first;
			//myIt->second = it->second;
                        //myIt++;
		}
		/*for(it = table[index].begin(); it != table[index].end(); it++)	{
			std::cout << "table: key, value: " << it->first << it->second << std::endl;
			 std::cout << "new table: key, value: " << myIt->first << myIt->second << std::endl;
		}*/
		//temp[index] = table[index];
	}

	//myIt = temp[index].begin();
	/*for(index = 0; index < size; index++)	{
		myIt = temp[index].begin();
		for(it = table[index].begin(); it != table[index].end(); it++)	{
			//temp[index] = table[index];
			//temp[index].key = it->first;
			//temp[index].second = it->second;
			myIt->first = it->first;
			myIt->second = it->second;
			myIt++;
		}
	}*/
	

	//table->resize(newSize);
	/*originalSize = this->tableSize();
	for(index = 0; index < originalSize; index++)	{
		//for(it = newTable[index].begin(); it != newTable[index].end(); it++)	{
			newTable[index] = table[index];
			//newTable->insert(it->first, it->second);
			//insert(it->first, it->second);
		//}
	}*/
	//delete newTable;

	delete[] table;
	table = temp;
	size = newSize;
	//table = newTable;

    // don't delete elements since we just moved their pointers around
    //     table = temp;
    //         size = newSize;

    /**
     * @todo Implement this function.
     *
     * Please read the note in the spec about list iterators!
     * The size of the table should be the closest prime to size * 2.
     *
     * @hint Use findPrime()!
     */
}
