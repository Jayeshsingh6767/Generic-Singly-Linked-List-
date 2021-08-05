#ifndef sll__$__h
#define sll__$__h 123
#include<common.h>
#include<stdio.h>
typedef struct SLLIterator
{
struct SLLNode *node;
}SinglyLinkedListIterator;
struct SLLNode
{
void *ptr;
struct SLLNode *next;
};
typedef struct SLL
{
struct SLLNode *start;
struct SLLNode *end;
int size;
}SinglyLinkedList;

struct SLL * createSinglyLinkedList(boolean *success);
void destroySinglyLinkedList(struct SLL *list);
void insertIntoSinglyLinkedList(struct SLL *list,int pos,void *ptr,boolean *success);
void addToSinglyLinkedList(struct SLL *list , void *ptr,boolean *success);
void clearSinglyLinkedList(struct SLL *list);
void removeFromSinglyLinkedList(struct SLL *list,int pos,boolean *success);
int getSizeOfSinglyLinkedList(struct SLL *list);
void * getFromSinglyLinkedList(struct SLL *list,int pos,int *success);
struct SLLIterator getSinglyLinkedListIterator(struct SLL *list,int *success);
boolean hasMoreElementInSinglyLinkedList(struct SLLIterator *iterator);
void * nextElementFromSinglyLinkedList(struct SLLIterator *iterator);
#endif