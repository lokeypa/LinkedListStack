#pragma once

class Stack
{
private: 
	class Element {
	public: 
		Element(int val, Element* pNext) :
			val(val),
			pNext(pNext)
		{}
	private:
		int val;
		Element* pNext = nullptr;

	};

public:
	void Push(int val) {
		pTop = new Element(val, pTop);
	}
	int Pop();
	int Size() const;
	bool Empty() const;

private :
	Element* pTop = nullptr;	
};