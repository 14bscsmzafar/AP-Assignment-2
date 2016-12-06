/* 
 * File:   String.h
 *
 * Created on February 18, 2016, 6:17 PM
 */
#include <iostream>

#ifndef STRING_H
#define	STRING_H

class String{
private:
    StringBuffer* _str;
    bool isOwner;
    String* ownerPointer;
    
    
    void assignOwner(String*);
    StringBuffer* leaveOwnership();
    void takeOwneShip(StringBuffer*);
public:
    String();
    ~String();
    String(String*);
    String(char* ,int);
    void append(char);
    int length() const;
    char charAt(int) const; 
    char* getBuff();
    //friend class String; //Making it it's friend so it can call it's leaveOwnership and assignOwner
};


#endif	/* STRING_H */

