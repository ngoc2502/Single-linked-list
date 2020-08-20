#include<iostream>
using namespace std;
//fraction  
struct frac
{
	int num = 0;//numerator
	int denom = 1;//denominator
};
struct fracSnode
{
	frac key;
	fracSnode* pnext;
} ;
struct fracSlist
{
	fracSnode* phead;
	fracSnode* ptail;
};
void inputfrac(frac &x);
void outputfrac(frac x);
void reduce(frac& x);
int biggest_common_devisor(int a, int b);
frac sum(frac a, frac b);
frac abs_minus(frac a, frac b);

void initialize(fracSlist** w_list);
bool isEmpty(fracSlist* r_list);
fracSnode* newNode(frac r_val);

void inputFracList(fracSlist* list, int n);
void outputFracList(fracSlist* list);

void defraclist(fracSlist* list);
void popfront(fracSlist* list);
fracSlist* addBack(fracSlist* u_list, frac r_val);
fracSnode* findNode_first(fracSlist* list, frac x);
fracSnode* find_X_sum(fracSlist* list);
fracSnode* find_k_pos(fracSlist* list, int k);
fracSlist* addfront(fracSlist* list, frac val);
fracSlist* addXbehindY(fracSlist* list, frac x, frac y);
fracSlist* add_x_listgoup(fracSlist* list, frac x);
bool isFracGoup(fracSlist* list);
void popback(fracSlist* u_list);
fracSlist* deX_first_meet(fracSlist* u_list, frac x);
