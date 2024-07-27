#include<iostream>
//#include<string>

using namespace std;

class String
{
	char* str;//указатель на char
	int length;
public:
	String()
	{
		str = nullptr;
		length = 0;
	}
	String(const char* str)
	{
		length = strlen(str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
	}
	String(const String& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}
	~String()
	{
		delete[]str;
	}
	String& operator=(const String& other)
	{
		if (this->str != nullptr)
		{
			delete[]str;
		}
		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
		return *this;
	}
	String operator+(const String& other)
	{
		String newStr;
		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);
		newStr.length = thisLength + otherLength;
		newStr.str = new char[thisLength + otherLength + 1];
		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}
		for (int j = 0; j < otherLength; j++, i++)
		{
			newStr.str[i] = other.str[j];
		}
		newStr.str[thisLength + otherLength] = '\0';
		return newStr;
	}
	void Print()
	{
		cout << str;
	}

	int Lenght()
	{
		return length;
	}

	bool operator==(const String& other)
	{
		if (this->length != other.length)
		{
			return false;
		}
		for (int i = 0; i < length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator!=(const String& other)
	{
		return !(this->operator==(other));
	}
	char& operator[](int index)
	{
		return this->str[index];
	}
	String(String&& other)
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}

};
//// Перегрузка <<
//std::ostream& operator << (std::ostream& ostrm, const String& other)
//{
//	return ostrm << other.str;
//}
//
////Перегрузка >>
//std::istream& operator >> (std::istream& istrm, String& other)
//{
//	//Создаем массив из Char в статической памяти
//	char buffer[100];
//
//	// Получаем целую строку из stream, сохраняем адрес буфера с текстом в *lineptr (функция из стандартной библиотеки)
//	istrm.getline(buffer, 100);
//
//	//Получаем длину строки (без пробелов)
//	int newStrLength = strlen(buffer);
//
//	// Создаем новый массив в динамической памяти(имейте в виду, что функция createNewArray создана мной и описана в теле класса TestString (в которой происходит создание нового массива в динамической памяти) . 
//	other.createNewArray(newStrLength);
//
//	//Копируем данные (имейте в виду, что функция copyStr создана мной и описана в теле класса TestString (в которой происходит поэлементное копирование массивов))
//	other.copyStr(buffer);
//	other.length = newStrLength;
//	return istrm;
//}
int main()
{

	String str("Hello");
	str.Print();
	cout << endl;
	String str1("Hello");
	String str2("world");
	//str1 = str2;
	//str1.Print();
	cout << endl;
	//	String result;
	String result = str1 + str2;
	//	result = str1 + str2;
	result.Print();
	cout << endl;
	cout << str1.Lenght() << endl;
	cout << str2.Lenght() << endl;
	cout << result.Lenght() << endl;

	bool equal = str == str1;
	bool equal1 = !(str != str1);


	cout << equal << endl;
	cout << equal1 << endl;
	result[0] = 'q';
	cout << str[0] << endl;
	result.Print();
	return 0;
}
