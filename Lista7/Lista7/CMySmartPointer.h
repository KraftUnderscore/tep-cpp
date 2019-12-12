#pragma once

class CRefCounter
{
public:
	CRefCounter() { i_count = 0; }
	int iAdd() { return(++i_count); }
	int iDec() { return(--i_count); };
	int iGet() { return(i_count); }
private:
	int i_count;
};

template <typename T> class CMySmartPointer
{
public:
	CMySmartPointer(T *ptPointer);
	CMySmartPointer(const CMySmartPointer &pcOther);
	~CMySmartPointer();
	T& operator*() { return (*pt_pointer); }
	T* operator->() { return (pt_pointer); }
	void operator=(const CMySmartPointer &pcOther);
private:
	T *pt_pointer;
	CRefCounter *pc_counter;
};

template <typename T>
CMySmartPointer<T>::CMySmartPointer(T *ptPointer)
{
	pt_pointer = ptPointer;
	pc_counter = new  CRefCounter();
	pc_counter->iAdd();
}

template <typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer &pcOther)
{
	pt_pointer = pcOther.pt_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
}

template <typename T>
CMySmartPointer<T>::~CMySmartPointer()
{
	if (pc_counter->iDec() == 0)
	{
		delete pt_pointer;
		delete pc_counter;
	}
}

template<typename T>
void CMySmartPointer<T>::operator=(const CMySmartPointer &pcOther)
{
	if (pc_counter->iDec() == 0)
	{
		delete pt_pointer;
		delete pc_counter;
	}
	pt_pointer = pcOther.pt_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
}
