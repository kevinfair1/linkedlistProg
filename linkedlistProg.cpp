#include <iostream>                                 
#include <list>
#include <iterator>
#include <algorithm>
#include <stack>

using namespace std;                                

int main()                                          
{                                                   
	list<int> list1, list2;          
	int num;                                        


	cout << "Line 8: Enter 10 integers of any value: " << endl;

	for (int i = 0; i < 10; i++)                          
	{
		cin >> num;
		list1.push_back(num);										
	}

	ostream_iterator<int> screen(cout, " ");         

	cout << "Line 11: list1: ";                   
	copy(list1.begin(), list1.end(), screen);

	cout << endl;                                   


	list2 = list1;
	        

	cout << "Line 11: list2: ";                   
	copy(list2.begin(), list2.end(), screen);

	cout << endl;

	cout << "\nAfter removing the first smallest\n";
	list<int>::iterator intIt = list1.begin();

	int smallest = 99999;
	int count = 0;
	int foundAt = -1;
	
	for (int p : list1)
	{
		if (p < smallest)
		{
			foundAt = count;
			smallest = p;
		}
		count++;
	}

	if (foundAt != -1)
	{
		advance(intIt, foundAt);
		list1.erase(intIt);
	}
	copy(list1.begin(), list1.end(), screen);	
	cout << "\nEnter the number to remove all of: ";
	int removeIt = -1;
	cin >> removeIt;

	if (removeIt != -1)
		list1.remove(removeIt);
	cout << "\nAfter:";
	copy(list1.begin(), list1.end(), screen);

	cin >> removeIt;
	

	return 0;

}