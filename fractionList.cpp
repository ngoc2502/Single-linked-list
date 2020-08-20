#include "fractonList.h"

void inputfrac(frac &x)
{
	cout << "numerator: ";
	cin >> x.num;
	do
	{
		cout << "denominator: ";
		cin >> x.denom;
	} while (x.denom == 0);
	return ;
}
void outputfrac(frac x)
{
	if (x.denom == 1)cout << x.num;
	else
	if (x.num == 0) cout << 0;
	else
	cout << x.num << "/" << x.denom;

}
void reduce(frac &x)
{
	int u = biggest_common_devisor(x.denom, x.num);
	x.denom = x.denom / u;
	x.num = x.num / u;
}
int biggest_common_devisor(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
frac sum(frac a, frac b)
{
	reduce(a);
	reduce(b);
	frac c;
	c.denom = a.num * b.denom;
	c.num = a.num * b.denom + b.num * a.denom;
	reduce(c);
	return c;
}
frac abs_minus(frac a, frac b)
{
	reduce(a);
	reduce(b);
	frac c;
	c.denom = a.num * b.denom;
	if (a.num * b.denom - b.num * a.denom>0)
		c.num = a.num * b.denom - b.num * a.denom;
	else c.num = b.num * a.denom - a.num * b.denom;
	reduce(c);
	return c;
}

void initialize (fracSlist** w_list)
{
	*w_list = new fracSlist{ nullptr,nullptr };
}
bool isEmpty(fracSlist* r_list)
{
	if (r_list->phead == nullptr) return(true);
	return false;
}
fracSnode* newNode(frac r_val)
{
	fracSnode* node = new fracSnode;
	node->key.denom = r_val.denom;
	node->key.num = r_val.num;
	node->pnext = nullptr;
	return node;
}


void inputFracList(fracSlist* list, int n)
{
	frac f;
	for (int i = 0; i < n; i++)
	{	
		cout << " Ordinal " << i<<" :\n";
		inputfrac(f);
		list=addBack(list, f);
	}
	return ;
}
void outputFracList(fracSlist* list)
{
	for (fracSnode* node = list->phead; node != nullptr; node = node->pnext)
	{
		reduce(node->key);
		outputfrac(node->key);
		cout << "\n";
	}
}
void popfront(fracSlist* list)
{
	if (isEmpty(list)) return;
	fracSnode* tem = list->phead->pnext;
	delete list->phead;
	list->phead = tem;
	if (tem == nullptr)
		list->ptail == nullptr;
}
void defraclist(fracSlist* list)
{
	if (isEmpty(list)) return;
	
	while(list->phead->pnext!=nullptr)
	{
		popfront(list);
	}
}
fracSnode* findNode_first(fracSlist *list, frac x)
{
	if (isEmpty(list)) return nullptr;
	for (fracSnode* n = list->phead; n != nullptr; n = n->pnext)
	{
		if (n->key.denom == x.denom && n->key.num == x.num)
			return n;
	}
	return nullptr;
}
int fracEqual(frac a, frac b)
{
	if (a.num * b.denom > a.denom* b.num) return 1;// a>b
	if (a.num * b.denom < a.denom * b.num) return -1;//a<b
	return 0;//a=b

}
fracSnode* find_X_sum(fracSlist* list)
{
	if (isEmpty(list)) return nullptr;
	if (list->phead == list->ptail) return nullptr;
	if (list->phead->pnext->pnext == nullptr) return nullptr;
	fracSnode* n = list->phead;
	for (n; n != list->ptail; n = n->pnext)
	{
		frac fsum ;
		frac bsum ;
		frac k;
		for (fracSnode* n1 = list->phead; n1 != n; n1 = n1->pnext)
		{
			fsum=sum(fsum , n1->key);
		}
		for (fracSnode* n2 = n->pnext; n2 != nullptr; n2 = n2->pnext)
		{
			bsum = sum(fsum, n2->key);
		}
		k = abs_minus(fsum, bsum);
		if( fracEqual(k,n->key)==0) return n;
	}
	return nullptr;
}
fracSnode* find_k_pos(fracSlist* list, int k)
{
	k = 0;
	int count = -1;
	for (fracSnode* n = list->phead; n != nullptr; n = n->pnext)
	{
		count++;
		if (count == k) return n;
	}
}
fracSlist* addfront(fracSlist* list, frac val)
{
	fracSnode* node = newNode(val);
	if (isEmpty(list))
	{
		list->phead = list->ptail = node;
		return list;
	}
	node->pnext = list->phead;
	list->phead = node;
	return list;
}
fracSlist* addBack(fracSlist* u_list, frac r_val)
{
	fracSnode* node = newNode(r_val);
	if (isEmpty(u_list))
	{
		u_list->phead = u_list->ptail = node;
		return u_list;
	}
	u_list->ptail = u_list->ptail->pnext = node;
	return u_list;
}
fracSlist* addXbehindY(fracSlist* list, frac x, frac y)
{
	bool kt = false;
	if (isEmpty(list)) return nullptr;
	if ((list->phead->pnext == nullptr) && (fracEqual(list->phead->key,y)==0))
	{
		addBack(list, y);
		return list;
	}
	fracSnode* n = list->phead;
	for (n; n != nullptr; n = n->pnext)
	{
		fracSnode* n1 = newNode(x);
		if (fracEqual(n->key,y)==0)
		{
			fracSnode* tem = n->pnext;
			n1->pnext = tem;
			n->pnext = n1;
			kt = true;
		}
	}
	if (kt == false) return nullptr;
	return list;
}
bool isFracGoup(fracSlist* list)
{
	for (fracSnode* n = list->phead; n->pnext != nullptr; n = n->pnext)
	{
		if (fracEqual(n->key, n->pnext->key) == 1) return false;
	}
	return true;
}
fracSlist* add_x_listgoup(fracSlist* list, frac x)
{
	if (isEmpty(list)) return nullptr;
	fracSnode* val = newNode(x);
	int k = fracEqual(val->key, list->phead->key);
	if (k == -1 || k == 0)
	{
		addfront(list, val->key);
		return list;
	}
	fracSnode* n = list->phead;
	int k1 = 0;
	for (n; n->pnext != nullptr; n = n->pnext);
	k1 = fracEqual(n->key, val->key);
	if (k1==1 || k1==0)
	{
		addBack(list, val->key);
		return(list);
	}
 

	for (fracSnode* n2 = list->phead; n2->pnext != nullptr; n2 = n2->pnext)
	{
		fracSnode* n1 = newNode(x);

		if (fracEqual(n2->key,val->key)==-1 && fracEqual(n2->pnext->key,val->key)==1)
		{
			fracSnode* temp = n2->pnext;
			n1->pnext = temp;
			n2->pnext = n1;
			return list;
		}
	}
}
void popback(fracSlist* u_list)
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
		fracSnode* node = u_list->phead;
		while (node->pnext->pnext != nullptr) node = node->pnext;
		delete node->pnext;
		u_list->ptail = node;
		node->pnext = nullptr;
		return;
	}

}
fracSlist* deX_first_meet(fracSlist* u_list, frac x)
{
	if (isEmpty(u_list)) return nullptr;
	if (fracEqual (u_list->phead->key , x)==0)
	{
		popfront(u_list);
		return u_list;
	}
	int count = 0;
	for (fracSnode* n = u_list->phead; n != nullptr; n = n->pnext)
	{
		if (fracEqual(n->key , x)==0) count++;
		if (fracEqual(n->key, x)==0 && n->pnext == nullptr && count == 1)
		{
			popback(u_list);
			return u_list;
		}
	}
	fracSnode* n1 = u_list->phead;
	while (n1 != u_list->ptail)
	{
		if (fracEqual(n1->pnext->key,x)==0)
		{
			fracSnode* n2 = n1->pnext->pnext;
			n1->pnext = n2;
			return u_list;
		}
		n1 = n1->pnext;
	}
	return nullptr;
}

