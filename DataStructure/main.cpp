#include "ArrayList.hpp"
#include "LinkedList.hpp"

using namespace std;

void testArrayList();

void testLinkedList();
int main() {
	//testArrayList();
	testLinkedList();

	return 0;
}

void testArrayList() {
	ArrayList<int> list(20);
	ArrayList<int> list2(20);
	list.insert(4);
	list.insert(8);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);

	std::cout << list.size() << "\n";

	list.print();

	list2.insert(5);
	list2.insert(7);

	list += list2;

	list.print();

	std::cout << list.occurences(4) << std::endl;

	ArrayList<int> list3(list);
	list3.print();

	list3 = list + list2;
	list3.print();
}

void testLinkedList() {
	LinkedList<int> list;
	list.insert(4);
	list.insert(8);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);
	list.insert(4);

	LinkedList<int>list2(list);
	list.print();

	list2.print();
	
	LinkedList<int>list3;
	list3.insert(10);
	list3.insert(10);
	list3.insert(10);

	list = list3;
	list.print();

	list2 += list3;
	list2.print();

	LinkedList<int>list4;
	list4 += list3;
	list4.print();

	cout << list2.count(4) << endl;
	cout << list2.count(10) << endl;
	cout << list2.count(8) << endl << endl;

	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl;
	cout << list2.grab() << endl << endl;

	list2.erase_one(8);
	list2.erase_one(10);
	list2.erase_one(10);
	list2.erase_one(10);
	list2.erase_one(10);
	list2.erase_one(4);
	list2.erase_one(4);
	list2.print();

	cout << list2.count(4) << endl;
	cout << list2.count(10) << endl;
	cout << list2.count(8) << endl;

}