#include "ArrayList.cpp"

int main() {
	ArrayList<int> list(20);
	ArrayList<int> list2(20);
	list.insert(4);
	list.insert(8);
	list.insert(4);

	list.print();

	list2.insert(5);
	list2.insert(7);

	list += list2;
	
	list.print();

	std::cout << list.occurences(4) << std::endl;

	ArrayList<int> list3(list);
	list.print();

	return 0;
}