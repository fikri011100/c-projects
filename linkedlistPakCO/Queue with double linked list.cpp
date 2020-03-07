#include <iostream>
#include<stdlib.h>
#include<string>

using namespace std;



/**
 *
 * Defining Node class to hold data of student.
 *
 */

class Node
{
public:

	// Defining variables for class.

	int Priority;
	int roll_number;
	string name;
	string phone;
	float cgpa;



	//Node pointers to store address of next and last node.

	Node *next;
	Node *previous;


	//Constructor to set values passed as arguments.

	Node(int p, int r, string n, string ph, float c)
	{


		Priority = p;
		roll_number = r;
		name = n;
		phone = ph;
		cgpa = c;


		next = NULL;
		previous = NULL;
	}

};

//Defining d_link_list class.

class d_link_list
{

//Pointers to hold address of first and last node in linked list.

private:
	Node *first;
	Node *last;

public:

	d_link_list()
	{

		first = last = NULL;
	}



	

	void insert(int p, int r, string n, string ph, float c)
	{

		Node *newNode = new Node(p, r, n, ph, c);
		Node *curr = first;
		Node *prev = curr;

		if(curr == NULL)
		{

			first = last = newNode;
			delete curr;
			delete prev;

		}
		else
		{


			while(curr != NULL && curr->Priority <= p)
			{

				prev = curr;
				curr = curr->next;

			}

			prev->next = newNode;
			newNode->previous = prev;
			newNode->next = curr;






		}
	}




	


	void pop()
	{



		Node *tmp = first;

		while(tmp->next->next != NULL)
		{

			tmp = tmp->next;

		}


		tmp->next = NULL;
		last = tmp;


	}




	void display()
	{

		Node *tmp = first;

		while(tmp != NULL)
		{

			cout << "Priority :" << tmp->Priority << endl;
			cout << "Roll Number :" << tmp->roll_number << endl;
			cout << "Name :" << tmp->name << endl;
			cout << "Phone :" << tmp->phone << endl;
			cout << "CGPA :" << tmp->cgpa << endl;
			cout << endl;
			cout << endl;
			tmp = tmp->next;
		}
	}

};


int main(int argc, char** argv)
{
	d_link_list d;


	cout << "\t\tPriority Queue Implementation using Linked List" << endl << endl;


	//Inserting some random values in linked list.

	d.insert(1, 185, "Muhammad Faiz Azmi", "088210374953", 3);
	d.insert(4, 193, "Pevita pearce", "011329450", 3.5);
	d.insert(3, 021, "Anya Geraldine", "0922132134", 3.52);
	d.insert(10, 057, "Kendal Jenner", "0813109872", 4.1);

	//Display Function called.

	d.display();



	//Pop Function called.
	d.pop();
	cout << endl;
	cout << endl;
	d.display();


	system("pause");
	return 0;
}
