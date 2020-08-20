#include "linkedlist.h"

using namespace std;

int main()
{
	SList* list = new SList;
	int n = 0;
	int x = 0;
	int k = 0;
	int l = 0;


	initialize1(&list);
	cout << "Enter the number of element: ";
	cin >> n;
	input(list, n);
	output(list);
	cout << "\n";
	cout << "Enter the function wanting to check:\n"
		<< "1. check if the list is empty\n"
		<< "2. Find out the first node having key = value x\n"
		<< "3. Find out the last node having key= value x\n"
		<< "4. find out the node so that the difference between sum of all elements before and after x is equal to x\n"
		<< "5. Find out the node whose position is equal to k\n"
		<< "6. Add node to the front of the list\n"
		<< "7. Add node to the back of the list\n"
		<< "8. Add x element after y element in the list\n"
		<< "9. Supose the list is going up, add x element so that the list is still going up\n"
		<< "10. Delete the first node in the list\n"
		<< "11. Delete the last node in the list\n"
		<< "12. Delete x element appearing the first time in the list\n";
do{
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 1:
	{
		if (isEmpty(list)) cout << "Empty1";
		else cout << " The list does not Empty!";
		break;
	}
	case 2:
	{
		cout << "\nEnter the value wanting to find out: ";
		cin >> x;
		Snode* node = findNode_first(list, x);
		if (node == nullptr)cout << "Not find out the value!!\n";
		else
			cout << "the first value find out: " << node->key << "\n";
		break;
	}
	case 3:
	{
		cout << "\nEnter the value wanting to find out: ";
		cin >> x;
		Snode* node1 = findNode_last(list, x);
		if (node1 == nullptr) cout << "Not find out the value!\n";
		else cout << "the last value find out: " << node1->key << "\n";
		break;
	}
	case 4:
	{
		Snode* node3 = fNode_foSum(list);

		if (node3 == nullptr) cout << "Not find out the value!!\n";
		else cout << node3->key << "\n";
		break;
	}
	case 5:
	{
		int k = 0;
		do
		{
			cout << "Enter k number: ";
			cin >> k;
		} while (k > n);
		Snode* node4 = fNode_k(list, k);
		if (!node4) cout << "Not find out the value!\n";
		else
			cout << node4->key << "\n";
		break;
	}
	case 6:
	{
		cout << "Enter the value wanting to add front of the list: ";
		cin >> x;
		addFront(list, x);
		output(list);
		break;
	}
	case 7:
	{
		cout << "Enter the value wanting to add back of the list: ";
		cin >> x;
		addBack(list, x);
		output(list);
		break;
	}
	case 8:
	{
		int y = 0;
		cout << "\ny=";
		cin >> y;
		cout << "x=";
		cin >> x;
		SList* list1 = addXbehindY(list, x, y);
		if (list1 == nullptr) cout << "Not find the value!";
		else
			output(list1);
		break;
	}
	case 9:
	{
		if (isGoup(list) == false) cout << "\nlist doesn't go up!";
		else
		{
			int y = 0;
			cout << "\nEnter the value wanting to add:";
			cin >> y;
			SList* list3 = addX_listgoup(list, y);
			output(list3);
		}
		break;
	}
	case 10:
	{
		popfront(list);
		output(list);
		break;
	}
	case 11:
	{
		popback(list);
		output(list);
		break;
	}
	case 12:
	{
		cout << "\nEnter the value wanting to remove ";
		cin >> x;
		SList* list2 = deX_first_meet(list, x);
		if (list2 == nullptr) cout << "Not find out the value!";
		else output(list2);
		break;
	}
	}
	cout << "Do you want to continue?\n"
		<< "1. yes\n"
		<< "2. no\n";
	cin >> l;
	if (l == 1) cout << "Enter the function wanting to check\n";
}while (l == 1);

	deSList(list);
	delete list;
	list = nullptr;
	return 0;
}