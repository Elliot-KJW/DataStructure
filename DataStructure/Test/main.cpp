#include "../List/ArrayList.hpp"
#include "../List/LinkedList.hpp"
#include "../Stack/ArrayStack.hpp"
#include "../Stack/NodeStack.hpp"

using namespace std;

void testArrayList();
void testLinkedList();
void testStack_checkingBalanecedParentheses(string expression);
void testStack_evaluatingArithmeticExpressions(string expression);
void testStack_evaluatingPostfixExpressions(string expression);
void testStack_translatingInfixToPostfixNotation(string expression);


int main() {
	//testArrayList();
	//testLinkedList();
	//testStack_checkingBalanecedParentheses("(((6+9)/3)*(6-4))");
	//testStack_evaluatingArithmeticExpressions("(((6+9)/3)*(6-4))");
	testStack_translatingInfixToPostfixNotation("3 * X + ( Y - 12 ) - Z");
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