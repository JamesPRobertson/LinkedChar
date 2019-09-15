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

	int length(){
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
			charIndex++;

			if(traversalNode->getData() == ch){
				return charIndex;
			}

			traversalNode = traversalNode->getNextNode();
		}

		return -1;
	}

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

	}

	bool submatch(const LinkedChar& lc){

	}

};

int main(){
	std::cout << "Please input a string of characters." << std::endl;

	std::string inputString;

	std::getline(std::cin,inputString);

	LinkedChar * list = new LinkedChar(inputString);

	list->print();

	std::cout << "The length of the string is : " << list->length() << std::endl;
	std:: cout << "The position of 'a' is: " << list->index('a') << std::endl;
}
