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
    else
    {
        std::cout << "The List is empty :(" << "\n";
    }
}

void LinkedList::deleteFromBack()
{
    if (!isEmpty())
    {
        // a single element in the Linked List
        if (head ->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node * temp = head->next;
            Node * previous = head;
            
            while (temp->next != nullptr)
            {
                previous = temp;
                temp = temp->next;
            }
            
            delete temp;
            previous->next = nullptr;
            
        }
    }
    else
    {
        std::cout << "The List is empty :(";
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

void LinkedList::printContents()
{
    if(!isEmpty())
    {
        Node * temp = this->head;
        
        while (temp)
        {
            std::cout << temp->data << "\n";
            temp = temp->next;
        }
        
        std::cout << "\n";
    }
    else
    {
        std::cout << "Cannot print out an empty list :(";
    }
}
