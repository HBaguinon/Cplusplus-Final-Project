/*******************************************************************************
* NAME: HAROLD DANE C. BAGUINON                                                *
* DATE: 11/22/2014                                                             *
* DATE DUE: 12/01/2014 12:00:00 PM                                             *
* COURSE: CSC136 010                                                           *
* PROFESSOR: DR. SPIEGEL                                                       *
* PROJECT: #4                                                                  *
* FILENAME: WordRec.cpp                                                        *
* PURPOSE: This program is the part of the fourth assignment.                  *
*          It will help define the WordRec object with function definitions.   *
*          The function prototypes will be in the corresponding                *
*          WordRec.h header file.                                              *
*******************************************************************************/

// File: WordRec.cpp
// WordRec class implementation

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "WordRec.h"

using namespace std;

//WordRec Constructor
WordRec::WordRec(string word,int count)
{
  setWord(word);
  setCount(count);
}

//Sets

//Sets the WordRec data member word
void WordRec::setWord(string theWord)
{  word=theWord;
}

//Sets the WordRec data member count
void WordRec::setCount(int theCount)
{  count=theCount;
}

//Returns WordRec data member word
string WordRec::getWord() const
{
  return word;
}

//Return WordRec data member count
int WordRec::getCount() const
{
  return count;
}

//Operator ++ overload(Pre): Increments data member count
WordRec &WordRec::operator++()
{
  setCount(getCount()+1);
  return *this;
}

//Operator ++ overload(Post): Increments data member count
WordRec WordRec::operator++(int)
{
  WordRec temp=*this;
  setCount(getCount()+1);
  return temp;
}

//Operator -- overload (Pre): Decrements data member count
WordRec &WordRec::operator--()
{
  setCount(getCount()-1);
  return *this;
}

//Operator -- overload (Post): Decrements data member count
WordRec WordRec::operator--(int)
{
  WordRec temp=*this;
  setCount(getCount()-1);
  return temp;
}

//Operator () overload: Returns a substring of data member word
string WordRec::operator()(int number) const
{ return getWord().substr(0,number);
}

//Operator < overload: Returns whether a WordRec object's word is
//alphanumerically less than another WordRec's word
bool WordRec::operator<(const WordRec &right) const
{return (getWord()<right.getWord());}

//Operator <= overload: Returns whether a WordRec object's word is
//alphanumerically less than or equal to another WordRec's word
bool WordRec::operator<=(const WordRec &right) const
{return (getWord()<=right.getWord());}

//Operator > overload: Returns whether a WordRec object's word is
//alphanumerically greater than another WordRec's word
bool WordRec::operator>(const WordRec &right) const
{return (getWord()>right.getWord());}

//Operator >= overload: 
// Returns whether a WordRec's word is alphanumerically greater than or equal to another WordRec's word
bool WordRec::operator>=(const WordRec &right) const
{return (getWord()>=right.getWord());}
  
//Operator == overload: Returns whether a WordRec object's word is equal to
//another WordRec obeject's word
bool WordRec::operator==(const WordRec &right) const
{return(getWord()==right.getWord());}

//Operator != overload: Returns whether a WordRec object's word is not equal to
//another WordRec obeject's word
bool WordRec::operator!=(const WordRec &right) const
{return(getWord()!=right.getWord());}

//Operator << overload: Prints a WordRec object
ostream &operator<<(ostream &out, const WordRec &right)
{
  out<<setw(15)<<right.getWord()<<setw(15)<<right.getCount();
  return out;
}

//Operator <<= overload:Prints a WordRec object's word
ostream &operator<<=(ostream &stream, const WordRec &right)
{
  stream<<setw(15)<<right.getWord();
  return stream;
}

//Operator >> overload:Inputs file information into a WordRec object
ifstream &operator>>(ifstream &inf, WordRec &right)
{
  string nextWord;
  inf>>nextWord;
  right.setWord(nextWord);
  right.setCount(1);
  return inf;
}
