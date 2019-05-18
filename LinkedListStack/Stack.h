#pragma once

class Stack
{
private:

	// it an element which is gogig to put in stact and used as linklist to follow.
	class Element {
	public:
		Element(int value, Element *pNext);
		int GetValue();
		Element* Disconnect();
	private:
		int value;
		Element *pNext = nullptr;
	};
public:
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;

private:
	Element *pTop = nullptr;
};