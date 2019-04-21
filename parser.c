//
// Created by mlind on 4/21/2019.
//

#include "parser.h"
#include "node.h"

void program(){

}

Node * createNode( ){
    Node * newNode = ( Node * ) malloc( sizeof( Node ) );
    newNode->depth = 0;

    newNode->firstChild = NULL;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->lastChild = NULL;
}