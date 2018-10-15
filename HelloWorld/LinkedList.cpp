//
//  LinkedList.cpp
//  HelloWorld
//
//  Created by Vikrant Basotra on 10/11/18.
//  Copyright © 2018 Vikrant Basotra. All rights reserved.
//

#include "LinkedList.hpp"

LinkedList::LinkedList() {
    cout<<"Constructor\n";
};

LinkedList::~LinkedList() {
}

void LinkedList::appendNode(int data){
    Node *ptr, *nodePtrTmp;
    nodePtrTmp = nodePtr;
    
    if (nodePtr == nullptr){
        ptr = new Node;
        ptr->prev = nullptr;
        ptr->data = data;
        ptr->next = nullptr;
        nodePtr = ptr;
    }
    else{
        while (nodePtrTmp->next != nullptr)
            nodePtrTmp = nodePtrTmp->next;
        
        ptr = new Node;
        nodePtrTmp->next = ptr;
        ptr->prev = nodePtrTmp;
        ptr->data = data;
        ptr->next = nullptr;
    }
    listLength++;
}

void LinkedList::addAtBeg(int data){
    Node *nodePtrTmp;
    nodePtrTmp = new Node;
    nodePtrTmp->prev = nullptr;
    nodePtrTmp->data = data;
    nodePtrTmp->next = nullptr;
    if (nullptr == nodePtr){
        nodePtr = nodePtrTmp;
    }
    else{
        nodePtrTmp->next = nodePtr;
        nodePtr->prev = nodePtrTmp;
        nodePtr = nodePtrTmp;
    }
    listLength++;
}

void LinkedList::addAfter(int afterData, int data){
    
    if (nullptr == nodePtr){
        LinkedList::addAtBeg(data);
    }
    else{
        Node *nodePtrTmp , *newNode;
        nodePtrTmp = nodePtr;
        while (afterData != nodePtrTmp->data){
            if (nullptr == nodePtrTmp->next)
                break;
            nodePtrTmp = nodePtrTmp->next;
        }

        
        if (nullptr == nodePtrTmp->next){
            LinkedList::appendNode(data);
        }
        else{
            newNode = new Node;
            newNode->data = data;
            
            newNode->next = nodePtrTmp->next;
            newNode->prev = nodePtrTmp;
            nodePtrTmp->next->prev = newNode;
            nodePtrTmp->next = newNode;
            listLength++;
        }
    }
}

void LinkedList::deleteNode(int data){
    
    if (nullptr == nodePtr){
        cout<< " Nothing to delete \n";
    }
    else{
        Node *nodePtrTmp;
        nodePtrTmp = nodePtr;
        while (data != nodePtrTmp->data){
            if (nullptr == nodePtrTmp->next)
                break;
            nodePtrTmp = nodePtrTmp->next;
        }
        
        if (data == nodePtrTmp->data){
            if (nullptr == nodePtrTmp->next){
                nodePtrTmp->prev->next = nullptr;
            }
            else if (nullptr == nodePtrTmp->prev){
                nodePtrTmp->next->prev = nullptr;
                nodePtr = nodePtrTmp->next;
            }
            else{
                nodePtrTmp->prev->next = nodePtrTmp->next;
                nodePtrTmp->next->prev = nodePtrTmp->prev;

            }
            delete nodePtrTmp;
            listLength--;
        }
        
    }
    
}
void LinkedList::displayList(){
    Node *nodePtrTmp = nodePtr;
    if (nullptr == nodePtr) {
        cout << "Empty List\n";
    }
    else{
        cout << "Linked List : \n";
        cout << nodePtrTmp->data;
        while (nodePtrTmp->next != nullptr){
            cout << ",";
            nodePtrTmp = nodePtrTmp->next;
            cout << nodePtrTmp->data;
        }
    }
    cout << endl;
}
void LinkedList::showLength(){
    cout << "list Length : " << listLength <<endl;
}
