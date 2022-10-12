#include <iostream>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

/*Name: Killian Hasson 		Class: CS202		Date: 05/11/21
 * For this program we are tasked with making a bulletin board which will be a data structure of a BST, although we are not there yet
 * I have been trying to put some thought into what would be the best way to sort the data in that tree. So far I have decided to split
 * the renters up from short term, monthly(medium term), and yearly(long term) each of these will require different data but they do all
 * require a name and price at the least. There is a lack of functions in alot of my classes which I am aware of, I struggled alot with 
 * the BST I dont know what it is about only using classes but it took me a week to properly add and be able to remove even though the remove 
 * still isnt perfect. My plan was to have the retrieve function find a rental and then call the other functions to edit or add to which never got done.
 * */

class lease;
/* 
 * vector<int> zipcode(5);
*/
//Base class for roommate
class roommate
{
	public:
		roommate();
		roommate(string Name, int Num, float Price);
		~roommate();
		friend ostream & operator<<(ostream &, const roommate & obj);	
		friend bool operator < (roommate const&, roommate const &);
		friend bool operator == (roommate const&, string Name);
		friend bool operator == (roommate const&, int Num);
		virtual void display(ostream &)const;
		string get_name();
		float get_price();
	protected:
		string name;//Name of the person looking for roommates
		int num;//Number of rooms available
		float price;//Price for the unit
};

//Daily rental, think AIRBNB
class short_term: public roommate
{
	public:
		short_term();
		short_term(string Name, int Num, float Price, int Max);
		~short_term();
		void display(ostream &)const;
		//int set_max(int new_max);
		//int edit();
	protected:
		int max_stay;
};

//Monthly rental, like a month to month rental
class monthly: public roommate
{
	public:
		monthly();
		monthly(string Name, int Num, float Price,float Uti);
		~monthly();
		void display(ostream &)const;
		//int add_utilities(float Utilities);//Allow the person putting in there add to add utilities to the base price if needed?
	protected:
		float utilities;//May have utilities
};

//Yearly rental
class yearly: public roommate
{
	public:
		yearly();
		yearly(string Name, int Num, float Price, float DownPay, string Lease);
		~yearly();
		void display(ostream &)const;
	protected:
		string lease;//The renter can input some information inregards to their lease, ie: no pets, no smoking ect
		float downpay;//May require a downpayment of sorts
};


//The node class is a basic one, need to return and get both left and right nodes
class node
{
	public:
		node();
		node(roommate * obj);
		~node();
		void copy(roommate * obj);//Copy two objs
		string get_name();//Gets the name of the rental
		node *& get_left();//Returns the left node by reference
		node * set_left(node * temp);//Set the left pointer
		node *& get_right();//Returns the right node by reference
		node * set_right(node * temp);//Set the right pointer
		roommate * get_data();//Return the rental 

	protected:
		roommate * rental;//Rental is a pointer to a roommate which is a base class
		node * left;//Left pointer
		node * right;//Right pointer
};

//This class will specifically handle the BST which will not be a balanced tree
//NEED TO REMIND MYSELF TO HANDLE IN ORDER SUCCESSOR SEARCH, reminded myself couldnt do it
class BST
{
	public:
		BST();
		~BST();
		int add(roommate * to_add);//Iterative add function
		int add(node *& root, roommate * to_add);//Recursive add function
		int remove(string Name);//Iterative remove function by name
		int remove(string Name, node *& root);//Recursive remove function by name
		void display();//Display function
		void display(node * root);//Recursive display function
		node * in_order(node * curr);//Returns the left most node, pass in the node tot he right that we want to remove
		node * retrieve(int Num);//Retrieve function take number to find the price
		node * retrieve(int Num, node * root);//Recursive retrieve function, returns the found node
	protected:
		node * root;//Root node 
};



















