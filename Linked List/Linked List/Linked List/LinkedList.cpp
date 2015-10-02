//
//  LinkedList.cpp
//  Linked List
//
//  Created by Emil Shirima on 10/1/15.
//  Copyright (c) 2015 Emil Shirima. All rights reserved.
//

#include "LinkedList.h"
Node::Node()
{
    data = 0;
    next = nullptr;
}

Node::Node(int info)
{
    data = info;
    next = nullptr;
}

LinkedList::LinkedList()
{
    head = nullptr;
}
//TODO: Confirm this implementation. I really doubt it
LinkedList::LinkedList(const LinkedList& actual)
{
    Node * temporaryHead, temporaryNode;
    
    temporaryHead = actual.head;
    
    while (temporaryHead != nullptr) {
        temporaryNode = *new Node(temporaryHead->data);
        temporaryHead = temporaryHead->next;
    }
}

LinkedList::~LinkedList()
{
    while (head != nullptr)
    {
        Node * temp = head;
        head = head->next;
        delete temp;
    }
}

LinkedList& LinkedList::operator=(LinkedList rhs)
{
    swap(rhs);
    return *this;
}

int LinkedList::length(LinkedList actual)
{
    int count = 0;
    Node * temp = actual.head;
    
    while (temp != nullptr)
    {
        ++count;
        temp = temp->next;
    }
    
    return count;
}

void LinkedList::swap(LinkedList & rhs)
{
    Node * temp = rhs.head;
    rhs.head = head;
    head = temp;
}

void LinkedList::insertInfront(int value)
{
    if (isEmpty())
    {
        head = new Node(value);
    }
    else
    {
        Node * temp = new Node(value);
        temp->next = head;
        head = temp;
    }
}

void LinkedList::insertBack(int value)
{
    if (isEmpty())
    {
        head = new Node(value);
    }
    else
    {
        Node * temp = head;
        
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        
        temp->next = new Node(value);
    }
}

void LinkedList::deleteFromFront()
{
    if (!isEmpty())
    {
        Node * temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::deleteFromBack()
{
    Node * temp = head;
    
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    
}

bool LinkedList::isEmpty()
{
    if (head == nullptr)
    {
        return true;
    }
    
    return false;
}
