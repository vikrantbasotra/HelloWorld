//
//  main.cpp
//  HelloWorld
//
//  Created by Vikrant Basotra on 10/10/18.
//  Copyright © 2018 Vikrant Basotra. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "Inside Main\n";
   // LinkedList *head = nullptr, *current = nullptr;
    LinkedList linkedList;
    linkedList.showLength();
    linkedList.addAfter(12,99);
    linkedList.appendNode(33);
    linkedList.appendNode(44);
    linkedList.appendNode(55);
    linkedList.appendNode(66);
    linkedList.addAtBeg(11);
    linkedList.addAtBeg(22);
    linkedList.addAfter(124,999);
    linkedList.addAfter(44,99);
    linkedList.displayList();
    linkedList.showLength();
    linkedList.deleteNode(999);
    linkedList.displayList();
    linkedList.showLength();
}
