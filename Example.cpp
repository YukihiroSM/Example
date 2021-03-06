#include "Array.cpp"
/*
			TASK:
			Множина (2 класи: елемент множини, множина перебувають у
			відношенні агрегації)
			Конструктори: за замовчуванням, з параметрами та копіювання.
			Деструктор.
			Функції (дві-три на вибір):
			додавання елемента до множини;
			видалення елемента із множини;
			виведення всіх елементів множини на екран;
			перевірка входження елемента до множини;
			очищення множини;
			перебирання всіх елементів множини.
			+
			Спроектувати шаблон.
			====Created by Yukihiro (Andriy Smidonov)====

*/
int main()
{
	Array<string, int> ar1;
	ar1.createArray();
	ar1.enterArray();
	ar1.showArray();
	ar1.addElement();
	ar1.showArray();
	ar1.checkOccurenceOfElement("abcde") ? cout << "Found" << endl : cout << "Not Found" << endl;
	ar1.removeElement();
	ar1.showArray();
	return 0;
}