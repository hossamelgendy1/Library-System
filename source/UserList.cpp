// Copyrights go to Modaser Abdelhamid and Hossam Elgendy from FCAI-CU.

#include "UserList.h"

// Default constructor: gives member variables default values.
UserList::UserList():capacity(0), usersCount(0)
{
}

// parameterized constructor: allocates users array with the given capacity.
UserList::UserList(int capacity)
{
	this->capacity = capacity;
	if (capacity <= 0)
	{
		cout << "ERROR: Invalid size.\n";
		exit(0);
	}
	users = new User[capacity];
	usersCount = 0;
}

// this function adds a user to the end of the array.
// this function does not set the id of users in the userList as the id is given when initializing the users array in the constructor
void UserList::addUser(User user)
{
	if (usersCount < capacity) // to check if there is storage to add the user
	{
		users[usersCount].setName(user.getName());
		users[usersCount].setAge(user.getAge());
		users[usersCount].setEmail(user.getEmail());
		users[usersCount].setPassword(user.getPassword());
		usersCount++;
	}
	else
	{
		cout << "*Can't add this user to the list (Reached full capacity)*\n";
	}
}

// searches for a user by name 
// returns a pointer to the wanted user if found. If not, returns a nullptr.
User* UserList::searchUser(string name)
{
	for (int i = 0; i < usersCount; i++)
	{
		if (users[i].getName() == name)
			return &users[i];
	}
	return nullptr;
}

// searches for a user by ID 
// returns a pointer to the wanted user if found. If not, returns a nullptr.
User* UserList::searchUser(int id)
{
	for (int i = 0; i < usersCount; i++)
	{
		if (users[i].getId() == id)
			return &users[i];
	}
	return nullptr;
}

// deletes a user from the userList
void UserList::deleteUser(int id)
{
	int deletedIndex = 0;
	for (int i = 0; i < usersCount; i++) //to iterate on all users
	{
		if (users[i].getId() == id) //to find the wanted user
		{
			users[i] = NULL; //this uses the overloaded operator= to set all members of the user to the default values.
			deletedIndex = i; //used to shift the users to the left if the deleted user isn't at the end of the array.
			break;
		}
	}
	if (deletedIndex < usersCount - 1) //the last index of the array = usersCount - 1
	{
		for (int i = deletedIndex; i < usersCount - 1; i++)
		{
			users[i] = users[i + 1];
			users[i].setId(users[i].getId() - 1); // To keep the ID incremental by 1 in the list, and avoid gaps when shifting all the users to the left.
		}
		users[usersCount - 1] = NULL;
	}
	usersCount--;
}

//destructor: frees the memory that was dinamically allocated in the constructor
UserList::~UserList()
{
	delete[] users;
}

// this function overloads the "<<" operator, so that we can use the "cout" function to print the UserList.
ostream& operator<<(ostream& output, UserList& userList)
{
	for (int i = 0; i < userList.usersCount; i++)
	{
		output << userList.users[i];
	}
	return output;
}
