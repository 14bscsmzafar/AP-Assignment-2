#Smart Pointer Strings

Source files of the following implementations are placed in their respective folders:

	Reference Linking with COW	
	Reference Counting with COW
	Owned
	Copied

____________________
##How to run
____________________

###Windows

Compile the main.cpp file in from a folder and execute the file compiled. You will be greeted with a random string of 3 different sizes.

**Note: Please don't use String::getBuff() in windows as cout with char* array was including grabage values after the real string (due to the missing '\0' charactor at the end, suprisingly, it was working on linux g++ correctly). 

###Linux g++

Same as above except remove system("pause") at the end and replace it with the following code:
:    cout << "Press any key to continue ..." << endl;
:    cin.get();

___________________
##Additional Functions
____________________

###String::getBuff(), StringBuffer::getBuf()

	This function simply returns the char pointer to the array the object is currently pointing to. It was implemented just to print the strings without the hasle of looping using charAt()

___________________
##Implementation Specific Functions
___________________

###Reference Linking with COW
	Constructors/Destructors:
	
		1. String::String()
		The pointers for next and previous String objects were pointed to the current object to simplify the logic. (Aplicable to all other constructors

		2. String::~String()
		If statement checks if the nextString and prevString pointers are pointing to the current object (which means it is the only one left), then delete the _str object.

	String::append()
	
		A new StringBuffer object was initialized and the current  object was removed from the reference chain. If it was the only one left, the StringBuffer object was directly modified.

###Owned

	Additonal functions:
		1. StringBuffer* String::leaveOwnership()
		This is used to remove the ownership of the StringBuffer object from the current String object. It further nullifies the _str pointer and sets isOwner to false. A reference to the StringBuffer object is returned (which must be assigned to a new owner otherwise memory leak would occur.

		2. void String::assignOwner(String*)
		This function assigns a new owner to the current object. It just assigns the reference passed into it to the owenerPointer.
		
		3. void String::takeOwneShip(StringBuffer*)
		This function makes the current object the owner by taking the reference from the arguments and assigning it to _str. It also sets isOwner to true.
	
	Constructors/Destructors:
		1. String::~String()
		If the object is owner, the StringBuffer is deleted.

	String::append()
		If the object is owner, the StringBuffer gets modified otherwise a exception IS PLANNED to be thrown.

	String::getBuff() and String::charAt(int)
		If the object is not owner, it uses ownerPointer to get the to the StringBuffer class. Same is aplicable to charAt.


###Copied

	Identical to owned except a deep copying everytime.

______________
##Profiling
______________

Output of profiled data is placed in the profiling folder. In these folder, are sub directeries named with the implementation. In each directory, are 6 screenshots of profiling output. The strings were used:

>small = "asd",
>medium = "hello",
>long = "thisisalongstring"

For each implementation, these tests were performed:

>CPU usage,
>Memory usage
