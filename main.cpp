#include "prog3.h"
/*
 * Name: Killian Hasson		Date: 05/19/21		Class:CS202
 *
 *Below is the basic loop for handling and managing a BST.
 * */

int main()
{
	//BELOW ARE ALL TEMP DATA
	BST app;
	string Name;
	string Lease;
	int Bg_check;
	int Num;
	float Price;
	float DownPay;
	int Max;
	int resp;
	int resp2;
	float Uti;
	//Loop for handling input and display
	do{
	cout << "Please select from the following list of options.";
	cout << "\nEnter 1 if you would like to add a unit for rent.\nPress 2 if you would like to view the current units available for rent."; 
	cout << "\nPress 3 to remove a unit." << "\nPress 4 to search for a specific rental by price." << endl;
	cin >> resp;
	//If were going to add a rental we need to ensure we are adding the correct roommate type of object
	if(resp == 1)
	{
		cout << "Please enter the corresponding number for the type of rental option...\n1 for short term.\n2 for seasonal.\n3 yearly rental option: ";
		cin >> resp2;
		//Short term rental input
		if(resp2 == 1)
		{
			cout << "Please enter in your name: ";
			cin >> Name;
			cout << "Please enter in the number of rooms available: ";
			cin >> Num;
			cout << "Please enter in the price for this unit: ";
			cin >> Price;
			cout << "Please enter in the max number of days the occupants can stay: ";
			cin >> Max;
			short_term * obj = new short_term(Name,Num,Price,Max);
			//node * new_rental = new node(obj);
			app.add(obj);				
		}
		//Month to month rental input
		if(resp2 == 2)
		{
			cout << "Please enter in your name: ";
                        cin >> Name;
                        cout << "Please enter in the number of rooms available: ";
                        cin >> Num;
                        cout << "Please enter in the price for this unit: ";
                        cin >> Price;
			cout << "Please enter the utilites price per month: ";
			cin >> Uti;	
			monthly * obj = new monthly(Name,Num,Price,Uti);
			app.add(obj);	
		}
		//Yearly rental input
		if(resp2 == 3)
		{
			cout << "Please enter in your name: ";
                        cin >> Name;
                        cout << "Please enter in the number of rooms available: ";
                        cin >> Num;
                        cout << "Please enter in the price for this unit: ";
                        cin >> Price;
			cout << "Please enter in the amount for a downpayment: ";
			cin >> DownPay;
			cout << "Please enter in some notes about the lease: ";
			cin.ignore(INT_MAX, '\n');
			getline(cin, Lease);
			
			yearly * obj = new yearly(Name,Num,Price,DownPay,Lease);
			app.add(obj);
		}
	}
	//Display function call
	if(resp == 2)
	{
		app.display();
	}
	//Find a rental by name and remove it from the BST
	if(resp == 3)
	{
		cout << "Please enter the name of the rental you want removed: ";
		cin >> Name;
		app.remove(Name);
	}	
	//THIS DOESNT WORK
	//This should return a rental that has a matching price, probably the most likely to be desired
	if(resp == 4)
	{
		cout << "What is your desired price: ";
		cin >> Num;

		node * obj = app.retrieve(Num);
		cout << *obj->get_data();	



	}
	}while(resp != 0);//Exit from the loop
}


