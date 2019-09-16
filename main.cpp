#include <iostream>
#include <string>

class CharNode{
private:
	char data;
	CharNode *nextNode;

public:
	CharNode(char inputChar):data(inputChar), nextNode(nullptr){}
	CharNode();

	char getData() const {
		return data;
	}

	void setData(char inputData) {
		this->data = inputData;
	}

	CharNode *getNextNode() const {
		return nextNode;
	}

	void setNextNode(CharNode *inputNextNode) {
		this->nextNode = inputNextNode;
	}

};

class LinkedChar{
private:
	CharNode *head;

	CharNode * getNodeAt(int index){
		CharNode * traversalNode = head;
		int count = 0;

		while(traversalNode != nullptr){
			if(count == index){
				return traversalNode;
			}

			count++;
			traversalNode = traversalNode->getNextNode();
		}

		return nullptr;
	}

public:
	LinkedChar(){

	}

	LinkedChar(std::string s){
		head = new CharNode(s[0]);
		CharNode *traversalNode = head;

		for(int i = 1; i < s.length(); i++){
			CharNode *foo = new CharNode(s[i]);
			traversalNode->setNextNode(foo);
			traversalNode = foo;
		}
	}

	int length() const{
		int count = 0;
		CharNode *traversalNode = head;

		while(traversalNode != nullptr){
			traversalNode = traversalNode->getNextNode();
			count++;
		}

		return count;
	}

	int index(char ch) const{
		int charIndex = 0;
		CharNode *traversalNode = head;

		while(traversalNode != nullptr){
			if(traversalNode->getData() == ch){
				return charIndex;
			}

			charIndex++;

			traversalNode = traversalNode->getNextNode();
		}

		return -1;
	}

	//Delete before submission
	void print(){
		CharNode * traversalNode = head;
		std::cout << "The contents are:";

		while(traversalNode != nullptr){
			std::cout << " " << traversalNode->getData();

			traversalNode = traversalNode->getNextNode();
		}

		std::cout << std::endl;
	}

	void append(const LinkedChar& lc){
		/*
		CharNode * traversalNode = this->getNodeAt(this->length());
		traversalNode->setNextNode(lc.head);
		//Please call ~LinkedChar at the end of this method
		 */

		CharNode * traversalNode = this->getNodeAt(this->length() - 1);
		CharNode * lcTraversalNode = lc.head;

		while(lcTraversalNode != nullptr){
			CharNode * tempNode = new CharNode(lcTraversalNode->getData());

			traversalNode->setNextNode(tempNode);
			traversalNode = tempNode;

			lcTraversalNode = lcTraversalNode->getNextNode();
		}
	}

	bool submatch(const LinkedChar& lc){
		CharNode * traversalNode = head;
		CharNode const * lcTraversalNode = lc.head;
		int lcLength = lc.length();
		int count = 0;

		while(traversalNode != nullptr){
			//if they match
			if(traversalNode->getData() == lcTraversalNode->getData()){
				count++;
				//if we get all the correct letters in sequence we are finished
				if(count == lcLength){
					return true;
				}

				traversalNode = traversalNode->getNextNode();
				lcTraversalNode = lcTraversalNode->getNextNode();
			}

			//We didn't find a match
			else{
				count = 0;

				lcTraversalNode = lc.head;
				//However we gotta see if the current letter matches the first one like this: udder : der
				if(traversalNode->getData() == lcTraversalNode->getData()){
					count++;
					lcTraversalNode = lcTraversalNode->getNextNode();
				}

				traversalNode = traversalNode->getNextNode();
			}
		}

		return false;
	}

};

int main(){
	std::cout << "Please input a string of characters." << std::endl;

	std::string inputString;
	std::string inputAppendString;

	std::getline(std::cin,inputString);

	LinkedChar * list = new LinkedChar(inputString);

	list->print();

	std::cout << "The length of the string is : " << list->length() << std::endl;
	std:: cout << "The position of 'a' is: " << list->index('a') << std::endl;

	std::cout << "Please input another string to append: " << std::endl;
	std::getline(std::cin, inputString);
	LinkedChar * listAppend = new LinkedChar(inputString);
	list->append(*listAppend);
	std::cout << "After appending, the new list is: ";
	list->print();
	std::cout << "Please enter a substring to search for: " << std::endl;
	std::getline(std::cin,inputString);
	LinkedChar * listSubMatch = new LinkedChar(inputString);
	std::cout << "Does the string contain a match?: " << list->submatch(*listSubMatch) << std::endl;

}
