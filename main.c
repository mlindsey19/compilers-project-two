#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <getopt.h>
#include "scanner.h"
#include "parser.h"

FILE * file;
void traverseTree( Node *  );

int main (int argc, char **argv){

    FILE * fp;
    char infile[32];
    char *ext = ".input1";

    if (argc == 1)
        fp = stdin;
    else {
        strcpy(infile, argv[1]);
        char *pos = strstr(infile, ext);
        if(pos == NULL)
            strcat(infile,ext);
        strcat(infile, "\0");
        fp = fopen(infile, "r");
    }
    file = fp;
    Node * root = createNode( toString(filename) );
    parser(root);
    traverseTree(root);
    fclose(fp);

    return 0;
}
static int level = -1 ;


static void traverseTokenList(LinkToken * link){
    printf("  %s ",link->token.instance);
    if( link->link != NULL )
        traverseTokenList(link->link);
}
void traverseTree( Node * node ){
    level++;
    int i;
    for ( i = 0; i < level; i++)
        printf("-- ");
    printf("< %s >", node->nonTerm);
    if (node->linkToken != NULL)
        traverseTokenList(node->linkToken);
    printf("\n");

    if(node->child_0 != NULL)
        traverseTree(node->child_0);
    if(node->child_1 != NULL)
        traverseTree(node->child_1);
    if(node->child_2 != NULL)
        traverseTree(node->child_2);
    if(node->child_3 != NULL)
        traverseTree(node->child_3);


    level--;
}