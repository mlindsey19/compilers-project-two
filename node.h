//
// Created by mlind on 4/21/2019.
//

#ifndef PARSER_NODE_H
#define PARSER_NODE_H

#include "token.h"

#define NT_sz

typedef struct
{
    int depth;

    int isToken;
    int isEmpty;
    Token token;

    struct Node * child_0;
    struct Node * child_1;
    struct Node * child_2;
    struct Node * child_3;

    char nonTerm[ NT_sz ];

} Node;

#endif //PARSER_NODE_H
