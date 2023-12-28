#include "ArrayList.cpp"

int main() {
	ArrayList<int> list = ArrayList<int>();
	ArrayList<int> list2 = ArrayList<int>();
	list.insert(4);
	list.insert(8);
	list.insert(4);

	list.print();

	list2.insert(5);
	list2.insert(7);

	list += list2;

	list.print();

	return 0;
}