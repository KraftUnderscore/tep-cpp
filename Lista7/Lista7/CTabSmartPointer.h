#pragma once

template <typename T> class CTabSmartPointer
{
public:
	CTabSmartPointer(T **ptPointer, int iTabSizeX);
	CTabSmartPointer(const CTabSmartPointer &pcOther);
	~CTabSmartPointer();
	T& operator*() { return (*pt_pointer); }
	T* operator->() { return (pt_pointer); }
	void operator=(const CTabSmartPointer &pcOther);
private:
	T **pt_pointer;
	CRefCounter *pc_counter;
	int i_tab_size_x;
};

template <typename T>
CTabSmartPointer<T>::CTabSmartPointer(T **ptPointer, int iTabSizeX)
{
	pt_pointer = ptPointer;
	i_tab_size_x = iTabSizeX;
	pc_counter = new  CRefCounter();
	pc_counter->iAdd();
}

template <typename T>
CTabSmartPointer<T>::CTabSmartPointer(const CTabSmartPointer &pcOther)
{
	pt_pointer = pcOther.pt_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
}

template <typename T>
CTabSmartPointer<T>::~CTabSmartPointer()
{
	if (pc_counter->iDec() == 0)
	{
		for (int ii = 0; ii < i_tab_size_x; ii++)
		{
			delete pt_pointer[ii];
		}
		delete pt_pointer;
		delete pc_counter;
	}
}

template<typename T>
void CTabSmartPointer<T>::operator=(const CTabSmartPointer &pcOther)
{
	if (pc_counter->iDec() == 0)
	{
		for (int ii = 0; ii < i_tab_size_x; ii++)
		{
			delete pt_pointer[ii];
		}
		delete pt_pointer;
		delete pc_counter;
	}
	pt_pointer = pcOther.pt_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
}
