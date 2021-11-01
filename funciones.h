/*
 *Proyecto Integral A
 *Jorge Guerrero Díaz
 *A01411752
 *20/09/2021
*/

/*
 * Sorts
 * Archivo para ordenamiento de vectores con sus funciones pertinentes
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#ifndef sorts_h
#define sorts_h
using namespace std;

template <class T>
class Sorts{
	//Declaracion de funciones
    private:
     void swap(vector<T> &, int,int);
    public:
     void ordenaBurbuja( vector<T>&);
	

};
/*
 * swap 
 * @param vector:&v, int:posicion, int: posicion
 * @return
*/
template <class T>
void Sorts<T>::swap(vector<T> &v , int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
};
/*
 * ordenaBurbuja  
 * @param vector:&v
 * @return
*/
template <class T>
void Sorts<T>::ordenaBurbuja( vector<T>&v){
	for (int i= v.size()-1; i> 0; i--){
		for (int j=0; j<i; j++)
		if (v[j]>v[j+1]){
			swap(v,j,j+1);
		}
	}

};

template <class T> class List;
template <class T> class ListIterator;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next;

	friend class List<T>;
	friend class ListIterator<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}

template <class T>
class List {
public:
	List();
	List(const List<T>&) ;
	~List();
	void clear();
	std::string toString() const;
	void insertion(string);
    int length() const;
	bool empty() const;
	void addFirst(T);
	int search(string);
	void update(int,string);
	int deleteAt(int);
private:
	Link<T> *head;
	int 	size;

	friend class ListIterator<T>;
};
template <class T>
void List<T>::clear() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}
template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
int List<T>::length() const {
	return size;
}
template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
	clear();
}
template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
void List<T>::addFirst(T val) {
	Link<T> *newLink;

	newLink = new Link<T>(val);
	if (newLink == 0) {
		cout<<"OutOfMemory";
	}
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::insertion(string val){
	Link<T> *newLink, *p;

	newLink = new Link<T>(val);
	if (newLink == 0) {
		cout<<"OutOfMemory";
	}
	if (empty()) {
		addFirst(val);
		return;
	}
	p = head;
	while (p->next != 0) { //buscar el final
		p = p->next;
	}
	newLink->next = 0;
	p->next = newLink;
	size++;
}
template <class T>
int List<T>::search(string val){
	Link <T> *p;
	p=head;
	int pos=0;
	int contador=0;
	while (contador != size){
		if (p->value==val){
			pos=contador;
			return pos;
		}else{
			pos=-1;
		}
		contador=contador+1;
		p=p->next;
		
	}
	return pos;
}
template <class T>
void List<T>::update(int pos,string val){
	Link <T> *p;
	p=head;
	int contador=0;
	while (contador != size){
		if (contador==pos){
			p->value=val;
		}
		contador=contador+1;
		p=p->next;
	}
}
template <class T>
int List<T>::deleteAt(int pos){
	Link <T> *p;
	T val;
	p = head;
	int contador=0;
	while (contador !=size){
		head = p->next;
		if (contador==pos){
			val=p->value;
			delete p;
			size--;
		}
		contador=contador+1;
	}
	return val;

}

////////////////////////////

template <class T> class BST;

template <class T>
class Node {
private:
	T value;
	Node *left, *right;
    int level,balance;
	Node<T>* succesor();

public:
	Node(T);
	Node(T, Node<T>*, Node<T>*,int);
	void add(T);
	bool find(T);
	void remove(T);
	void removeChilds();
	void inorder(std::stringstream&) const;
};
template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0),level(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri,int lev)
	: value(val), left(le), right(ri), level(lev) {}

template <class T>
void Node<T>::add(T val) {
	if (val < value) {
		if (left != 0) {
			left->add(val);
		} else {
			left = new Node<T>(val);
		}
	} else {
		if (right != 0) {
			right->add(val);
		} else {
			right = new Node<T>(val);
		}
	}
}

template <class T>
bool Node<T>::find(T val) {
	if (val == value) {
		return true;
	} else if (val < value) {
		return (left != 0 && left->find(val));
	} else if (val > value) {
		return (right != 0 && right->find(val));
	}
}

template <class T>
Node<T>* Node<T>::succesor() {
	Node<T> *le, *ri;

	le = left;
	ri = right;

	if (left == 0) {
		if (right != 0) {
			right = 0;
		}
		return ri;
	}

	if (left->right == 0) {
		left = left->left;
		le->left = 0;
		return le;
	}

	Node<T> *parent, *child;
	parent = left;
	child = left->right;
	while (child->right != 0) {
		parent = child;
		child = child->right;
	}
	parent->right = child->left;
	child->left = 0;
	return child;
}

template <class T>
void Node<T>::remove(T val) {
	Node<T> * succ, *old;

	if (val < value) {
		if (left != 0) {
			if (left->value == val) {
				old = left;
				succ = left->succesor();
				if (succ != 0) {
					succ->left = old->left;
					succ->right = old->right;
				}
				left = succ;
				delete old;
			} else {
				left->remove(val);
			}
		}
	} else if (val > value) {
		if (right != 0) {
			if (right->value == val) {
				old = right;
				succ = right->succesor();
				if (succ != 0) {
					succ->left = old->left;
					succ->right = old->right;
				}
				right = succ;
				delete old;
			} else {
				right->remove(val);
			}
		}
	}
}

template <class T>
void Node<T>::removeChilds() {
	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}

template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		//aux << " ";
	}
	aux << value;
	if (right != 0) {
		right->inorder(aux);
	}
}

////////////////

template <class T>
class BST {
private:
	Node<T> *root;

public:
	BST();
	~BST();
	bool empty() const;
	void add(T);
	bool find(T) const;
	void remove(T);
	void removeAll();
	int* inorder() const;
};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
BST<T>::~BST() {
	removeAll();
}

template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}
template <class T>
void BST<T>::remove(T val) {
	if (root != 0) {
		if (val == root->value) {
			Node<T> *succ = root->succesor();
			if (succ != 0) {
				succ->left = root->left;
				succ->right = root->right;
			}
			delete root;
			root = succ;
		} else {
			root->remove(val);
		}
	}
}

template <class T>
void BST<T>::removeAll() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
}

template<class T>
void BST<T>::add(T val) {
	if (root != 0) {
		if (!root->find(val)) {
			root->add(val);
		}
	} else {
		root = new Node<T>(val);
	}
}

template <class T>
bool BST<T>::find(T val) const {
	if (root != 0) {
		return root->find(val);
	} else {
		return false;
	}
}

template <class T>
int* BST<T>::inorder() const {
	std::stringstream aux;

	//aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	//aux << "]";
	
	char c;
	int i=0;
	static int lol[100];
	while (aux.get(c)){
		//cout<<(int)c-48;
		lol[i]=(int)c-48;
		i=i+1;
	}
	return lol;
}
#endif
