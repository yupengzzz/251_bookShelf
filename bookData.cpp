/**
* @file bookData.cpp
* @author Yupeng Zhao
* @Date 2018-07-09
* @version 1.0
* @section DESCRIPTION
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____Yupeng Zhao____ _____2018-07-09______________
//
// ____ 301334967 ______
//

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Book
{
public:
	Book();
	void addBook();
	void printBook();
	friend bool operator <(Book& book1, Book& book2);

private:
	string arthur;
	string publication;
	string title;
};


int main()
{
	vector<Book> bookVector;
	Book addBook;
	int ans = 0;
	do
	{
		cout << "Select from the following choices: " << endl
			<< "1. Add a new book" << endl
			<< "2. Print listing sorted by arthur" << endl
			<< "3. Quit" << endl;
		cin >> ans;
		cin.ignore(100, '\n');
		if(cin.fail() || (ans != 1 && ans != 2 && ans != 3))
		{
			cin.clear();
			cin.ignore(100, '\n');
			cerr << "Error: Your entry cannot be recognized." << endl
				<< "Terminating program." << endl;
			exit (1);
		}

		if(ans == 1)
		{
			addBook.addBook();
			bookVector.push_back(addBook);
		}
		else if(ans == 2)
		{
			cout << "The books entered so far, sorted alphabetically by author are:" << endl;
			sort(bookVector.begin(), bookVector.end());
			for(vector<Book>::iterator it = bookVector.begin(); it != bookVector.end(); ++it)
			{
				it->printBook();
			}
		}
		else if(ans == 3)
		{
			cout << "End of simulation." << endl;
			break;
		}
	}while(ans == 1 || ans == 2);

	return 0;
}

Book::Book()
{
}

void Book::addBook()
{
	cout << "Enter title: " << endl;
	getline(cin, title);
	cout << "Enter arthur: " << endl;
	getline(cin, arthur);
	cout << "Enter publication date: " << endl;
	getline(cin, publication);
}


bool operator <(Book& book1, Book& book2)
{
	return(book1.arthur <= book2.arthur);
}


void Book::printBook()
{
	cout << "	" << arthur << ". " << title
		<< ". " << publication << "." << endl;
}
