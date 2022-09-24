#include "../include/pch.h"
#include "../include/List.h"

int main()
{
	/*----Char list----*/

	/* Creating list of chars */
	List<char> charList('a');
	
	/* Inserting values to list in different positions */
	charList.insertNode('b', 0);
	charList.insertNode('c', 1);
	charList.insertNode('d', -1);
	charList.insertNode('e', -2);
 
	/* Normal list printing */
	charList.print();

	/* Reversed list printing */
	charList.print(true);
	std::cout << "\n";

	/*----Int list----*/

	/* Creating list of integers */
	List<int> intList(1);

	/* Inserting value to list */
	intList.insertNode(2, 0);

	/* Switching head of list to next element */
	intList.nextHead();

	/* Inserting values to list in different positions */
	intList.insertNode(3, 0);
	intList.insertNode(4, -1);
	
	/*Swtiching head of list to previous element */
	intList.prevHead();

	/* Normal list printing */
	intList.print();

	/* Reversed list printing */
	intList.print(true);
	std::cout << "\n";

	/* Searching for values with index i in list  */
	std::cout << "Int list[17]: " << intList[17].data <<
		"\nChar list[13]: " << charList[13].data << std::endl;

	return 0;
}
