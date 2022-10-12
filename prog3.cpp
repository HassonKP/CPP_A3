#include "prog3.h"

/*
 * Name: Killian Hasson		Date: 05/19/2021	Class: CS202
 *
 * Below is my implementation file, this file contains all of the functions required to properly handle the BST. I have 1 Base roommate class which has
 * the operator overloading functions in them, I changed to have three overloaded operators and given more time and a better understanding on this task
 * I would have attempted to have more operators implemented. I have three kinds of rentals derived from the base class, each has atleast 1 additional type 
 * of data just to ensure I actually implemented them correctly. The functions are listed below...
*/
//Base constructor for the base class
roommate::roommate()
{
	
	num = 0;
	price = 0;

}

//Constructor with arguements
roommate::roommate(string Name,int Num, float Price)
{

	name = Name;

	num = Num;

	price = Price;
}

//Destructor
roommate::~roommate()
{
	num = 0;
}

//Overloaded the operator to help with easier display, this might need to be changed for dealing with nodes but this may work for now
ostream & operator << (ostream & out, const roommate & obj)
{
	obj.display(out);//Calls the display function dynamically with different kinds of rental or roommate objects
	return out;
}

//Overloaded operator to help navigate and compare for a BST, this amy need to be built upon to better handle with nodes but for now it can handle the data
bool operator < (roommate const & a, roommate const & b)
{
	return a.price < b.price;
}

//Overloaded operator for comparing two names to find a match
bool operator == (roommate const & a, string Name)
{
	return  a.name == Name;
}

//Overloaded operator to ensure we found a matching price
bool operator == (roommate const & a, int Num)
{
	return a.price == Num;
}

//Return the price of the rental
float roommate::get_price()
{
	return price;
}

//Returns the name of the renter
string roommate::get_name()
{
	return name;
}

//Display any kind of roommate request
void roommate::display(ostream & out) const
{
}

//SHORT TERM CLASS FUCNTIONS -------------------------------------------------------------------------------------------------------
//Base constructor
short_term::short_term(): roommate()
{
	max_stay = 0;
}

//Short term roommate constructor w/ arguments
short_term::short_term(string Name,int Num, float Price, int Max): roommate(Name,Num,Price)
{
	max_stay = Max;
}

//Destructor
short_term::~short_term()
{
	max_stay = 0;
}

//Display function for the short term rentals
void short_term::display(ostream & out) const
{
	out << name << " (" << num << ") $" << price
            << " up to " << max_stay << " days" << endl;
	return;
}

//MONTHLY CLASS FUNCTIONS -----------------------------------------------------------------------------------------------------------
//Base constructor
monthly::monthly(): roommate()
{
	utilities = 0;
}

//Constructor for monthly roommate takes arguments
monthly::monthly(string Name,int Num,float Price, float Uti): roommate(Name,Num,Price)
{
	utilities = Uti;
}

//Destructor for the monthly rental
monthly::~monthly()
{
	utilities = 0;
}

//Displays the monthly rental 
void monthly::display(ostream & out)const
{
	out << name << " (" << num << ") $" << price << "\nMonthly utilities: $" << utilities << endl;
	return;
}

//IF TIME ALLOW THIS FUNCTION TO CHANGE UTILITIES PRICE
//int add_utilities(float Utilities);//Allow the person putting in there add to add utilities to the base price if needed?


//YEARLY CLASS FUNCTIONS --------------------------------------------------------------------------------------------------------------
yearly::yearly(): roommate()
{
	downpay = 0;
	lease = " ";
	
}

//Constructor for yearly roommate, takes arguments
yearly::yearly(string Name, int Num, float Price, float DownPay, string Lease): roommate(Name,Num,Price)
{
	downpay = DownPay;
	lease = Lease;
}

//Destructor for yearly roommate
yearly::~yearly()
{
	downpay = 0;
	lease = " ";
}

//Display the yearly rental
void yearly::display(ostream & out)const
{
	out << name << " (" << num << ") $" << price << ". Down payment: $" << downpay << "\nLease notes: " << lease << ".\n";
	return;
}


//NODE CLASS FUNCTIONS ---------------------------------------------------------------------------------------------------------------
//Base constructor
node::node()
{
	rental = NULL;
	left = NULL;
	right = NULL;
}

//Copies the roommate obj to the rental pointer in the node
node :: node(roommate * obj)
{
  rental = obj;
  left = NULL;
  right = NULL;
}

//Node destructor
node :: ~node()
{
	if(left)
	{
		delete left;
		left = NULL;
	}
	if(right)
	{
		delete right;
		right = NULL;
	}
}
//WASNT NEEDED
/*
void node::display()
{
	cout << rental;
}*/
//Copy obj to obj
void node::copy(roommate * obj)
{
	rental = obj;
	return;
}

//Get the left node by reference
node *& node::get_left()
{
	return left;
}

//Sets the left pointer to the new node
node * node::set_left(node * temp)
{
	left = temp;
}

//Get the right node by reference
node *& node::get_right()
{
	return right;
}

//Set the right pointer to the node taken in the argument
node * node::set_right(node * temp)
{
	right = temp;
}

//Gets the roommate object
roommate * node::get_data()
{
	return rental;
}

//Calls the get name function in roommate class in order to return the name directly
string node::get_name()
{
	return rental->get_name();
}

//BINARY SEARCH TREE CLASS FUNCTIONS -----------------------------------------------------------------------------------------------
//Constructor for the BST
BST::BST()
{
	root = NULL;
}

//Destructor for the BST
BST::~BST()
{
	if(root)
	{
		delete root;
		root = NULL;
	}
}
//Add function which will take in a roommate
int BST::add(roommate * to_add)
{
	if(!root)
	{
		root = new node(to_add);
	}
	else
		add(root,to_add);
}

//This function will recursively find where to add the roommate application
int BST::add(node *& root,roommate * to_add)
{

  if(*root->get_data() < *to_add && root->get_right())
  {
	add(root->get_right(), to_add);
  }
  else if(*root->get_data() < *to_add)
  {
	root->set_right(new node(to_add));
  }
  else if(!root->get_left())
  {
	root->set_left(new node(to_add));
  }
  else
  {
	add(root->get_left(),to_add);
  }
return 1;
}

//BELOW FUNCTIONS NOT IMPLEMENTED MAY NOT BE NEEDED

/*node * BST::find(string Name)
{
	return find(Name,root);	
}

node * BST::find(string Name, node * curr)
{
	if(*curr->get_data() == Name)
	{
		return curr;
	}
	if(curr->get_left())
	{
		node * temp = find(Name, curr->get_left());
		if(temp)
			return temp;
	}
	if(curr->get_right())
	{
		node * temp = find(Name, curr->get_right());
		if(temp)
			return temp;
	}
	return NULL;
}

int BST::delete_min() 
{
  root = delete_min(root);
}

node * BST::delete_min(node * curr) 
{
  if (curr->get_left()) 
  {
    curr->set_left(delete_min(curr->get_left()));
    return curr;
  }
  return curr->get_right();
}
*/

//Remove function, takes in name to find
int BST::remove(string Name)
{
	//Check if the BST is empty
	if(!root)
	{
		cout << "No rentals!" << endl;
		return 0;
	}
	remove(Name, root);//Pass the root into the recursive call
}

//Recursive remove function
int BST::remove(string Name, node *& root)
{
	//Check if the name matches the sought name
	if(*root->get_data() == Name)
	{
		//Check if the node found is a leaf
		if(!root->get_right() && !root->get_left())
		{
			delete root;
			root = NULL;
			return 1;
		}
		//Check if left child exists and no right child
		if(root->get_left() && !root->get_right())
		{
			node * current = root->get_left();
			delete root;
			root = NULL;
			root = current;
		}
		//Checks if only a right child exists
		if(!root->get_left() && root->get_right())
		{
			node * current = root->get_right();
			delete root;
			root = NULL;
			root = current;
		}
		//Two children exist for the found node
		else
		{
			node * current = root->get_right();//set a temp node one to the right
			in_order(current);//Find the replacement node using the temp node
			root->copy(current->get_data());//copy the objects
			remove(current->get_name(), root->get_right());//find the node that was copied and remove it
		}		
	}
	//Traverse to the left
	if(root->get_left())
	{
		remove(Name, root->get_left());
	}
	//Traverse to the right
	if(root->get_right())
	{
		remove(Name, root->get_right());
	}
}	

//Iterative display call
void BST::display()
{
	if(!root)
	{
		cout << "No rentals!";
		return;
	}

	display(root);//Recursive function call
}

//Recursive display function
void BST::display(node * root)
{
	if(root)
	{
		cout << *root->get_data();
	}
	if(root->get_left())
	{	
		display(root->get_left());
	}
	if(root->get_right())
	{
		display(root->get_right());
	}
	return;
}

//Returns the left most node 
node * BST::in_order(node * curr)
{
	if(!curr->get_left())
	{
		return curr;
	}
	else
		in_order(curr->get_left());
}

//Retrieve a node from the BST
node * BST::retrieve(int Num)
{
	if(!root)
	{
		cout << "No rentals!";
	}

	return retrieve(Num, root);
}

//Recursive function for retrieving a node
node * BST::retrieve(int Num, node * root)
{

	if(*root->get_data() == Num)
	{
		cout << "We found an apartment with a matching price!" << endl;
		return root;
	}
	
	retrieve(Num, root->get_right());
	retrieve(Num, root->get_left());
		
}	

