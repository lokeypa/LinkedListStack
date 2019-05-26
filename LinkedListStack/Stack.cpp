#include "Stack.h"

void Stack::Push(int val)
{
	pTop = new Element(val, pTop);
}

int Stack::Pop()
{
	if (!Empty()) {
		int tempVal = pTop->GetValue();
		auto tempPTop = pTop;
		pTop = pTop->Disconnect();
		delete tempPTop;
		return tempVal;
	}
	else {
		return - 1;
	}
}

int Stack::Size() const
{
	if(Empty()) {
		return 0;
	}
	else {
		return pTop->CountElement();
	}
}

bool Stack::Empty() const
{
	return pTop == nullptr;
}

Stack::Element::Element(int value, Element * pNext)
	:
	value(value),
	pNext(pNext)
{
}

int Stack::Element::GetValue()
{
	return value;
}

Stack::Element * Stack::Element::Disconnect()
{
	auto tempPNext = pNext;
	pNext = nullptr;
	return tempPNext;

}

int Stack::Element::CountElement()
{
	if (pNext == nullptr) {
		return 1;
	}
	else {
		return 1 + pNext->CountElement();
	}
}
