#include <iostream>
class CMyStr 
{
public:
	CMyStr() { pc_str = NULL; i_size = 0; };
	CMyStr(const CMyStr &cOther);
	CMyStr(CMyStr &&cOther);
	~CMyStr();
	void operator=(const CMyStr &cOther);
	void operator=(CMyStr &&cOther);
	void vSet(std::string sValue);
	void vPrint();
private:
	char *pc_str;
	int i_size;
	void v_copy(const CMyStr &cOther);
};