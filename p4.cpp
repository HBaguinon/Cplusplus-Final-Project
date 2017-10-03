// File: p4.cpp
// Prepared by Dr. Spiegel with thanks to Jamie Mason
// Application to test out the functionality of the LinkedList class
// Permits user to print in several ways and 
//	remove words read in from a file and stored with their multiplicity

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "LinkedList.h"
#include "WordRec.h"

using namespace std;

// Saves a lot of redundant typing.
typedef LinkedList<WordRec> WordList;  

//Function prototype of function that opens the file
bool openFile(ifstream &inf);

//Function prototype of function that displays the prompt asking for a character 
char menu();

//Function prototype of function that displays the prompt asking for a number
int numberPrompt();

//Function prototype of function that displays the prompt asking for a string
string stringPrompt();

//Function prototype of function that searches for a word from the file that
//is the same as the one the user input
void find(const WordList &TheWords);

// Output the first n characters of each word
void substring(const WordList &TheWords);
       
//Print the words from the file with the passed in multiplicity
void mult(const WordList &TheWords);

//For number<--n.m, print the first m characters of words that appeared n times
void multMchars(const WordList &TheWords);

// Remove occurrences of a word in the list
void removeWord(WordList &TheWords);

//Function prototype of function that regulates the output based on user input
void regulateOutput(WordList &TheWords);

//Inputs file into the WordRecs
// ***************** Insert prototype here *******************************

int main()
{
  //Variable that contains the data from the file
  ifstream inf;
  //Variable that holds the character the the user input
  char character;
  //Variable that contains a true/false value pertaining to whether the 
  //function was opened or not
  bool result;
  //Instantiate a WordList object
  LinkedList<WordRec> TheWords;
  //Open File
  result=openFile(inf);
  //Output if the file does not exist
  if(!result)
    {
      cout<<"Error:File does not exist.\n";
      return 0;
    }
  //Input file information into thew WordList
  inf >> TheWords;
  //Regulate Output
  regulateOutput(TheWords);
  //Close the file
  inf.close();
  return 0;
}

//Functions

//Opens the file
bool openFile(ifstream &inf)
{ //Variable to hold the file name
  string filename;
  //Ask for File Name
  cout<<"Enter the data file name >";
  cin>>filename;
  inf.open(filename.c_str());
  return(inf);
}

//Prompt asking for a character
char menu()
{
  char SelectedCharacter;
  cout<<"\n";
  cout<<"A)ll Words in File with their Multiplicity."<<endl;
  cout<<"P)rint all Words Appearing N Times"<<endl;
  cout<<"S)ubstring: First N letters of Each Word"<<endl;
  cout<<"F)ind a Word "<<endl;
  cout<<"M)Characters of Words Appearing N Times"<< endl;
  cout<<"Q)uit"<<endl;
  cin>>SelectedCharacter;
  return SelectedCharacter;
}

//Prompt asking for a number
int numberPrompt()
{
  int numberValue=0;
  cout<<"\n";
  cout<<"Enter an integer value >";
  cin>>numberValue;
  return numberValue;
}

//Prompt asking for a string
string stringPrompt()
{ string word;
  cout<<"\n";
  cout<<"Enter a word >" ;
  cin>>word;
  return word;
}

//Searches for a word from the file using the iterator interface in the WordList
void find(const WordList &TheWords)
{ string findWord=stringPrompt();
  listItr<WordRec> it(TheWords);
  bool found=false;
  cout << endl;
  for (it.start();it.more();it.next())
    { 
      if (it.value().getWord()==findWord)
	{
	  cout<< it.value().getWord() << " appeared " << 
				it.value().getCount() << " times in the file\n";
	  found=true;
	}
    }
    if (!found)
      cout<<"The word " << findWord <<" does not exist in the file." << endl;
}
 
//Outputs substrings
void substring(const WordList &TheWords)
{ int number=numberPrompt();
  while (number<=0)
    {
      cout<<"\n";
      cout<<"Error: Invalid Entry"<<endl;
      number=numberPrompt();
    }
  listItr<WordRec> it(TheWords);
  cout<<"\n";
  cout<<"Substring:\n\n";
  cout<<setw(15)<<"Words"<<endl;
  for (it.start();it.more();it.next())
    cout<< setw(15) << it.value()(number) << endl;
}
       
//Print the multiplicity of the words from the file
void mult(const WordList &TheWords)
{ int number=numberPrompt();
  while (number<=0)
    {
      cout<<"\n";
      cout<<"Error: Invalid Entry"<<endl;
      number=numberPrompt();
    }
  listItr<WordRec> it(TheWords);
  bool print=false;
  for (it.start();it.more();it.next())
    {
      if (it.value().getCount()==number)
	{
	  if(!print)
	    {
	      cout<<"\n";
	      cout<<"Words appearing "<<number<<" times:\n\n";
	      cout<<setw(15)<<"Words"<<endl;
	      print=true;
	    }
	  cout<<it.value() << endl;
	}
    }
  if(!print)
    {
      cout<<"\nNo word in the file has this multiplicity.\n";
    }
}
 
//Print the multiplicity of the words from the file
void multMchars(const WordList &TheWords)
{ listItr<WordRec> it(TheWords);
  double number;
  cout << "Enter double in form n.m >";
  cin >>  number;
  int mult=int(number),numChars=((number+0.001-mult)*10);
  bool print=false;
  for (it.start();it.more();it.next())
    {
      if (it.value().getCount()==mult)
	{
	  if(!print)
	    {
	      cout<<"\n";
	      cout<<"First "<<numChars<<" characters of words appearing "<<mult<<" times:\n";
	      cout<<setw(15)<<"Words"<<endl;
	      cout<<"\n";
	      print=true;
	    }
	  cout<<setw(15)<<it.value()(numChars) << endl;
	}
    }
  if(!print)
    {
      cout<<"\n";
      cout<<"No word in the file has this multiplicity.";
    }
}

// Find a word in the list. Return how many times it was added, 0 if not found.
WordRec* findWordInList(const WordList &TheWords,string word)
{ listItr<WordRec> it(TheWords);
  bool flag=false;
  for (it.start();it.more();it.next())
    if (it.value().getWord()==word)
      return(&it.value());		// Return a pointer to the found WordRec
  return(0);				// Return NULL
}

// ********************** Must complete this function *******************
// Remove occurrences of a word in the list
void removeWord(WordList &TheWords)
{ string word;
  cout << "\n";
  cout << "Enter the Word to Remove >";
  cin >> word;
}

//Regulates the output based on user input
void regulateOutput(WordList &TheWords)
{ int number;
  string wordFind;
  char inputCharacter=menu();
  while (inputCharacter!='Q' && inputCharacter!='q')
    {
      switch(inputCharacter)
	{
	case 'a':
        case 'A':
          cout << setw(15) << "Word" << setw(18) << "Appearances\n" << TheWords;
          break;
        case 'p':
        case 'P':
	  mult(TheWords);
          break;
	case 's':
	case 'S':
	  substring(TheWords);
	  break;
        case 'f':
        case 'F':
	  find(TheWords);
          break;
	case 'M':
	case 'm':
	  multMchars(TheWords);
	  break;
        default:
	  cout<<"\n";
          cout<<"Error: Invalid Entry"<<endl;
          break;
        }
      inputCharacter=menu();
    }
}

// *************** Must write AND prototype this function *******************
// Inputs file into the WordRecs 
// If the word read is present, orderedInsert returns a pointer to its WordRec. 
//  In that case, the word was NOT inserted. We increment the Word's counter. 
