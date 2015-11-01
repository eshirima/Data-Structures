//
//  HashMap.cpp
//  HashMap
//
//  Created by Emil Shirima on 10/31/15.
//  Copyright © 2015 Emil Shirima. All rights reserved.
//

#include "HashMap.hpp"
Item::Item()
{
    data = "\0";
    next = nullptr;
}

Item::Item(std::string info)
{
    data = info;
    next = nullptr;
}

HashMap::HashMap()
{
    for (int i = 0; i < size; ++i)
    {
        hashTable[i] = new Item;
        hashTable[i]->data = "\0";
        hashTable[i]->next = nullptr;
    }
}

int HashMap::hash(std::string word)
{
    int index = 0;
    
    for (int i = 0; i < word.length(); ++i)
    {
        index += (int)word[i];
    }
    
    return index % size;
}

bool HashMap::isIndexEmpty(int index)
{
    if (hashTable[index]->data == "\0")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool HashMap::isBucketEmpty(int index)
{
    if (hashTable[index]->next == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void HashMap::addItem(std::string element)
{
    int index = hash(element);
    
    if (isIndexEmpty(index)) // this means the spot in the array is empty
    {
        hashTable[index]->data = element;
    }
    else
    {
        // points to the first element in that index
        Item * iteratorPointer = hashTable[index];
        while (iteratorPointer->next != nullptr)
        {
            iteratorPointer = iteratorPointer->next;
        }
        
        iteratorPointer->next = new Item(element);
        
    }
}

int HashMap::numberOfElementsInBucket(int location)
{
    
    if (isIndexEmpty(location))
    {
        return 0; // there's no element at this location
    }
    else
    {
        int count = 1; // we have one element at this point
        if (hashTable[location]->next == nullptr) // we don't have a linkedlist to traverse in
        {
            return count;
        }
        
        else
        {
            Item * iterator = hashTable[location];
            while (iterator->next != nullptr)
            {
                ++count;
                iterator = iterator->next;
            }
        }
        
        return count;
    }
}
void HashMap::printBucketsAtIndex(int location)
{
    Item * iteratorPointer = hashTable[location]->next;
    while (iteratorPointer != nullptr)
    {
        std::cout << iteratorPointer->data << "\n";
        iteratorPointer = iteratorPointer->next;
    }
}

void HashMap::printEntireMap()
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "\n";
        std::cout << "+++++++++++++++ SRT +++++++++++++++" << "\n";
        std::cout << "At index " << i << "\n";
        std::cout << "Total number of elements " << numberOfElementsInBucket(i) << "\n";
        std::cout << hashTable[i]->data << "\n\n";
        if (isBucketEmpty(i)) // if bucket is empty then just go on
        {
            continue;
        }
        else
        {
            std::cout << "Bucket Contents" << "\n";
            printBucketsAtIndex(i);
            std::cout << "+++++++++++++++ END +++++++++++++++" << "\n";
        }
    }
}

void HashMap::printFilledAreasOfTheMap()
{
    for (int i = 0; i < size; ++i)
    {
        if (hashTable[i]->data == "\0")
        {
            // TODO: Fix the issue when the flag is DELETED
            continue;
        }
        else
        {
            std::cout << "\n";
            std::cout << "+++++++++++++++ SRT +++++++++++++++" << "\n";
            std::cout << "At index " << i << "\n";
            std::cout << "Total number of elements " << numberOfElementsInBucket(i) << "\n";
            std::cout << hashTable[i]->data << "\n";
            if (isBucketEmpty(i))
            {
                std::cout << "+++++++++++++++ END +++++++++++++++" << "\n";
                continue;
            }
            else
            {
                std::cout << "\n";
                std::cout << "Bucket Contents" << "\n";
                printBucketsAtIndex(i);
                std::cout << "+++++++++++++++ END +++++++++++++++" << "\n";
            }
        }
    }
}

void HashMap::search(std::string word)
{
    int index = hash(word);
    
    if (hashTable[index]->data == word)
    {
        std::cout << word << " found in constant time at index " << index << "\n";
    }
    else
    {
        Item * itemIterator = hashTable[index];
        if (itemIterator->next == nullptr)
        {
            std::cout << word << " was not found \n";
        }
        else
        {
            while (itemIterator != nullptr)
            {
                if (itemIterator->data == word)
                {
                    std::cout << word << " found in linked list \n";
                }
                
                itemIterator = itemIterator->next;
            }
        }
    }
    
}

void HashMap::remove(std::string word)
{
    int index = hash(word);
    
    if (hashTable[index]->data == "\0") // this means it is empty
    {
        std::cout << word <<" does not exist \n";
    }
    else if(hashTable[index]->data == word && hashTable[index]->next == nullptr) // element found and no buckets
    {
        hashTable[index]->data = "\0";
        std::cout << word << " was removed from the map \n";
    }
    
    else if(hashTable[index]->data == word) // element found at the first but buckets present
    {
        Item * currentItem = hashTable[index];
        hashTable[index] = hashTable[index]->next;
        delete currentItem;
        std::cout << word << " was removed from the map \n";
    }
    else // the item is possibly in the buckets
    {
        
        Item * previousItem = hashTable[index];
        Item * currentItem = previousItem->next;
        
        while (currentItem != nullptr)
        {
            if (currentItem->data == word)
            {
                previousItem->next = currentItem->next;
                delete currentItem;
                std::cout << word << " was removed from the bucket at index " << index << "\n";
                break;
            }
            else
            {
                currentItem = currentItem->next;
                previousItem = previousItem->next;
            }
        }
        
        if (currentItem == nullptr)
        {
            std::cout << word << " does not exist \n";
        }
    }
}