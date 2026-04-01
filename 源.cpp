#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* pre;
	Node* next;
	Node(int val = 0) :data(val), pre(nullptr), next(nullptr) {}
};
class douList {
private:
	Node* head;
	Node* tail;
	
public:
	douList() {
		head = new Node();
		tail=head;
		
		head->pre = head;
		head->next = head;
	};
	
	~douList() {
		if (head->next == head)return;
		Node* temp;
		Node* current=head->next;
		while (current != head) {
			temp = current->next;
			delete current;
			current = temp;
		}
		delete head;
	}
	void creatfromArry(int a[], int n) {
		for (int i = 0; i < n; i++) {
			Node* newNode = new Node(a[i]);
			newNode->pre = tail;
			newNode->next = head;
			
			head->pre = newNode;
			tail->next = newNode;
			tail = newNode;
			
		}
	}
	douList(int val) {
		head = new Node();
		tail = head;
		head->pre = head;
		head->next = head;
		// 插入第一个数据节点
		Node* newNode = new Node(val);
		newNode->pre = head;
		newNode->next = head;
		head->next = newNode;
		head->pre = newNode;
		tail = newNode;
	}

	void show() {
		if (head->next == head) { 
			cout << "链表为空" << endl;
			return; }
		Node* current = head->next;
		cout << "地址编号\t数值" << endl;
		int count = 0;
		while (current != head) {
			cout << current << "\t" << current->data << endl;
			count++;
			current = current->next;
		}
		cout << "size:" << count << endl;
	}
	void resever() {
		if (head->next == head)return;
		Node*temp;
		Node* current=head->next;
		while (current != head) {
			temp = current->next;
			current->next = current->pre;
			current->pre=temp;
			current = temp;
		}
		temp = head->next;
		head->next = head->pre;
		head->pre = temp;
	}

};
int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	douList L1;
	L1.creatfromArry(a, 10);
	cout << "\t逆置前\t" << endl;
	L1.show();
	L1.resever();
	cout << "\t逆置后\t" << endl;
	L1.show();
};