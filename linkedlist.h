#include<iostream>

using namespace std;

struct Snode
{
	int key;
	Snode* pnext;
};
struct SList
{
	Snode* phead;
	Snode* ptail;
};
void input(SList* list, int n);
void output(SList* list);
void initialize1(SList** list);// create empty list

bool isEmpty(SList* list);// return true if list empty

Snode* newNode1(int r_val);// fisrt way to create new node
Snode* newNode2(int r_val);// second way to create new node
SList* addFront(SList* u_list, int r_val);// add an element to front of the list
SList* addBack(SList* u_list, int r_val);//add an element to the last of the list
Snode* findNode_first(SList* list, int val);// find the first node having key=val
Snode* findNode_last(SList* list, int val);// find the last node having key=val
SList* addXbehindY(SList* list, int x, int y);// add node X behind node y


void popfront(SList* u_list);// delete the first node
void popback(SList* u_list);// delete the last node
void deSList(SList* list);// delete all node
Snode*fNode_foSum(SList* list);// find out the node so that the difference between sum of all elements before and after x is equal to x
Snode* fNode_k(SList* list, int val);// find out node have key=k
SList* deX_first_meet(SList* list, int x);// delete node X in the first time it appears
bool isGoup(SList* list);// return true if the list is going up
SList* addX_listgoup(SList* u_list, int val);// Supose the list is going up, add x element so that the list is still going up

