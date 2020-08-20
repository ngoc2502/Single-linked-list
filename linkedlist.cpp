# include"linkedlist.h"
using namespace std;

void initialize1(SList** w_list)// first way
{
	*w_list = new SList;
	(*w_list)->phead = nullptr;
	(*w_list)->ptail = nullptr;
}
void initialize2(SList** w_list)//second way
{
	*w_list = new SList{nullptr,nullptr};
}
bool isEmpty( SList* r_list)
{
	if (r_list->phead == nullptr) return(true);
	return false;
}
Snode* newNode1(int r_val)// fisrt way 
{
	Snode* node = new Snode;
	node->key = r_val;
	node->pnext = nullptr;
	return node;
}
Snode* newNode2(int r_val)// second way
{
	return new Snode{r_val, nullptr};
}
SList* addFront(SList* u_list, int r_val)
{
	Snode* node= newNode1(r_val);
	if (isEmpty(u_list))
	{
		u_list->phead = node;
		u_list->ptail = node;
		return u_list;
	}
	node->pnext = u_list->phead;
	u_list->phead = node;
	return u_list;
}
SList* addBack(SList* u_list, int r_val)
{
	Snode* node = newNode1(r_val);
	if (isEmpty(u_list))
	{
		u_list->phead = u_list->ptail = node;
		return u_list;
	}
	
	u_list->ptail= u_list->ptail->pnext = node;
	return u_list;
}

void input(SList* list, int n )
{
	int x=0;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the value: ";
		//newNode1(x);
		cin >> x;
		list= addBack(list, x);
	}
 }
void output(SList* list)
{
	Snode* node = list->phead;
	while (node  != nullptr)
	{
		cout << node->key << "  ";
		node = node->pnext;
	}
}

Snode* findNode_first(SList* list, int val)
{
	if (isEmpty(list)) return nullptr;
	Snode* node = list->phead;
	for (node; node != nullptr; node=node->pnext)
	{
		if (node->key == val)

		{
			return node;
			break;
		}
	}
	return nullptr;
}
Snode* findNode_last(SList* list, int val)
{
	if (isEmpty(list)) return nullptr;
	Snode* node = list->phead;
	bool check=false;
	SList* l = new SList{ nullptr, nullptr };
	for (node; node != nullptr; node = node->pnext)
	{
		if(node->key==val) 
		{
			check = true;
			addFront(l, node->key);
	}
	}
	deSList(l);
	if (check == false) return nullptr;
	return l->phead;

}

void popback(SList* u_list)
{
	if (isEmpty(u_list)) return;
	if (u_list->phead == u_list->ptail)
	{
		delete u_list->phead;
		u_list->phead = u_list->ptail = nullptr;
		return;
	}
	else
	{
		Snode* node = u_list->phead;
		while (node->pnext->pnext != nullptr) node = node->pnext;
		delete node->pnext;
		u_list->ptail = node;
		node->pnext = nullptr;
		return;
	}

}
void popfront(SList* u_list)// delete the first node
{
	if (isEmpty(u_list)) return;
	Snode* node = u_list->phead->pnext;
	delete u_list->phead;
	u_list->phead = node;
	if (node == nullptr)
		u_list->ptail = nullptr;
}
void deSList(SList* list)
{
	if (isEmpty(list)) return;
	while (list->phead->pnext != nullptr)
	{
		popfront(list);
	}
}
Snode* fNode_foSum(SList* list)
{
	if (isEmpty(list)) return nullptr;
	if (list->phead->pnext == nullptr) return nullptr;
	if (list->phead->pnext->pnext == nullptr) return nullptr;
	Snode* n = list->phead->pnext;
	for (n; n->pnext != nullptr; n = n->pnext)
	{
		int fsum = 0;
		int bsum = 0;
		for (Snode* k = list->phead; k != n; k = k->pnext)
		{
			fsum += k->key;
		}
		for (Snode* j = n->pnext; j != nullptr; j = j->pnext)
		{
			bsum += j->key;
		}
		if ((fsum - bsum == n->key)) return n;
	}
	return nullptr;
}
Snode* fNode_k(SList* list, int val)
{
	int k = 0;
	Snode* n = list->phead;
	while (k != val)
	{
     	n = n->pnext;	
		k++;
	}
	return (n);
}
SList* addXbehindY(SList* list, int x, int y)
{
	bool kt = false;
	if (isEmpty(list)) return nullptr;
	if ((list->phead->pnext == nullptr) && (list->phead->key == y))
	{
		addBack(list, y);
		return list;
	}
	Snode* n = list->phead;
	for ( n; n != nullptr; n = n->pnext)
	{
		Snode* n1 = newNode1(x);
		if (n->key == y)
		{
			Snode* tem = n->pnext;
			n1->pnext= tem;
			n->pnext = n1;
			kt = true;
		}
	}
	if (kt == false) return nullptr;
	return list;
}
int length(SList* r_list)
{
	Snode* n = r_list->phead;
	int len = 0;
	for (n; n != nullptr; n = n->pnext)
	{
		len += 1;
	}
	return (len);
}
SList* deX_first_meet(SList* u_list, int x)
{
	if (isEmpty(u_list)) return nullptr;
	if (u_list->phead->key == x)
	{
		popfront(u_list);
		return u_list;
	}
	int count = 0;
    for (Snode* n = u_list->phead ; n != nullptr; n = n->pnext)
	{
		if (n->key == x) count++;
		if (n->key == x && n->pnext == nullptr && count==1)
		{
			popback(u_list);
			return u_list;
		}
	}
	Snode* n1 = u_list->phead;
	while (n1!= u_list->ptail)
	{
		if (n1->pnext->key == x )
		{
			Snode* n2 = n1->pnext->pnext;
			n1->pnext = n2;
			return u_list;
		}
		n1 = n1->pnext;
	}
	return nullptr;
}
bool isGoup(SList* r_list)
{
	for (Snode* n = r_list->phead; n != r_list->ptail;n=n->pnext)
	{
		if (n->key > n->pnext->key)
			return false;
	}
	return true;
}
SList* addX_listgoup(SList* u_list, int val)
{
	if (isEmpty(u_list)) return nullptr;
	if (val <= u_list->phead->key)
	{
		addFront(u_list, val);
		return u_list;
	}
	Snode* n = u_list->phead;
	for (n; n->pnext!= nullptr; n = n->pnext);
	if (n->key <= val)
	{
		addBack(u_list, val);
		return(u_list);
	}
	
	for (Snode* n2 = u_list->phead; n2->pnext != nullptr; n2 = n2->pnext)
	{
		Snode* n1 = newNode1(val);

		if ((n2->key <= val) && (n2->pnext->key >= val))
		{
			Snode* temp = n2->pnext;
			n1->pnext = temp;
			n2->pnext = n1;
			return u_list;
		}
	}
}