#include <iostream>
#include <cstdlib>
using namespace std;

typedef char ItemType;

struct Node{ //Node 구조체 정의
	ItemType info; //노드의 값
	Node* next; //노드의 주소(위치)
};

class Stack{ //연결리스트로 스택 정의
	Node* topPtr; //첫번째 노드를 가리키는 포인터
public:
	Stack(); //스택 생성자
	~Stack(); //스택 소멸자
	bool is_empty(); //스택이 비어있는지 판단
	//bool is_full();
	void push(ItemType item); //원소 삽입
	ItemType pop(); //원소 삭제하고 반환
};

int main(){
	Stack s;

	s.push('a');
	s.push('b');
	s.push('c');

	while(!s.is_empty()){
		cout<<s.pop()<<endl;
	}

	return 0;
}

Stack::Stack(){
	topPtr = NULL;
}

Stack::~Stack(){
	while(!is_empty())
		pop();
}

bool Stack::is_empty(){
	return topPtr == NULL;
}

void Stack::push(ItemType item){
	Node* newNode;
	newNode = new Node;
	newNode->info = item;
	newNode->next = topPtr; //처음 생성되는 것이라면 newNode->next=NULL
	topPtr = newNode;
}

ItemType Stack::pop(){
	if(is_empty()){
		cout<<"Stack is full"<<endl;
		exit(1);
	}
	else{
		ItemType item;
		Node* tempPtr;
		item = topPtr->info;
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
		return item;
	}
}
