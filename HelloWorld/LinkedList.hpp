//
//  LinkedList.hpp
//  HelloWorld
//
//  Created by Vikrant Basotra on 10/11/18.
//  Copyright © 2018 Vikrant Basotra. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
class LinkedList {
    struct Node {
        Node *prev{nullptr};
        int data {0};
        Node *next {nullptr};
    } *nodePtr = nullptr;
    
    int listLength {0};
public:
    LinkedList();
    ~LinkedList();
    void appendNode(int data);
    void addAtBeg(int data);
    void addAfter(int afterData, int data);
    void deleteNode(int data);
    void displayList();
    void showLength();
};

#endif /* LinkedList_hpp */
