#include "StringBuffer.h"
#include "String.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor

String::String() {
    this->_str = new StringBuffer();
    this->nextString=this;
    this->prevString=this;
}
//destructor

String::~String() {
	String* prev = this->prevString;
	String* next = this->nextString;
	if (this->nextString!=this)
	{
		prev->nextString=next;
		next->prevString= prev;
	}
	//else
	//{
	//	delete[] _str;
	//}
}

//copy a const String into this string

char* String::getBuff() 
{
	return this->_str->getBuff();
}

String::String(String* newString) 
{
    this->_str = newString->_str;
	
	this->nextString = newString;
	this->prevString= newString->prevString;
	this->prevString->nextString=this;
	newString->prevString =this;

}

//copy a char* into your string

String::String(char* newString, int length) {
    this->_str = new StringBuffer(newString, length);
    //increment the refcount by 1
    this->nextString = this;
    this->prevString = this;

}

void String::append(char c) {

    //    char* tempbuf = new char[this->_str->length()+1];
    //    this->_str->revSmartCopy(tempbuf);
    if (this->nextString != this) 
	{
        auto_ptr<StringBuffer> newdata(new StringBuffer);
        newdata.get()->reserve(this->_str->length() + 1);
        newdata.get()->smartCopy(this->_str);

        //decrement the reference count to this String
        String* next=this->nextString;
        String* prev=this->prevString;
        
        prev->nextString=next;
        next->prevString=prev;
        
        this->nextString=this;
        this->prevString=this;

        //cout<<"length at newdata"<<newdata.get()->length()<<endl;
        //now split the object instances
        this->_str = newdata.release();
    } else {
        this->_str->reserve(this->_str->length() + 1);
    }

    //copy the new character at the end of this string
    this->_str->append(c);

}

//get length of the string

int String::length() const {
    return this->_str->length();
}

//get character at index if it is less than length

char String::charAt(int index) const {
    if (index < this->_str->length()) {
        return this->_str->charAt(index);
    } else {
        //throw new IndexOutOfBoundException();

    }
}
