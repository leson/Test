#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}LNode, *LinkList;

LinkList init( int len );
void insertEle( LinkList l, int n, int e );
void delNode( LinkList l, int n );
void updateNode( LinkList l, int n, int e );
void printLink( LinkList l );

int testList()

#endif // LIST_H_INCLUDED
