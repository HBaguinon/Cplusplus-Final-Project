/*******************************************************************************
* NAME: HAROLD DANE C. BAGUINON                                                *
* DATE: 11/22/2014                                                             *
* DATE DUE: 12/01/2014 12:00:00 PM                                             *
* COURSE: CSC136 010                                                           *
* PROFESSOR: DR. SPIEGEL                                                       *
* PROJECT: #4                                                                  *
* FILENAME: WordRec.h                                                          *
* PURPOSE: This program is the header file for the fourth assignment.          *
*          It will help define the WordRec object and contain function         *
*			prototypes. The function definitions will be in the corresponding  *
*			WordRec.cpp file.                                                  *
*******************************************************************************/

// File: WordRec.h
// A WordRec holds a word and an int that can be used to track its multiplicity. 

#ifndef WORDREC_H
#define WORDREC_H
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class WordRec {
  public:

  // WordRec Constructor
  WordRec(string word="",int count=0);

  //Sets

  //Sets the WordRec data member word
  void setWord(string words);
  //Sets the WordRec data member count
  void setCount(int counts);

  //Gets

  //Returns WordRec data member word
  string getWord() const;
  //Returns WordRec data member count
  int getCount() const;

  //Operator ++ overload(Pre and Post): Increments data member count
  WordRec &operator++();
  WordRec operator++(int);

  //Operator -- overload (Pre and Post): Decrements data member count
  WordRec &operator--();
  WordRec operator--(int);

  //Operator () overload: Returns a substring of data member word
  string operator()(int number) const;

  //Operator < overload: 
  // Returns whether a WordRec's word is alphanumerically less than another WordRec's word
  bool operator<(const WordRec &right) const;

  //Operator <= overload: 
  // Returns whether a WordRec's word is alphanumerically less than or equal to another WordRec's word
  bool operator<=(const WordRec &right) const;

  //Operator > overload: 
  // Returns whether a WordRec's word is alphanumerically greater than another WordRec's word
  bool operator>(const WordRec &right) const;

  //Operator >= overload: 
  // Returns whether a WordRec's word is alphanumerically greater than or equal to another WordRec's word
  bool operator>=(const WordRec &right) const;

  //Operator == overload: 
  // Returns whether a WordRec's word is equal to another WordRec's word
  bool operator==(const WordRec &right) const;

  //Operator != overload: 
  // Returns whether a WordRec's word is not equal to another WordRec's word
  bool operator!=(const WordRec &right) const;

  
  private:

  //Contains a word from a file
  string word;
  //Contains the multiplicity of a word from a file
  int count;
};

//Operator << overload: Prints a WordRec object
ostream &operator<<(ostream &out, const WordRec &right);

//Operator <<= overload: Prints a WordRec object's word
ostream &operator<<=(ostream &stream, const WordRec &right);

//Operator >> overload: Inputs words from file into a WordRec object
ifstream &operator>>(ifstream &inf, WordRec &right);

#endif
