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

int selectionMenu();

int main(){
	LinkedChar * linkedChar = nullptr;

	while(true){
		int selection = selectionMenu();
		std::string input = nullptr;

		switch(selection){
			default:
				continue;

			case 0:
				std::cout << "Successfully exited program" << std::endl;
				return 1;

			case 1:
				//To prevent an endless number of LinkedChars from building up, we delete the current one and rewrite it
				delete(linkedChar);
				std::cout << "Please enter a string to rewrite or initialize the LinkedChar" << std::endl;
				std::getline(std::cin,input);
				linkedChar = new LinkedChar(input);
				break;

			case 2:
				std::cout << "The current length of the LinkedChar is: " << linkedChar->length() << std::endl;
				break;

			case 3:
				std::cout << "What character would you like to find?" << std:: endl;
				std::getline(std::cin, input);
				std::cout << "The index of " << input << " is: " << linkedChar->index(input[0]) << std::endl;
				break;

			case 4:
				std::cout << "Please enter a string to append to the end of the linkedChar" << std::endl;
				std::getline(std::cin, input);
				linkedChar->append(input);
				break;

			case 5:
				std::cout << "Please enter a string to test for submatch" << std::endl;
				std::getline(std::cin,input);
				std::cout << "Does the linkedChar contain: " << input << "? " << linkedChar->submatch(input);
				break;

			case 6:
				std::cout << std::endl;
				linkedChar->print();
				break;
		}
	}
}

int selectionMenu(){
	std::cout << "Please make a selection by entering the corresponding integer" << std::endl;
	std::cout << "	(0) To exit the program immediately" << std::endl;
	std::cout << "	(1) Enter or rewrite the working linkedChar string" << std::endl;
	std::cout << "	(2) Get current length of working LinkedChar" << std::endl;
	std::cout << "	(3) Find the index of a character in the working LinkedChar" << std::endl;
	std::cout << "	(4) Append a string onto the end of the working LinkedChar" << std::endl;
	std::cout << "	(5) Determine if a string is contained within the working LinkedChar" << std::endl;
	std::cout << "	(6) Display the current working LinkedChar" << std::endl;

	std::string inputString;
	std::getline(std::cin,inputString);
	return std::stoi(inputString);
}