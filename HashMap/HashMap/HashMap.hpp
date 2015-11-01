//
//  HashMap.hpp
//  HashMap
//
//  Created by Emil Shirima on 10/31/15.
//  Copyright © 2015 Emil Shirima. All rights reserved.
//

#ifndef HashMap_hpp
#define HashMap_hpp

#include <iostream>

class Item
{
public:
    
    Item();
    Item(std::string);
    std::string data;
    Item * next;
};

class HashMap
{
public:
    
    HashMap();
    int hash(std::string);
    bool isIndexEmpty(int);
    bool isBucketEmpty(int);
    void addItem(std::string);
    int numberOfElementsInBucket(int);
    void printBucketsAtIndex(int);
    void printEntireMap();
    void printFilledAreasOfTheMap();
    void search(std::string);
    void remove(std::string);
    
private:
    
    static const int size = 100;
    Item * hashTable[size];
};

#endif /* HashMap_hpp */
