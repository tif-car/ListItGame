#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(int initialData){
    data = initialData;
    next = nullptr;
  }
};

class LinkedList{
  private:
  Node* head;
  Node* tail;

  public:
  LinkedList(){
    head = nullptr;
    tail = nullptr;
  }
  void Append(Node* newNode);
  void Prepend(Node* newNode);
  void InsertAfter(Node* currentNode, Node* newNode);
  void Print();
  

};

 void LinkedList::Append(Node* newNode){
  if (head == nullptr){
    head = newNode;
    tail = newNode;
  }
  else {
    tail->next = newNode;
    tail = newNode;
  }
    
} //end of append function

void LinkedList::Prepend(Node* newNode){
  if(head == nullptr){
    head = newNode;
    tail = newNode;
  }
  else {
    newNode->next = head;
    head = newNode;
  }
}//end of prepend function

void LinkedList::InsertAfter(Node* currentNode, Node* newNode){
  if(head == nullptr) {
    head = newNode;
    tail = newNode;
  }
  else if(currentNode == tail){
    tail->next = newNode;
    tail = newNode; 
  }
  else {
    newNode->next = currentNode->next;
    currentNode->next = newNode;
  }
}

void LinkedList::Print(){
  Node* currentNode = head;

  while(currentNode){
    cout << currentNode->data << endl;
    currentNode = currentNode->next;
  }
} //end of print function

int computerGuess(){
  int guess = rand() % 11;
  return guess;
}

int main(){
  LinkedList newlist;
  char game;
  cout << "List It is a game where you need to guess 10 numbers from 1-10" << endl;
  cout << "If the computer guesses the same number as you, you lose" << endl;
  cout << "You need to create a list of 10 numbers before the computer guesses your number" << endl;
  cout << "Want to play list it? (y/n)" << endl;
  cin >> game;

  game = tolower(game);

  if(game == 'y') {
    int playerCorrectGuess = 0;
    int computerCorrectGuess = 0;

    while(playerCorrectGuess < 10 && computerCorrectGuess < 10){
      int value;
      cout << "Enter a number between 1 and 10: ";
      cin >> value;

      int guess = computerGuess();
      cout << "The computer guessed: " << guess << endl;

      if(value != guess){
        Node* newNode = new Node(value);
        newlist.Append(newNode);

        cout << "Your Current List:" << endl;
        newlist.Print();
      }

        else {
        cout << "Sorry, you lost" << endl;
        cout << "GAME OVER" << endl;
        break;
        }

      if(playerCorrectGuess == 10){
        cout << "Congratulations, you won!" << endl;
      }//end of if statement
    }
  }

   return 0;
  
} //end of main function
