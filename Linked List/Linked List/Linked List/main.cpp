//
//  main.cpp
//  Linked List
//
//  Created by Emil Shirima on 9/30/15.
//  Copyright (c) 2015 Emil Shirima. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

int main(int argc, const char * argv[]) {
    
    LinkedList testList = *new LinkedList();
    
    // the list is empty at this point
    std::cout << "Extreme Test Cases" << "\n";
    testList.deleteFromFront();
    testList.deleteFromBack();
    
    std::cout << "\n\n";
    
    std::cout << "Initial Front Insertion Test Case" << "\n";
    testList.insertInfront(90);
    testList.printContents();
    
    std::cout << "Initiial Front Deletion Test Case" << "\n";
    testList.deleteFromFront();
    testList.printContents();
    
    std::cout << "\n\n";
    
    std::cout << "Initial Back Insertion Test Case" << "\n";
    testList.insertBack(80);
    testList.printContents();
    
    std::cout << "Initial Back Deletion Test Case" << "\n";
    testList.deleteFromBack();
    testList.printContents();
    
    std::cout << "Testing Front Insertion" << "\n";
    testList.insertInfront(69);
    testList.insertInfront(10);
    testList.insertInfront(12);
    testList.printContents();
    
    std::cout << "Testing Backward Insertion" << "\n";
    testList.insertBack(30);
    testList.insertBack(6);
    testList.insertBack(9);
    testList.printContents();
    
    std::cout << "Testing Front Deletion" << "\n";
    testList.deleteFromFront();
    testList.printContents();
    testList.deleteFromFront();
    testList.printContents();
    
    std::cout << "Testing Back Deletion" << "\n";
    testList.deleteFromBack();
    testList.deleteFromBack();
    testList.deleteFromBack();
    testList.printContents();
    
    return 0;
}
