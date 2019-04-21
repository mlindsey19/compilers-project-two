//
// Created by mlind on 4/21/2019.
//

#ifndef PARSER_NODE_H
#define PARSER_NODE_H

#include "token.h"

#define NT_sz

typedef struct node
{
    int depth;

    int isToken;
    int isEmpty
    char nonTerm[ NT_sz ];
    Token token;

    Node * firstChild;
    Node * leftChild;
    Node * rightChild;
    Node * lastChild;

} Node;

#endif //PARSER_NODE_H
