#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class Node
{
  public:
   T data;
   Node<T>* next;
};

template <class T>
class List {
 private:
  Node<T> * head;
  int size;
 public:
	 List() : head(NULL) {}
	 ~List() { }
	 List(T* arr, int n_nodes) {
	  Node<T>** iter = &this->head;
	  for (int i = 0; i < n_nodes; i++) {
		  *iter = new Node<T>;
		  (*iter)->data = arr[i];
		  (*iter)->next = NULL;
		  iter = &((*iter)->next);
	  }

	  /* Is there a way like this?
	  Node<T>*& iter = this->head;
	  for (int i = 0 ; i < n_nodes; i++ ){
	   iter = new Node<T>;
	   iter->data = arr[i];
	   iter->next = NULL;
	   &iter = &(iter->next);
	  }
	  */
	  size = n_nodes;

  }
  void insert_at(int idx, const T& data) {
	  Node<T>* new_node = new Node<T>;
	  new_node->data = data;//?
	  new_node->next = NULL;
	  
	  int count = 0;

	  Node<T> * iter = this->head;
	  while (iter->next!=NULL) {
		  if (count == idx - 1) {
			  new_node->next = iter->next;
			  iter->next = new_node;
			  size++;
		  }
		 
		  else {
			  iter = iter->next;
		  }
		  count++; 
	  }
  }
  void remove_at(int idx) {
	  int count = 0;
	  Node<T> * iter = this->head;
	  Node<T> * target_iter = this->head->next;

	  while (idx--) {
		  if (count == idx) {
			  iter->next = target_iter->next;
			  delete target_iter;
			  size--;
		  }

		  else {
			  iter = iter->next;
			  target_iter = target_iter->next;
		  }

		  count++;
	  }

	  
	  
  }
  void pop_back() {
	  int count = 0;
	  Node<T> * iter = this->head;

	  while (1) {
		  iter = iter->next;
		  if (iter == NULL) {
			  break;
		  }
		  
		  count++;
	  }
	

	  int check = 0;
	  Node<T> * iter2 = this->head;
	  Node<T> * temp;
	  while (iter2) {
		  
		  //cout << iter2->data << endl;
		  if (check == count-1) {
			  temp = iter;
			  iter2->next = NULL;
			  delete temp;
			  //iter2->next = NULL;
		  }
		  else {
			  iter2 = iter2->next;
		  }
		  check++;
		 
	  }
	  size--;
  }
  void push_back(const T& val) {
	  Node<T>* new_node = new Node<T>;
	  new_node->data = val;
	  new_node->next = NULL;

	  Node<T> * iter = this->head;
	  //Node<T> * temp;
	  while (iter->next!=NULL) {
		  iter = iter->next;
	  }
	  iter->next = new_node;
	  size++;
  }
  void pop_front() {
	  Node<T>* second_iter = this->head->next;
	  this->head = second_iter;
	  size--;
  }
  
  void push_front(const T& val) { // insert const keyword cuz of rvalue problem
	Node<T>* new_node = new Node<T>;
	new_node->data = val;
	new_node->next = this->head;
	this->head = new_node;
	size++;
  }
  friend ostream& operator<<(ostream& out , List& rhs) {
   Node<T> * iter = rhs.head;
   int count = 0;
   while (iter){
	  if (count == rhs.size-1) {
		  out << iter->data ;
		  iter = iter->next;
	  }
	  else {
		  out << iter->data << ",";
		  iter = iter->next;
	  }
	  count++;
   }
   return out;
  }

};