#include "../include/List.h"
#include "../include/pch.h"

int main()
{
	List<char> charList('S');	//list of chars
	charList.insertNode('g');	//inserting values to list in different places
	charList.insertNode('t', 1);
	charList.insertNode('n', -1);
	charList.insertNode('r', 2);
	charList.insertNode('i', -2);

	charList.print();	//normal list print
	std::cout << '\n';
	charList.prevNode().print(true);	//reversed list print, starting from previous node
	std::cout << "\n\n";

	List<int> intList(1);	//int list
	intList.insertNode(2);	//inserting values to list
	intList.nextNode().insertNode(3);	//we can change node, from where we count index
	intList.insertNode(4, -1);

	intList.print();
	std::cout <<  '\n';
	intList.prevNode().print(true);
	std::cout << "\n\n";

	/* Searching for values with index i in list  */
	std::cout << "Int list[17]: " << intList.findNode(17).data <<
		"\nChar list[13]: " << charList.findNode(13).data << std::endl;

	return 0;
}
