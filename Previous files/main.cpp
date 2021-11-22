//main.cpp 
//created by Daniil Nesterov (e-mail: maidanov1991@yandex.ru)
//homework - webinar of November 12, 2021 

#include <iostream>
#include <stdint.h> 
#include <clocale>

//Task 1. Создать и инициализировать переменные пройденных типов данных (short int, int, long long, char, bool, float, double).
//Task 1 - первая часть 
short int A = 12;			//объявлена глобальная переменная типа "short int" с именем "A" и начальным значением 12
unsigned int nB{ 65'000U };	//объявлена и инициализирована глобальная беззнаковая переменная типа "int" с именем "nB" и значением 65'000 
int64_t CAT{ -9'000'000'000'000'000'000 }; //с применением #include <stdint.h> объявлена глобальная переменная типа "long long" 
										   //с именем "CAT" и начальным значением -9'000'000'000'000'000'000 
//Конец первой части Task 1


//Task 2. Создать перечисление(enum) с возможными вариантами символов для игры в крестики-нолики. 
enum Sign {
	empty,		//пустое значение для первоначального заполнения игрового поля
	cross,		//значение для заполнения пустого поля "крестиком"
	zero		//значение для заполнения пустого поля "ноликом"
};
//Конец Task 2.


//Task 3. Создать массив, способный содержать значения такого перечисления и инициализировать его.
Sign TTTField[3][3] = { {empty, empty, empty}, {empty, empty, empty}, {empty, empty, empty} };
//Конец Task 3.


//Task 4. * Создать структуру(struct) данных «Поле для игры в крестики-нолики» и снабдить 
//его всеми необходимыми свойствами (подумайте что может понадобиться)
struct TTT{
	Sign Field[3][3];					//игровое поле 3х3
	char sFirstPlayer[15];				//имя первого игрока (максимум 15 символов)
	char sSecondPlayer[15];				//имя второго игрока (максимум 15 символов)
	bool bIsFirstCross : 1;				//однобитовый ответ на вопрос: "Первый игрок ходит крестиками?" (1 - да, 0 - нет):  
										//для традиционных "крестиков-ноликов" значение переменной bIsFirstCross позволяет
										//однозначно определить, чем ходит второй игрок и который из игроков ходит первым.  
	unsigned short int nMovesNumber : 4;//количество сделанных ходов (4-битная переменная - можно хранить значение от 0 до 15)
	bool bIsFirstWin : 1;				//однобитовый ответ на вопрос: "Первый игрок победил?" (1 - да, 0 - нет; вопрос актуален после 5 хода),  
										//если bIsFirstWin == 1, то игра заканчивается победой первого игрока,  
										//если после 9 хода bIsFirstWin == 0 , то игра окончилась ничьей.
	bool bIsSecondWin : 1;				//однобитовый ответ на вопрос: "Второй игрок победил?" (1 - да, 0 - нет; вопрос актуален после 6 хода),  
										//если bIsSecondWin == 1, то игра заканчивается победой второго игрока. 
};
//Конец Task 4.


//Task 5. ** Создать структуру(struct MyVariant) объединяющую: union MyData (int,float, char)
//и 3-и битовых поля(флага) указывающими какого типа значение в данный момент содержится в объединении(isInt, isFloat, isChar).
//Продемонстрировать пример использования в коде этой структуры. 
//Task 5 - первая часть. 
union MyData {				//новый тип данных "MyData" 
	int nIdNumber;			//ID-номер
	float Salary;			//Зарплата
	char DepartmentCode;	//Код подразделения
};

struct MyVariant {			//новый тип данных "MyVariant"
	MyData employee;		//инфо о сотруднике (в формате типа данных "MyData")
	bool bIsInt : 1;		//однобитовый ответ на вопрос "Инфо о сотруднике содержит значение int?" (1 - да, 0 - нет)
	bool bIsFloat : 1;		//однобитовый ответ на вопрос "Инфо о сотруднике содержит значение float?" (1 - да, 0 - нет)
	bool bIsChar : 1;		//однобитовый ответ на вопрос "Инфо о сотруднике содержит значение char?" (1 - да, 0 - нет)
};
//Конец первой части Task 5 


int main() {
	setlocale(LC_ALL, "Russian"); 


//Task 1 - вторая часть.	
	unsigned char a, c;	//объявлены локальные переменные типа "unsigned char" с именами "a" и "c" (их начальные значения не определены)
	a = 'Ф';			//с применением #include <clocale> ранее объявленной локальной unsigned char переменной "a" присвоено значение 'Ф' 
	c = 244;			//ранее объявленной локальной unsigned char переменнной "c" присвоено значение 244
	bool b{ true };		//объявлена и инициализирована локальная переменная типа "bool" с именем "b" и начальным значением "true" 
	float f = -123.047f;//объявлена локальная переменная типа "float" с именем "f" и начальным значением -123.047 
	double d = 9321.0;	//объявлена и инициализирована локальная переменная типа "double" с именем "d" и значением 9321.0
//Конец второй части Task 1


//Task 5 - вторая часть.	
	MyVariant Angela;							//объявлена новыая переменная типа "MyVariant" с именем "Angela"
	Angela.employee.nIdNumber = 92'345'625;		//в инфо о сотруднике "Angela" записано int значение ID-номера
	Angela.bIsInt = 1;							//обзначено, что в инфо о сотруднике "Angela" записано int значение
	Angela.bIsFloat = 0;						//обзначено, что в инфо о сотруднике "Angela" записано не-float значение
	Angela.bIsChar = 0;							//обзначено, что в инфо о сотруднике "Angela" записано не-char значение

	
	//даны инструкции вывести ту инфо о сотруднике "Angela", которая обозначена записаной   
	if (Angela.bIsInt == 1) {					
		std::cout << "Angela.IdNumber = " << Angela.employee.nIdNumber << "\n\n";
	}
	
	if (Angela.bIsFloat == 1) { 
		std::cout << "Angela.Salary = " << Angela.employee.Salary << "\n\n"; 
	}
	
	if (Angela.bIsChar == 1) {
		std::cout << "Angela.DepartmentCode = " << Angela.employee.DepartmentCode << "\n\n";
	}
	

	Angela.employee.DepartmentCode = 'W';	//в инфо о сотруднике "Angela" записано char значение кода департамента
	Angela.bIsInt = 0;						//обзначено, что в инфо о сотруднике "Angela" записано не-int значение
	Angela.bIsChar = 1;						//обзначено, что в инфо о сотруднике "Angela" записано char значение
	

	//даны инструкции вывести ту инфо о сотруднике "Angela", которая обозначена записаной  
	if (Angela.bIsInt == 1) {
		std::cout << "Angela.IdNumber = " << Angela.employee.nIdNumber << "\n\n";
	}

	if (Angela.bIsFloat == 1) {
		std::cout << "Angela.Salary = " << Angela.employee.Salary << "\n\n";
	}

	if (Angela.bIsChar == 1) {
		std::cout << "Angela.DepartmentCode = " << Angela.employee.DepartmentCode << "\n\n";
	}
//Конец второй части Task 5 

	return 0;
};