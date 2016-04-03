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
	NDVector<T>(int size = 10);
	~NDVector<T>();
	NDVector<T>( const NDVector<T> &obj );
	void operator=(const NDVector &V);
	const int & operator[](unsigned int);
	void push_back(T); //add to back
	void pop_back(); //remove from back
	T back(); //access last element
	void clear(); //empty array

private:
	const int size;
	T * vector;

};
template <class T>
NDVector<T>::NDVector(int size) { //default constructor
	vector = new T [size];

}
template <class T>
NDVector<T>::~NDVector() {
	delete[] vector;
}
template <class T>
NDVector<T>::NDVector(const NDVector<T> &obj) {
	vector = new T [size];
	*vector = *obj.vector; //copies the value
}
template <class T>
void NDVector<T>::operator=(const NDVector &V) {
	//copy one vector to another vector
	vector = V.vector;

	return *this;
}
template <class T>
const int & NDVector<T>::operator[](unsigned int i) {
	return vector[i];
}
#endif //_NDVECTOR_H_