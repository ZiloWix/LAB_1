#include <iostream>
using namespace std;

class dynamicarray
{
private:
	int* ptr;
	int ElementCount; // размер массива
	int CurElementCount; // количесвто заполненных элементов массива
public:
	dynamicarray(): CurElementCount(10), ElementCount(10), ptr(ptr = new int [10]) {};
	dynamicarray(int ce, int ec, int* ptr): CurElementCount(ce), ElementCount(ec), ptr(ptr) {}
	void DynamicArrayAdd(int);  // добавление елемента в конец массива
	//void DynamicArrayInsert(int, int); // вставка элемента по индексу с заменой
	void DynamicArrayInsert2(int, int); // вставка элемента по индексу
	void DynamicArrayDelete(int); // удаляет элемент массива, с указанным индексом
	inline void DynamicArrayClear(); // удаляет массив из памяти компьютера
	void DynamicArrayShow(); // выводит массив

	int operator[](int);
};

int dynamicarray::operator[](int index) {
	if (index >= CurElementCount || index < 0)
		throw std::runtime_error("operator[] --- ERROR");
		cout << "operator[] --- ERROR" << endl;
	return ptr[index];
}

void dynamicarray::DynamicArrayAdd(int value)
{
	if (CurElementCount == ElementCount)
	{
		int size = ElementCount * 2;
		int* array = new int[size];
		for (int i = 0; i < ElementCount; i++)
		{
			array[i] = ptr[i];
		}
		ElementCount *= 2;
		delete[] ptr;
		ptr = array;
	}

	ptr[CurElementCount] = value;
	CurElementCount++;
}

/*void dynamicarray::DynamicArrayInsert(int index, int value)
{
	if (index >= CurElementCount || index < 0)
	{
		cout << "DynamicArrayInsert --- ERROR" << endl;
		return;
	}
	ptr[index] = value;
}*/

void dynamicarray::DynamicArrayInsert2(int index, int value)
{
	if (index >= CurElementCount || index < 0)
	{
		cout << "DynamicArrayInsert --- ERROR" << endl;
		return;
	}
	if (CurElementCount == ElementCount)
	{
		int size = ElementCount * 2;
		int* array = new int[size];
		for (int i = 0; i < ElementCount; i++)
		{
			array[i] = ptr[i];
		}
		ElementCount *= 2;
		delete[] ptr;
		ptr = array;
	}
	for (unsigned int i = CurElementCount; i > index; i--)
	{
		ptr[i] = ptr[i-1];
	}
	ptr[index] = value;
	CurElementCount++;
}

void dynamicarray::DynamicArrayDelete(int index)
{
	//if (CurElementCount == 1)
	//{
	//	delete[] ptr;//DynamicArrayClear(da) возможно ли как-то воспользоваться этой функцией?
	//	return;
	//}
	//else
		if (index < 0 && index >= CurElementCount)
	{
		cout << "DynamicArrayDelete --- ERROR" << endl;
		return;
	}
	else if (index == (CurElementCount - 1))
	{
		CurElementCount--;
		return;
	}

	for (int i = index; i < (CurElementCount - 1); i++)
	{
		ptr[i] = ptr[i + 1];
	}
	CurElementCount--;
}

inline void dynamicarray::DynamicArrayClear()
{
	delete[] ptr;
}

void dynamicarray::DynamicArrayShow()
{
	for (int i = 0; i < CurElementCount; i++)
	{
		cout << ptr[i] << endl;
	}
}

int main()
{
	int* ptr = new int[10];
	dynamicarray d;
	dynamicarray da(0, 10, ptr);


	for (int i = 0; i < 30; i++)
	{
		da.DynamicArrayAdd(i * i);
	}

	//da.DynamicArrayInsert(0, 100);
	da.DynamicArrayInsert2(0, 10);
	da.DynamicArrayDelete(0);

	da.DynamicArrayShow();
	//cout << da[2] << endl;
	da.DynamicArrayClear();
	
	cout << endl << endl;
	d.DynamicArrayInsert2(0, 1111);
	d.DynamicArrayShow();
	d.DynamicArrayClear();
	return 0;
}