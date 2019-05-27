#pragma once

//access read violation error occurs and we need toimplementthe copy cnstruct and the copy assignment operator 

class Stack
{
private:

	// it an element which is gogig to put in stact and used as linklist to follow.
	class Element {
	public:
		Element(int value, Element *pNext);
		Element(const Element& src);
		int GetValue();
		Element* Disconnect();
		int CountElement();
		~Element();
	private:
		int value;
		Element *pNext = nullptr;
	};
public:
	Stack() = default;
	Stack(const Stack& src);
	Stack& operator=(const Stack& src); // need to do deep copy.
	~Stack();
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;

private:
	Element *pTop = nullptr;
};