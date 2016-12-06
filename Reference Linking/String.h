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
    String* nextString;
    String* prevString;
public:
    String();
    ~String();
    String(String*);
    String(char* ,int);
    void append(char);
    int length() const;
    char charAt(int) const; 
    char* getBuff();
};


#endif	/* STRING_H */

