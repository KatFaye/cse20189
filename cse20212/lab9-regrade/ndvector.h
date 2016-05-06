//ndvector.h
//Class definition NDvector template class
//Author: Kat Herring

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#ifndef _NDVECTOR_H_
#define _NDVECTOR_H_

template <class T>
class NDVector {

public:
	NDVector<T>(int);
	~NDVector<T>();
	NDVector<T>( const NDVector<T> &obj );
	NDVector<T> & operator=(const NDVector &V);
	const int & operator[](unsigned int);
	const NDVector<T>& push_back(T); //add to back
	const NDVector<T>& pop_back(); //remove from back
	void setVal(int, int);
	int size() const; //size of vector
	T back(); //access last element
	const NDVector<T> & clear(); //empty array



private:
	int nItems;
	T * vector;
	int values; //number of items actually in vector

};
template <class T>
NDVector<T>::NDVector(int n = 10) { //default constructor
	nItems = n;
	values = 0; //vector initially empty
	vector = new T [nItems];

}
template <class T>
NDVector<T>::~NDVector() {
	delete[] vector;
}
template <class T>
NDVector<T>::NDVector(const NDVector<T> &obj) { //copy constructor
	vector = new T [obj.values];
	values = obj.size();
	nItems = obj.size();
}
template <class T> //copy constructor
NDVector<T> & NDVector<T>::operator=(const NDVector<T> &V) {
	//copy one vector to another vector
	T * newVec = new T[V.size()];
	for (int i = 0; i < values; i++) {
		newVec[i] = V.vector[i];
	}
	delete[] vector;
	this->vector = newVec;
	this->values = V.values;
	this->nItems = V.nItems; 
	return *this;
}
template <class T>
const int & NDVector<T>::operator[](unsigned const int i) {
	return vector[i];
}
template <class T>
const NDVector<T>& NDVector<T>::push_back(T val) {
	if (values>=nItems) {
		T * temp = new T[values*2]; //increase vector size by one
		
		for (int i = 0; i < values; i++) {
			temp[i] = vector[i];
		}
		temp[values] = val; //adds new element to end of vector
		delete[] vector;
		this->vector = temp;
		this->values += 1;
		this->nItems *= 2;
	}
		
	else {
		vector[values] = val;
		++values;
	}
	return *this;
}
template <class T>
const NDVector<T> & NDVector<T>::pop_back() {
	T * temp = new T[values-1]; //increase vector size by one
	for (int i = 0; i < values-1; i++) {
			temp[i] = vector[i];
		}
		delete[] vector;
		this->vector = temp;
		this->values -= 1;
		this->nItems -= 1;
	return *this;
}
template <class T>
void NDVector<T>::setVal(int pos, int value) {
	this->vector[pos] = value;
}
template <class T>
int NDVector<T>::size() const {
	return this->values;
}
template <class T>
T NDVector<T>::back() { //access last element
return vector[values-1];
}
template <class T>
const NDVector<T> & NDVector<T>::clear() { //deletes vector and creates new empty vector
	T * temp = new T[10];
	
	delete[] vector;
	this->vector = temp;
	this->values = 0;
	this->nItems = 10;

	return *this;
}
#endif //_NDVECTOR_H_