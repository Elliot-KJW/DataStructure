#include "ArrayList.cpp"

int main() {
	ArrayList<int> list;
	ArrayList<int> list2;
	list.insert(4);
	list.insert(8);
	list.insert(4);

	list.print();

	list2.insert(5);
	list2.insert(7);

	list += list2;
	
	list.print();

	std::cout << list.occurences(4) << std::endl;

	return 0;
}