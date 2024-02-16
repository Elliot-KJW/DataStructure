#include "../List/ArrayList.hpp"
#include "../List/LinkedList.hpp"
#include "../Stack/ArrayStack.hpp"
#include "../Stack/NodeStack.hpp"
#include "../Queue/ArrayQueue.hpp"
#include "../Queue/NodeQueue.hpp"
#include "../Tree/BSTree.hpp"
#include "../Tree/Heap.hpp"
#include "../Tree/Set.hpp"
#include "../Table/HashTable.hpp"
#include "../Graph/Graph.hpp"

using namespace std;

struct test_record_type {
	int key;
	double data;

	test_record_type() {

	}

	test_record_type(int key, double data) {
		this->key = key;
		this->data = data;
	}
};

void testArrayList();
void testLinkedList();
void testStack_checkingBalanecedParentheses(string expression);
void testStack_evaluatingArithmeticExpressions(string expression);
void testStack_evaluatingPostfixExpressions(string expression);
void testStack_translatingInfixToPostfixNotation(string expression);
void testQueue_Palindroms(string str);
void testBSTree();
void testHeap();
void testSet();
void testHashTable();
void testGraph();

int main() {
	//testArrayList();
	//testLinkedList();
	//testStack_checkingBalanecedParentheses("(((6+9)/3)*(6-4))");
	//testStack_evaluatingArithmeticExpressions("(((6+9)/3)*(6-4))");
	//testStack_translatingInfixToPostfixNotation("3 * X + ( Y - 12 ) - Z");
	//testQueue_Palindroms("ra11ddar");
	//testBSTree();
	//testHeap();
	//testSet();
	//testHashTable();
	testGraph();
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

	list.remove(4);
	list.print();
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

void testStack_checkingBalanecedParentheses(string expression) {
	NodeStack<char> stack;
	for (char c : expression) {
		if (c == '(') {
			stack.push(c);
		}
		else if (c == ')') {
			if (!stack.empty()) {
				stack.pop();
			}
			else {
				cout << "error" << endl;
				return;
			}
		}
	}
	
	if (stack.size() == 0) {
		cout << "success!!" << endl;
	}
	else {
		cout << "error" << endl;
	}
}

void testStack_evaluatingArithmeticExpressions(string expression) {
	NodeStack<double> numbers;
	NodeStack<char> operators;


	for (char c : expression) {
		if (isdigit(c)) {
			numbers.push(c - '0');
		}
		else if (strchr("+-*/", c) != NULL) {
			operators.push(c);
		}
		else if (c == ')') {
			double number1 = numbers.pop();
			double number2 = numbers.pop();
		
			switch (operators.pop()) {
			case '+':
				number2 += number1;
				break;
			case '-':
				number2 -= number1;
				break;
			case '*':
				number2 *= number1;
				break;
			case '/':
				number2 /= number1;
				break;
			}

			numbers.push(number2);
		}

		cout << c << endl;
		numbers.print();
		operators.print();
		cout << endl;
	}
	numbers.print();
	cout << numbers.top() << endl;
}

void testStack_evaluatingPostfixExpressions(string expression) {
	NodeStack<double> stack;

	for (char c : expression) {
		if (isdigit(c)) {
			stack.push(c - '0');
		}
		else if (c == ' ') {
			continue;
		}
		else {
			double number1 = stack.pop();
			double number2 = stack.pop();

			switch (c) {
			case '+':
				number2 += number1;
				break;
			case '-':
				number2 -= number1;
				break;
			case '*':
				number2 *= number1;
				break;
			case '/':
				number2 /= number1;
				break;
			}

			stack.push(number2);
		}

		cout << c << endl;
		stack.print();
	}
}

void testStack_translatingInfixToPostfixNotation(string expression) {
	NodeStack<char> stack;
	string postExpression = "";

	cout << "Start Scan!" << endl << endl;

	for (char c : expression) {
		switch (c) {
		case ' ':
			continue;
		case '(':
			stack.push(c);
			break;
		case '+':
		case '-':
			if (!stack.empty() && strchr("+-", stack.top()) != NULL)  {
				postExpression += stack.pop();
				postExpression += ' ';
				stack.push(c);
				break;
			}
		case '*':
		case '/':
			if (!stack.empty() && strchr("*/", stack.top()) != NULL) {
				postExpression += stack.pop();
				postExpression += ' ';
				stack.push(c);
				break;
			}
			else {
				stack.push(c);
				break;
			}
		case ')':
			while (stack.top() != '(') {
				postExpression += stack.pop();
				postExpression += ' ';
			}
			stack.pop();
			break;
		default:
			postExpression += c;
			postExpression += ' ';
			break;
		}

		cout << c << endl;
		stack.print();
		cout << postExpression << endl << endl;
	}

	cout << "End Scan!" << endl << endl;

	while (!stack.empty()) {
		postExpression += stack.pop();
		postExpression += ' ';
		stack.print();
		cout << postExpression << endl << endl;
	}
}

void testQueue_Palindroms(string str) {
	NodeStack<char> s;
	NodeQueue<char> q, qq;
	bool isPalindroms = true;

	for (char c : str) {
		s.push(c);
		qq.enqueue(c);
	}

	q = qq;

	while(s.size() > 0) {
		cout << s.top() << endl;
		cout << q.front() << endl;

		if (s.pop() != q.dequeue()) {
			isPalindroms = false;
		}
		cout << endl;
	}

	cout << ((isPalindroms == true) ? "true" : "false") << endl;
}

void testBSTree() {
	BSTree<int> tree;
	tree.insert(45);
	tree.insert(53);
	tree.insert(51);
	tree.insert(54);
	tree.insert(9);
	tree.insert(3);
	tree.insert(17);
	tree.insert(13);
	tree.print(0);

	tree.erase_one(45);
	tree.print(0);

	tree += tree;
	tree.print(0);

	cout << tree.count(17) << endl;
}

void testHeap() {
	Heap<int> heap;

	heap.insert(45);
	heap.insert(42);
	heap.insert(23);
	heap.insert(35);
	heap.insert(21);
	heap.insert(22);
	heap.insert(4);
	heap.insert(19);
	heap.insert(27);
	heap.print();

	heap.remove_top();
	heap.print();
}

void insertSet(Set<int>& set, int a) {
	std::cout << "insert " << a << std::endl;
	set.insert(a);
	std::cout << "----- Set 시작 -----" << std::endl << std::endl;
	set.print(0);
	std::cout << std::endl << "----- Set 종료 -----" << std::endl << std::endl;
}

void eraseSet(Set<int>& set, int a) {
	set.erase(a);
	std::cout << "erase " << a << std::endl;
	std::cout << "----- Set 시작 -----" << std::endl << std::endl;
	set.print(0);
	std::cout << std::endl << "----- Set 종료 -----" << std::endl << std::endl;
}

void testSet() {
	Set<int> set;
	char c;
	while (true) {
		cin >> c;
		if (c == 'q') {
			break;
		}
		else if (c == 'i') {
			int i;
			cin >> i;
			insertSet(set, i);
		}
		else if (c == 'e') {
			int i;
			cin >> i;
			eraseSet(set, i);
		}
		else if (c == 'p') {
			set.print(0);
		}
	}
}

void testHashTable() {
	HashTable<test_record_type> table;

	table.insert(*(new test_record_type(201, 2.5)));
	table.insert(*(new test_record_type(1, 2.5)));
	table.insert(*(new test_record_type(202, 2.5)));
	table.remove(1);
	table.insert(*(new test_record_type(1, 2.5)));
	table.insert(*(new test_record_type(202, 2.5)));

	table.print();
}

void testGraph() {
	Graph<int> graph;

	graph.print();
	graph.add_vertex(10);
	graph.add_vertex(22);
	graph.add_edge(0, 1);
	graph.print();

}