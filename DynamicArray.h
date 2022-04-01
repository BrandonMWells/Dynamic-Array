#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED

template <class T>
class Array {
public:
	Array(int initSize);
	Array(const Array<T> & obj) { deepCopy(obj); }
	Array<T> & operator = (const Array<T> & obj);
	~Array() { makeEmpty(); }

	T & operator [] (int index);
	int length() const { return capacity; }
	void changeSize(int newSize);
	int errCode() const { return err; }
private:
	T * els;	// collection of elements of type T
	int capacity;
	int err;
	T dud;
	void deepCopy(const Array<T> & obj);
	void makeEmpty() { delete [] els; }
};

template <class T>
Array<T>::Array(int initSize) {
	if (initSize < 1) { capacity = 1; err = 1; }
	else { capacity = initSize; err = 0; }
	els = new T [capacity];
}

template <class T>
Array<T> & Array<T>::operator = (const Array<T> & obj) {
    if (this == & obj) return (*this);
    makeEmpty();
    deepCopy(obj);
    return (*this);
}

template <class T>
T & Array<T>::operator [] (int index) {
	if (index < 0 || index >= capacity) {
		err |= 2;	// err = err | 2;
		return dud;
	}
	return els[index];
}

template <class T>
void Array<T>::changeSize(int newSize) {
	if (newSize < 1) {
		err |= 4;
		return;
	}
    T * temp = new T[newSize];
	int limit = (newSize < capacity) ? newSize : capacity;		// ternary operator..   boolExp ? exp1 : exp2
    for (int i = 0; i < limit; i++)
        temp[i] = els[i];
    delete [] els;
    els = temp;
    capacity = newSize;
}

template <class T>
void Array<T>::deepCopy(const Array<T> & obj) {
    els = new T[obj.capacity];
    capacity = obj.capacity;
    err = obj.err;
    dud = obj.dud;
    for (int i = 0; i < capacity; i++)
        els[i] = obj.els[i];
}


#endif // DYNAMICARRAY_H_INCLUDED
