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

		int GetVal() const {
			return val;
		}

		Element* Disconnect() {
			auto pTemp = pNext;
			pNext = nullptr;
			return pTemp;
		}

		int CountElement() const {

			// recurssion using 
			if (pNext != nullptr) {
				return pNext->CountElement() + 1;
			}
			else
			{
				return 1;
			}

		}

	private:
		int val;
		Element* pNext = nullptr;

	};

public:
	void Push(int val) {
		pTop = new Element(val, pTop);
	}
	int Pop() {

		if (!Empty()) {
			const int tempVal = pTop->GetVal();
			auto pOldTop = pTop;
			pTop = pTop->Disconnect();
			delete pOldTop;
			return tempVal;
		}
		else {
			return -1;//if the stack ios empty.
		}
	}
	int Size() const
	{
		if (!Empty()) {
			return (*pTop).CountElement();
		}
		else {
			return 0;
		}
	}
	bool Empty() const
	{
		return pTop == nullptr;
	}

private :
	Element* pTop = nullptr;	
};