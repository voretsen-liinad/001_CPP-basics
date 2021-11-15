//main.cpp 
//created by Daniil Nesterov (e-mail: maidanov1991@yandex.ru)
//homework - webinar of November 12, 2021 

#include <iostream>
#include <stdint.h> 
#include <clocale>

//Task 1. ������� � ���������������� ���������� ���������� ����� ������ (short int, int, long long, char, bool, float, double).
//Task 1 - ������ ����� 
short int A = 12;			//��������� ���������� ���������� ���� "short int" � ������ "A" � ��������� ��������� 12
unsigned int nB{ 65'000U };	//��������� � ���������������� ���������� ����������� ���������� ���� "int" � ������ "nB" � ��������� 65'000 
int64_t CAT{ -9'000'000'000'000'000'000 }; //� ����������� #include <stdint.h> ��������� ���������� ���������� ���� "long long" 
										   //� ������ "CAT" � ��������� ��������� -9'000'000'000'000'000'000 
//����� ������ ����� Task 1


//Task 2. ������� ������������(enum) � ���������� ���������� �������� ��� ���� � ��������-������. 
enum Sign {
	empty,		//������ �������� ��� ��������������� ���������� �������� ����
	cross,		//�������� ��� ���������� ������� ���� "���������"
	zero		//�������� ��� ���������� ������� ���� "�������"
};
//����� Task 2.


//Task 3. ������� ������, ��������� ��������� �������� ������ ������������ � ���������������� ���.
Sign TTTField[3][3] = { {empty, empty, empty}, {empty, empty, empty}, {empty, empty, empty} };
//����� Task 3.


//Task 4. * ������� ���������(struct) ������ ����� ��� ���� � ��������-������ � �������� 
//��� ����� ������������ ���������� (��������� ��� ����� ������������)
struct TTT{
	Sign Field[3][3];					//������� ���� 3�3
	char sFirstPlayer[15];				//��� ������� ������ (�������� 15 ��������)
	char sSecondPlayer[15];				//��� ������� ������ (�������� 15 ��������)
	bool bIsFirstCross : 1;				//����������� ����� �� ������: "������ ����� ����� ����������?" (1 - ��, 0 - ���):  
										//��� ������������ "���������-�������" �������� ���������� bIsFirstCross ���������
										//���������� ����������, ��� ����� ������ ����� � ������� �� ������� ����� ������.  
	unsigned short int nMovesNumber : 4;//���������� ��������� ����� (4-������ ���������� - ����� ������� �������� �� 0 �� 15)
	bool bIsFirstWin : 1;				//����������� ����� �� ������: "������ ����� �������?" (1 - ��, 0 - ���; ������ �������� ����� 5 ����),  
										//���� bIsFirstWin == 1, �� ���� ������������� ������� ������� ������,  
										//���� ����� 9 ���� bIsFirstWin == 0 , �� ���� ���������� ������.
	bool bIsSecondWin : 1;				//����������� ����� �� ������: "������ ����� �������?" (1 - ��, 0 - ���; ������ �������� ����� 6 ����),  
										//���� bIsSecondWin == 1, �� ���� ������������� ������� ������� ������. 
};
//����� Task 4.


//Task 5. ** ������� ���������(struct MyVariant) ������������: union MyData (int,float, char)
//� 3-� ������� ����(�����) ������������ ������ ���� �������� � ������ ������ ���������� � �����������(isInt, isFloat, isChar).
//������������������ ������ ������������� � ���� ���� ���������. 
//Task 5 - ������ �����. 
union MyData {				//����� ��� ������ "MyData" 
	int nIdNumber;			//ID-�����
	float Salary;			//��������
	char DepartmentCode;	//��� �������������
};

struct MyVariant {			//����� ��� ������ "MyVariant"
	MyData employee;		//���� � ���������� (� ������� ���� ������ "MyData")
	bool bIsInt : 1;		//����������� ����� �� ������ "���� � ���������� �������� �������� int?" (1 - ��, 0 - ���)
	bool bIsFloat : 1;		//����������� ����� �� ������ "���� � ���������� �������� �������� float?" (1 - ��, 0 - ���)
	bool bIsChar : 1;		//����������� ����� �� ������ "���� � ���������� �������� �������� char?" (1 - ��, 0 - ���)
};
//����� ������ ����� Task 5 


int main() {
	setlocale(LC_ALL, "Russian"); 


//Task 1 - ������ �����.	
	unsigned char a, c;	//��������� ��������� ���������� ���� "unsigned char" � ������� "a" � "c" (�� ��������� �������� �� ����������)
	a = '�';			//� ����������� #include <clocale> ����� ����������� ��������� unsigned char ���������� "a" ��������� �������� '�' 
	c = 244;			//����� ����������� ��������� unsigned char ����������� "c" ��������� �������� 244
	bool b{ true };		//��������� � ���������������� ��������� ���������� ���� "bool" � ������ "b" � ��������� ��������� "true" 
	float f = -123.047f;//��������� ��������� ���������� ���� "float" � ������ "f" � ��������� ��������� -123.047 
	double d = 9321.0;	//��������� � ���������������� ��������� ���������� ���� "double" � ������ "d" � ��������� 9321.0
//����� ������ ����� Task 1


//Task 5 - ������ �����.	
	MyVariant Angela;							//��������� ������ ���������� ���� "MyVariant" � ������ "Angela"
	Angela.employee.nIdNumber = 92'345'625;		//� ���� � ���������� "Angela" �������� int �������� ID-������
	Angela.bIsInt = 1;							//���������, ��� � ���� � ���������� "Angela" �������� int ��������
	Angela.bIsFloat = 0;						//���������, ��� � ���� � ���������� "Angela" �������� ��-float ��������
	Angela.bIsChar = 0;							//���������, ��� � ���� � ���������� "Angela" �������� ��-char ��������

	
	//���� ���������� ������� �� ���� � ���������� "Angela", ������� ���������� ���������   
	if (Angela.bIsInt == 1) {					
		std::cout << "Angela.IdNumber = " << Angela.employee.nIdNumber << "\n\n";
	}
	
	if (Angela.bIsFloat == 1) { 
		std::cout << "Angela.Salary = " << Angela.employee.Salary << "\n\n"; 
	}
	
	if (Angela.bIsChar == 1) {
		std::cout << "Angela.DepartmentCode = " << Angela.employee.DepartmentCode << "\n\n";
	}
	

	Angela.employee.DepartmentCode = 'W';	//� ���� � ���������� "Angela" �������� char �������� ���� ������������
	Angela.bIsInt = 0;						//���������, ��� � ���� � ���������� "Angela" �������� ��-int ��������
	Angela.bIsChar = 1;						//���������, ��� � ���� � ���������� "Angela" �������� char ��������
	

	//���� ���������� ������� �� ���� � ���������� "Angela", ������� ���������� ���������  
	if (Angela.bIsInt == 1) {
		std::cout << "Angela.IdNumber = " << Angela.employee.nIdNumber << "\n\n";
	}

	if (Angela.bIsFloat == 1) {
		std::cout << "Angela.Salary = " << Angela.employee.Salary << "\n\n";
	}

	if (Angela.bIsChar == 1) {
		std::cout << "Angela.DepartmentCode = " << Angela.employee.DepartmentCode << "\n\n";
	}
//����� ������ ����� Task 5 

	return 0;
};