// 面试题1：赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。

#include <cstring>
#include <cstdio>

class CMyString
{
public:
	CMyString(char *pData = NULL);
	CMyString(const CMyString &str);
	~CMyString(void);

	CMyString& operator=(const CMyString &str);

	void Print();

private:
	char *m_pData;

};

CMyString::CMyString(char *pData)
{
	if(NULL == pData)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strncpy(m_pData, pData, length + 1);
	}
}

CMyString::CMyString(const CMyString &str)
{
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strncpy(m_pData, str.m_pData, length + 1);
}

CMyString::~CMyString(void)
{
	delete[] m_pData;
}

CMyString &CMyString::operator=(const CMyString &str)
{
	if(this != &str)
	{
		CMyString strTmp(str);

		char *pTmp = strTmp.m_pData;
		strTmp.m_pData = m_pData;
		m_pData = pTmp;
	}

	return *this;
}

void CMyString::Print()
{
	printf("out: %s \n", m_pData);
}

void Test1()
{
	printf("Test1 begins: \n");
	char *text = "This is AssignOperator test";
	CMyString whw1(text);
	CMyString whw2;
	whw2 = whw1;

	printf("The expected result is: %s.\n", text);
    printf("The actual result is: ");
    whw2.Print();
}

void Test2()
{
    printf("Test2 begins:\n");

    char* text = "Hello world";

    CMyString whw1(text);
    whw1 = whw1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    whw1.Print();
}

// 连续赋值
void Test3()
{
    printf("Test3 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
