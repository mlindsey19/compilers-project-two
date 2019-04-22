//
// Created by mlind on 4/21/2019.
//

#include "parser.h"
#include "node.h"
#include "scanner.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void program();
static void vars();
static void block();
static void stats();
static void stat();
static void mStat();
static void in();
static void out();
static void iff();
static void assign();
static void loop();
static void expr();
static void a();
static void k();
static void n();
static void m();
static void r();
static void ro();
static void re();



static int isInstance( char *, char * );
Token tk;
static void parseError( char * );

void parser(){
    tk = scanner();
    program();
}


static void program(){
    vars();
    block();
    if ( tk.id == EOFtk )
        printf("Program ok\n");
    else
        parseError(toString(EOFtk));
}
static void vars(){
    if ( isInstance( tk.instance, toString(INT_tk) ) ) {
        tk = scanner();
        if ( tk.id == IDENTtk)
            tk = scanner();
        else
            parseError(toString( IDENTtk ) );
        if ( tk.id == INTtk ) {
            tk = scanner();
            vars();
        }else
            parseError( toString( INTtk ) );
    } else
        return;

}
static void block(){
    if ( isInstance( tk.instance, toString( Begin_tk ) ) )
        tk = scanner();
    else
        parseError( toString( Begin_tk ) );

    vars();
    stats();

    if ( isInstance( tk.instance, toString( End_tk ) ) )
        tk = scanner();
    else
        parseError( toString( End_tk ) );
    return;
}
static void stats(){
    stat();
    if (isInstance(tk.instance, toString( COLON_tk ) ) )
        tk = scanner();
    else
        parseError( toString( COLON_tk ) );
    mStat();
}
static void stat() {
    if ( isInstance( tk.instance, toString( Read_tk ) ) ) {
        tk = scanner();
        in();
    } else if ( isInstance( tk.instance, toString( Output_tk ) ) ) {
        tk = scanner();
        out();
    } else if ( isInstance( tk.instance, toString( IFF_tk ) ) )  {
        tk = scanner();
        iff();
    } else if ( isInstance( tk.instance, toString( Loop_tk ) ) ) {
        tk = scanner();
        loop();
    } else if ( tk.id == IDENTtk ){
        tk = scanner();
        assign();
    } else if( tk.instance, toString( Begin_tk ) ){
        tk = scanner();
        block();
    }else
        parseError( toString( Statment ) );
    return;
}

static void mStat(){
    if (isInstance( tk.instance, toString( End_tk ) ) ){
        return;
    } else
        stat();
}
static void in(){
    if (isInstance( tk.instance, toString( irginvrisyrt ) ) ){

    }
}
static void out(){
    if (isInstance( tk.instance, toString( OPEN_BRACKET_tk ) ) ){
        tk = scanner();
    }else
        parseError(toString( OPEN_BRACKET_tk) );
    expr();
    if (isInstance( tk.instance, toString( CLOSE_BRACKET_tk ) ) ){
        tk = scanner();
    }else
        parseError(toString( CLOSE_BRACKET_tk) );
}
static void iff(){
    if (isInstance( tk.instance, toString( irginvrisyrt ))){

    }
}
static void assign(){
    if (isInstance( tk.instance, toString( irginvrisyrt ))){

    }
}
static void loop(){
    if (isInstance( tk.instance, toString( irginvrisyrt ))){

    }
}
static void expr(){
    a();
    k();
}
static void k(){
    if (isInstance( tk.instance, toString( PLUS_tk ))){
        tk =scanner();
        expr();
    } else if (isInstance( tk.instance, toString( MINUS_tk) ) ) {
        tk = scanner();
        expr();
    }
}
static void a(){
    n();
    if (isInstance( tk.instance, toString( ASTERISK_tk ))){
        tk = scanner();
        a();
    }
}
static void n(){
    m();
    if (isInstance( tk.instance, toString( SLASH_tk ))){
        n();
    }
}
static void m(){
    if (isInstance( tk.instance, toString( MINUS_tk ))){
        tk=scanner();
        m();
    } else
        r();
}
static void r(){
    if ( isInstance( tk.instance, toString( OPEN_BRACKET_tk ))){
        expr();
        if ( isInstance( tk.instance, toString( CLOSE_BRACKET_tk ))){
        } else
            parseError( toString( OPEN_BRACKET_tk) );
    } else if( tk.id == IDENTtk ){
        tk = scanner();
        return;
    } else if( tk.id == INTtk ) {
        tk = scanner();
        return;
    }else
        parseError( "expr, identifier or integer" );
}
static void ro(){
    if (isInstance( tk.instance, toString( irginvrisyrt ))){

    }
}
static void re(){
    if (isInstance( tk.instance, toString( irginvrisyrt ))){

    }
}




Node * createNode( ){
    Node * newNode = ( Node * ) malloc( sizeof( Node ) );
    newNode->depth = 0;

    newNode->child_0 = NULL;
    newNode->child_1 = NULL;
    newNode->child_2 = NULL;
    newNode->child_3 = NULL;
}

static int isInstance(char * a, char *b ){
    if ( strcmp( a, b ) == 0 )
        return 1;
    return 0;
}
static void parseError( char * expected){
    printf("ERROR line: %i -> %s - Expected %s\n", tk.id,  expected);
}
