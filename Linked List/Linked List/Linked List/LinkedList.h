//
//  LinkedList.h
//  Linked List
//
//  Created by Emil Shirima on 10/1/15.
//  Copyright (c) 2015 Emil Shirima. All rights reserved.
//

#ifndef __Linked_List__LinkedList__
#define __Linked_List__LinkedList__

#include <stdio.h>
#include <iostream>

class Node
{
public:
    
    Node();
    Node(int);
    
    int data;
    Node * next;
};

class LinkedList
{
public:
    
    LinkedList();
    LinkedList(const LinkedList&);
    ~LinkedList();
    LinkedList& operator=(LinkedList);
    
    int length(LinkedList);
    void swap(LinkedList&);
    void insertInfront(int);
    void insertBack(int);
    void deleteFromFront();
    void deleteFromBack();
    bool isEmpty();
    void printContents();
    
private:
    Node * head;
};

#endif /* defined(__Linked_List__LinkedList__) */
