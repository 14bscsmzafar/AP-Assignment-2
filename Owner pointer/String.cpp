#include "StringBuffer.h"
#include "String.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor

String::String() {
    this->_str = new StringBuffer();
    this->isOwner = true;
    this->ownerPointer = NULL;
}
//destructor

String::~String() 
{	
	if (this->isOwner)
	{
		delete _str;
	}
}

//copy a const String into this string

StringBuffer* String::leaveOwnership()
{
	this->isOwner=false;
	StringBuffer* toReturn = this->_str;
	this->_str=NULL;
	return toReturn;
}
void String::assignOwner(String* newOwner)
{
	this->ownerPointer = newOwner;
}

char* String::getBuff() 
{
	if (this->isOwner)
	{
		return this->_str->getBuff();
	}
	else
	{
		return this->ownerPointer->getBuff();
	}
		
}

void String::takeOwneShip(StringBuffer* newBuff)
{
	if (!this->isOwner)
	{
		this->isOwner=true;
	}
	this->_str = newBuff;
	this->ownerPointer = NULL;
}

String::String(String* newString) 
{
		this->takeOwneShip(newString->leaveOwnership());
		newString->assignOwner(this);
}

//copy a char* into your string

String::String(char* newString, int length) 
{
    this->_str = new StringBuffer(newString, length);
    //increment the refcount by 1
    this->isOwner=true;
    this->ownerPointer=NULL;

}




void String::append(char c) {

    //    char* tempbuf = new char[this->_str->length()+1];
    //    this->_str->revSmartCopy(tempbuf);
    if (this->isOwner) 
	{
        auto_ptr<StringBuffer> newdata(new StringBuffer);
        newdata.get()->reserve(this->_str->length() + 1);
        newdata.get()->smartCopy(this->_str);
		
		delete this->_str;
        
        this->_str = newdata.release();
        
    	//copy the new character at the end of this string
    	this->_str->append(c);
    } 
	else
		cout << "OwnerShip exception should be thrown now when implemented!" << endl;

}

//get length of the string
int String::length() const {
	if (isOwner)
    	return this->_str->length();
    else
    	return this->ownerPointer->_str->length();
}

//get character at index if it is less than length

char String::charAt(int index) const 
{
    if (this->isOwner)
    {
    if (index < this->_str->length()) {
        return this->_str->charAt(index);
    } else {
        //throw new IndexOutOfBoundException();

    }
    }
    else
    {
        return this->ownerPointer->charAt(index);
    }
}
