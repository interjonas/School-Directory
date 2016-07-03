#include <iostream>
#include <stdlib.h>
#include <string>
#pragma warning(disable: 4996)
using namespace std;

/****************** Forward Declarations ******************/
class container;
class person;
class student;
class athlete;
char a[32]="Constructor"; 
//I was having difficulties with string literals and char declarations, This is not needed, code compiles but it has warnings, that is why i declared these two variables
char b[32]="Constructor";

void branching(char c, container** pointerToHead);	// given
char* get_name();						// given
void printFirst(container* root);
void deleteOne(container** pointerToHead);


///////////////     CONTAINER   ///////////////////////////////////////////////

// A class for nodes of the linked list.
class container {
public:
    person *plink;	// points to a person object
    container *next;
    container(){
        plink = NULL;
        next = NULL;
    };
};

/////////////////////////////////////////////////////////////////////////////



///////////////////////////////     PERSON      /////////////////////////////////


// A class to hold attributes of a person
class person {
public:
    char *name;
    char *email;
    long phone;
    // constructor that uses the parameters to initialize the class properties
    person(char *cName, char *cEmail, long iPhone) {
        name = new (char[32]);	// acquiring memory for storing name
        email = new (char[32]); 	// acquiring memory for storing email
        strcpy(name, cName);		// initialize name
        strcpy(email, cEmail); 	// initialize email
        phone = iPhone; 		// initialize phone
    }
	virtual void display()
	{
		cout << "\nFirst Name:\t" << name << endl;
		cout << "Email:\t"<< email << endl;
		cout << "Phone:\t"<< phone << endl;
	};
    ~person() 
	{
		delete name;
		delete email;
		//delete phone;
		cout << "\n Destructor is Called - Object Destroyed\n";
        // write your destructor code here for Question 1
    }
};


////////////////////////////////////////////////////////////////////////////




//////////////////		STUDENT		/////////////////////////////////////////

class student:public person
{
	public:
	    double gpa;
	    char *program;
	    // constructor that uses the parameters to initialize the class properties
	    student(char *PointerProgram, long cGPA): person(a,b,0) 
		{
	        program = new (char[32]);	// acquiring memory for storing name
	        strcpy(program, PointerProgram);	// initialize name
	        gpa = cGPA; 		// initialize phone
	    }
	virtual void display()
		{
			person::display();
			cout << "Program: "<< program << endl;
			cout << "GPA:\t"<< gpa << endl;
		};
	    ~student() 
		{
			delete program;
			cout << "\n Destructor is Called - Object Destroyed\n";
	        // write your destructor code here for Question 1
	    }

};

////////////////////////////////////////////////////////////////////////////




////////////////////		ATHLETE		/////////////////////////////////////

class athlete:public student
{
	public:
	    char *sport;
	    // constructor that uses the parameters to initialize the class properties
	    athlete(char *PointerSport):student(a,0.0) 
		{
	        sport = new (char[32]);	// acquiring memory for storing name
	        strcpy(sport, PointerSport);		// initialize name
	    }
	virtual void display()
			{
				person::display();
				cout << "Sport:\t"<< sport << endl;
			};
	    ~athlete() 
		{
			delete sport;
			cout << "\n Destructor is Called - Object Destroyed\n";
	        // write your destructor code here for Question 1
	    }

};

////////////////////////////////////////////////////////////////////////////


//////////////////////      INSERTION       ////////////////////////////////

int insertion(container** pointerToHead)
{
    //int i = 0;
	char test1[32] ="Test";
	char test2[32] ="Test";
	container *newNode=new container;
	container*iterator1, *follower;
    person* newPerson=new person(test1,test2,0);
	student* newStudent=new student(test1,0.0);
	athlete* newAthlete=new athlete(test1);
    
    // Case 1: The program is out of memory.
    if (newNode == NULL)
    {
        printf("Fatal Error: Out of Memory. Exiting now.");
        return 0;
    }
    // Case 2: The structure still has unfilled slots.
    else
    {
		int userInput;
		do {
				cout << "Choose One of the Following:\n(1) Create New Person\n(2) Create New Student\n(3) Create New Athlete\n" <<endl;
				cin >> userInput;
				if (userInput< 1 || userInput > 3)
				{
					cout<<"Please enter a value from 1 to 3.\n"<<endl;
				}
			} while (userInput< 1 || userInput > 3);
		if (userInput==1)
		{
			        if (newPerson == NULL)
			        {
			            printf("Fatal Error: Out of Memory. Exiting now.");
			            return 0;
			        }
			        else
			        {
			            cout << "Enter the name:" <<endl;
			            cin >> newPerson->name;
			            cout << "Enter the phone number:" <<endl;
			            cin >> newPerson->phone;
			            cout << "Enter the e-mail:"<<endl;
			            cin >> newPerson->email;
			            newNode->plink = newPerson;
			            if (*pointerToHead == NULL)
			            {
			                *pointerToHead = newNode;
			                (*pointerToHead)->next = NULL;
			                return 0;
			            }
			            else
			            {
			                if (strcmp(newPerson->name, (*pointerToHead)->plink->name) < 0)
			                {
			                    newNode->next = *pointerToHead;
			                    *pointerToHead = newNode;
			                    return 0;
			                }
			                iterator1 = *pointerToHead;
			                follower = iterator1;
			                while (iterator1 != NULL)
			                {
			                    if (strcmp(newPerson->name, iterator1->plink->name) < 0)
			                    {
			                        newNode->next = iterator1;
			                        follower->next = newNode;
			                        return 0;
			                    }
			                    follower = iterator1;
			                    iterator1 = iterator1->next;
			                }
			                follower->next = newNode;
			                newNode->next = NULL;
			                return 0;
			            }
			        }
		}
		if (userInput==2)
				{
			        if (newStudent == NULL)
			        {
			            printf("Fatal Error: Out of Memory. Exiting now.");
			            return 0;
			        }
			        else
			        {
			            cout << "Enter the name:" <<endl;
			            cin >> newStudent->name;
			            cout << "Enter the phone number:" <<endl;
			            cin >> newStudent->phone;
			            cout << "Enter the e-mail:"<<endl;
			            cin >> newStudent->email;
						cout << "Enter the program:"<<endl;
						cin >> newStudent->program;
						cout << "Enter GPA:"<<endl;
						cin >> newStudent->gpa;
			            newNode->plink = newStudent;
			            if (*pointerToHead == NULL)
				            {
				                *pointerToHead = newNode;
				                (*pointerToHead)->next = NULL;
				                return 0;
				            }
			            else
				            {
				                if (strcmp(newStudent->name, (*pointerToHead)->plink->name) < 0)
			    	            {
				    	               newNode->next = *pointerToHead;
				        	            *pointerToHead = newNode;
				        	            return 0;
				                }
					            iterator1 = *pointerToHead;
					            follower = iterator1;
			             while (iterator1 != NULL)
			                {
			                    if (strcmp(newStudent->name, iterator1->plink->name) < 0)
			                    {
			                        newNode->next = iterator1;
			                        follower->next = newNode;
			                        return 0;
			                    }
					                    follower = iterator1;
					                    iterator1 = iterator1->next;
			                }
				                follower->next = newNode;
					                newNode->next = NULL;
					                return 0;
					            }
					        }
				}
				if (userInput==3)
				{
			       if (newAthlete == NULL)
			        {
			            printf("Fatal Error: Out of Memory. Exiting now.");
			            return 0;
			        }
			        else
			        {
			            cout << "Enter the name:" <<endl;
			            cin >> newAthlete->name;
			            cout << "Enter the phone number:" <<endl;
			            cin >> newAthlete->phone;
			            cout << "Enter the e-mail:"<<endl;
			            cin >> newAthlete->email;
						//cout << "Enter the program:"<<endl;
						//cin >> newAthlete->program;
						//cout << "Enter GPA:"<<endl;
						//cin >> newAthlete->gpa;
						cout << "Enter Sport:"<<endl;
						cin >> newAthlete->sport;
			           newNode->plink = newAthlete;
			            if (*pointerToHead == NULL)
			            {
			                *pointerToHead = newNode;
			                (*pointerToHead)->next = NULL;
			                return 0;
			            }
			            else
			            {
			                if (strcmp(newAthlete->name, (*pointerToHead)->plink->name) < 0)
			                {
			                    newNode->next = *pointerToHead;
			                    *pointerToHead = newNode;
			                    return 0;
			                }
			                iterator1 = *pointerToHead;
		 	               follower = iterator1;
			                while (iterator1 != NULL)
			                {
			                    if (strcmp(newAthlete->name, iterator1->plink->name) < 0)
			                    {
			                        newNode->next = iterator1;
			                        follower->next = newNode;
			                        return 0;
			                    }
			                    follower = iterator1;
			                    iterator1 = iterator1->next;
			                }
				                follower->next = newNode;
				                newNode->next = NULL;
				                return 0;
			            }
		        }
		}	

    }
    return 0;
}; 		
// Question 2

//////////////////////////////////////////////////////////////////////////



/////////////////////////       SEARCH      //////////////////////////////

container* search(container* root, char* sname)
{
    container* iterator1 = root;
    
    while (iterator1 != NULL)
    {
        if (strcmp(sname, iterator1->plink->name) == 0)
        {
            iterator1->plink->display();
            free(sname); // garbage collection
            return iterator1;
        }
        iterator1 = iterator1->next;
    }
    cout<<"The name does not exist.\n"<<endl;
    free(sname); // garbage collection
    return iterator1;
};// Question 3


/////////////////////////////////////////////////////////////////////////


//////////////////////      DELETE ONE       //////////////////////////

void deleteOne(container** pointerToHead)
{
    //int i = 0;
    container *toDelete = NULL;
    
    // Note: *pointerToHead gets the head of the list
    if (*pointerToHead == NULL)
    {
        cout<<"\nThe list is empty. Nothing was deleted.\n"<<endl;
    }
    // (*pointerToHead)->next is equivalent to saying head->next
    else if ((*pointerToHead)->next == NULL)
    {
        free((*pointerToHead)->plink);
        free(*pointerToHead);
        *pointerToHead = NULL;
		cout<<"\nThe sole container node was deleted. List is now empty.\n"<<endl;
    }
    else
    {
        toDelete = *pointerToHead;	// toDelete = head;
        *pointerToHead = (*pointerToHead)->next; //head = head->next;
        free(toDelete->plink);
        free(toDelete);
        toDelete = NULL;
        cout<<"\nA containder node was deleted.\n"<<endl;
    }
    
};


///////////////////////////////////////////////////////////////////////////////////




/////////////////////       DELETE ALL      /////////////////////////////////

void deleteAll(container** pointerToHead)
{
    container* pnext;
    pnext = *pointerToHead;
    // if (head == NULL)
    if (*pointerToHead == NULL)
    {
        return;
    }
    else
    {
        deleteAll(&(*pointerToHead)->next);
        deleteOne(pointerToHead);
    }
}; 		// Question 4

////////////////////////////////////////////////////////////////////////



///////////////////     PRINT ALL   /////////////////////////////////

void printAll(container* root)
{
    
    container* iterator1 = root;
    
    //Case 1: The structure is empty
    if (iterator1 == NULL)
    {
        cout<<"\nNo entries found.\n"<<endl;
        return;
    }
    // Case 2: The structure has at least one item in it
    else
    {
        printFirst(root);
        return;
    }
}		// Question 5

/////////////////////////////////////////////////////////////////


///////////////     MAIN    ///////////////////////////////////

int main()
{
    container* head = NULL; // Declare head as a local variable of main function
    // Print a menu for selection
    char ch = 'i';
    do {
        cout<< "Enter your selection" << endl;
        cout<< "\ti: insert a new entry" << endl;
		cout<< "\td: delete one entry" << endl;
        cout<< "\tr: delete all entries" << endl;
        cout<< "\ts: search an entry" << endl;
        cout<< "\tp: print all entries" << endl;
        cout<< "\tq: quit" << endl;
        cin >> ch;
        ch = tolower(ch);	// Convert any uppercase char to lowercase.
        branching(ch, &head);
        cout << endl;
    } while (ch != 'q');
    return 0;
};

///////////////////////////////////////////////////////////////


/////////////     BRANCHING       //////////////////////////////////

// Branch to different tasks: insert a person, search for a person, delete a person
// print all added persons.
void branching(char c, container** pointerToHead)
{
    char *p;
    switch (c) {
        case 'i':
            insertion(pointerToHead);
            break;
        case 's':
            p = get_name();
            search(*pointerToHead, p);
            break;
		case 'd':
			deleteOne(pointerToHead);
			break;
        case 'r':
            deleteAll(pointerToHead);
            break;
        case 'p':
            printAll(*pointerToHead);
            break;
        case 'q':
            deleteAll(pointerToHead); // free all memory
            break;
        default:
            printf("Invalid input\n");
    }
};

////////////////////////////////////////////////////////////////////




////////////////    GET NAME    ////////////////////////////////////////////////////


// Read the input from the user.
char * get_name()
{
    char *p = new(char[32]); // Use dynamic memory which does not go out of scope
    cout << "Please enter a name for the search: " <<endl;
    cin >> p;
    return p;
};

///////////////////////////////////////////////////////////////////////////////////



//////////////      PRINT FIRST     /////////////////////////////////////////////
void printFirst(container* root)
{
    if (root != NULL)
    {
        root->plink->display();
		root=root->next;
		printFirst(root);
    }
};
///////////////////////////////////////////////////////////////////////////////