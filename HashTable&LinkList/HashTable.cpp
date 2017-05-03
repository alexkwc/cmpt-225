#include <cctype>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include <vector>
#include "HashTable.h"
#include "LinkedList.h"


std::vector<Val> HashTable::keys() const
{
    std::vector<Val> output;
    for(auto i = (unsigned int)0 ; i < arrSize; ++i)
    {
        auto tmp = arr[i].get();
        output.insert(output.end(),tmp.begin(),tmp.end()) ;
    }
    return output;
}

std::uint32_t HashTable::hash(const Val& key)
{
    uint32_t seed = 37;
    std::uint32_t hsh = 0;
    for(auto i = (size_t)0;i<key.length();i++)
    {
        if(!(isalpha(key[i]))) throw std::invalid_argument("String with non alphabetic.");
        hsh = hsh*seed + uint32_t(std::tolower(key[i])-96);
    }
    return hsh;
}

std::size_t HashTable::compress(std::uint32_t hash) const
{
        //std::cout<<"hash ="<<hash<<" ,arrSize="<<arrSize<<std::endl;
        return hash % arrSize ;
}

bool HashTable::add(const Val& v)
{
    auto key = compress(hash(v));
    if(arr[key].empty()) numOfUsedKey++;
    if(arr[key].add(v))
    {
        numOfItem++;
        return true;
    }
    return false;
}

bool HashTable::remove(const Val& v)
{
    auto key = compress(hash(v));
    if(arr[key].remove(v))
    {
        if(arr[key].empty()) numOfUsedKey--;
        numOfItem--;
        return true;
    }

    return false;
}

bool HashTable::search(const Val& v)
{
    return arr[compress(hash(v))].search(v);
}

int HashTable::size() const
{
    return numOfItem;
}

int HashTable::capacity() const
{
    return arrSize;
}

HashTable::HashTable (int c)
{
    if(c <=0 ) throw std::invalid_argument("HashTable size < 1");
    arrSize = (uint32_t) c * (uint32_t) 2;
    while(!(prime(arrSize)))
    {
        arrSize++;
    }
    arr = std::make_unique<LinkedList[]>(arrSize);
}

HashTable::HashTable (const HashTable& ht)
:arrSize{ht.arrSize},
arr{std::make_unique<LinkedList[]>(ht.arrSize)},
numOfUsedKey{ht.numOfUsedKey},
numOfItem{ht.numOfItem}
{
    deep_copy(ht);
}

HashTable& HashTable::operator=(const HashTable& ht)
{
    arr =std::make_unique<LinkedList[]>(ht.arrSize);
    arrSize = ht.arrSize;
    deep_copy(ht);
    return *this;
}

void HashTable::deep_copy(const HashTable& ht)
{
    for(auto i = (size_t)0;i<arrSize; i++)
    {
        arr[i] = ht.arr[i];
    }
}

float HashTable::loadFactor() const
{
    return (float)numOfItem/arrSize;
}

HashTable HashTable::setunion(const HashTable& ht) const
{
    HashTable newTable {int(numOfItem + ht.numOfItem)};
    for(auto i = (size_t)0; i<arrSize; i++)
    {
        auto tmp = arr[i].get();
        for(auto v:tmp) newTable.add(v);
    }
    for(auto i = (size_t)0; i<ht.arrSize; i++)
    {
        auto tmp = ht.arr[i].get();
        for(auto v:tmp) newTable.add(v);
    }
    return newTable;
}

void HashTable::printTable(const std::string& label) const
{
    std::cout<<label<<std::endl;
    for(auto i = (size_t)0;i<arrSize; i++)
    {
        arr[i].printList();
    }
    return;
}

HashTable::HashTable ()
{}

bool HashTable::prime(uint32_t v) const
{
    auto i = (uint32_t)2;
    while(i<v)
    {
        if(v%i == 0) return false;
        i++;
    }
    return true;
}
