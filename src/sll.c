#include<sll.h>
#include<common.h>
#include<stdlib.h>

struct SLL * createSinglyLinkedList(boolean *success)
{
struct SLL *sll;
sll=(struct SLL *)malloc(sizeof(struct SLL));
if(sll==NULL)
{
if(success!=NULL) *success=false;
}
else
{
if(success!=NULL) *success=true;
sll->start=NULL;
sll->end=NULL;
sll->size=0;
return sll;
}
}

void destroySinglyLinkedList(struct SLL *list)
{
if(list==NULL) return;
clearSinglyLinkedList(list); 
free(list);
}

void insertIntoSinglyLinkedList(struct SLL *list,int pos,void *ptr,boolean *success)
{
struct SLLNode *t,*p1,*p2;
int x;
if(success) *success=false;
if(list==NULL) return;
if(pos<0 || pos>list->size)return;
if(pos==list->size)
{
addToSinglyLinkedList(list,ptr,success);
return;
}
p1=list->start;
x=0;
while(x<pos)
{
p2=p1;
p1=p1->next;
x++;
}
t=(struct SLLNode*)malloc(sizeof(struct SLLNode));
if(t=NULL) return;
t->ptr=ptr;
t->next=NULL;
if(p1==list->start)
{
t->next=list->start;
list->start=t;
}
else
{
t->next=p1;
p2->next=t;
}
list->size++;
if(success) *success=true;
}

void addToSinglyLinkedList(struct SLL *list , void *ptr,boolean *success)
{
struct SLLNode *t;
if(success) *success=false;
if(list==NULL) return;
t=(struct SLLNode *)malloc(sizeof(struct SLLNode));
if(t==NULL) return;
t->ptr=ptr;
t->next=NULL;
if(list->start==NULL)
{
list->start=t;
list->end=t;
}
else
{
list->end->next=t;
list->end=t;
}
if(success) *success=true;
list->size++;
}

void clearSinglyLinkedList(struct SLL *list)
{
struct SLLNode *t;
if(list==NULL) return;
while(list->start!=NULL)
{
t=list->start;
list->start=list->start->next;
free(t);
}
list->end=NULL;
list->size=0;
}

void removeFromSinglyLinkedList(struct SLL *list,int pos,boolean *success)
{
struct SLLNode *p1,*p2;
int x;
if(success) *success=false;
if(list==NULL) return;
if(pos<0||pos>=list->size)return;
p1=list->start;
x=0;
while(x<pos)
{
p2=p1;
p1=p1->next;
x++;
}
if(success) *success=true;
list->size--;
if(p1==list->start && p1==list->end) //only one node
{
list->start=NULL;
list->end=NULL;
free(p1);
return;
}
if(p1==list->start) // many but first
{
list->start=list->start->next;
free(p1);
return;
}
if(p1==list->end) // many but last
{
p2->next=NULL;
list->end=p2;
free(p1);
return;
}
p2->next=p1->next;
free(p1);
}

int getSizeOfSinglyLinkedList(struct SLL *list)
{
if (list==NULL) return 0;
return list->size;
}

void * getFromSinglyLinkedList(struct SLL *list,int pos,int *success)
{
struct SLLNode *t;
int x;
if(success) *success=false;
if(list==NULL) return NULL;
if(pos<0 || pos>=list->size) return NULL;
t=list->start;
x=0;
while(x<pos)
{
t=t->next;
x++;
}
if(success) *success=true;
return t->ptr;
}


struct SLLIterator getSinglyLinkedListIterator(struct SLL *list,int *success)
{
if(list==NULL)
{
if(success) success=false;
}
else
{
SinglyLinkedListIterator g;
g.node=list->start;
if(success) *success=true;
return g;
}
}
boolean hasMoreElementInSinglyLinkedList(struct SLLIterator *iterator)
{
if(iterator!=NULL && iterator->node!=NULL)
{
return 1;
}
else
{
return 0;
}
}
void * nextElementFromSinglyLinkedList(struct SLLIterator *iterator)
{
void *k;
if(iterator!=NULL)
{
k=iterator->node->ptr;
iterator->node=iterator->node->next;
}
return k;
}

