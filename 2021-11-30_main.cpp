// 2021-11-30_main.cpp 
// homework - Webinar of November, 30, 2021
// created by Daniil Nesterov (e-mail: maidanov1991@yandex.ru)

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "2021-11-30_mylib.h"

using namespace std; 
namespace fs = std::filesystem; 

//Task 2 - part 1.=============================================================================================================================//
#define T2_CHECK_NUMBER(number, limit) \
	if (limit == 0) \
		cout << "false"; \
	else \
	{\
		if (limit > 0) \
			(number >= 0 && number < limit) ? (cout << "true") : (cout << "false"); \
		else \
			(number <= 0 && number > limit) ? (cout << "true") : (cout << "false"); \
	}\
	cout << "\n\n\n";
//End of Task 2 - part 1.======================================================================================================================//	




//Task 3 - part 1.=============================================================================================================================//
#define T3_ARR_SIZE 7
#define SwapINT(a, b) \
	if (a > b) \
	{\
		a = a ^ b; \
		b = a ^ b; \
		a = a ^ b; \
	}\

bool T3_BubleSortIntArr1D(int* arr, const size_t & size)
{
	if (size < 1)
		return false; 
	 
	for (size_t i{ 1 }; i < size; i++)
	{
		for (size_t j{ 1 }; j <= size - i; j++)
		{
			SwapINT(arr[j - 1], arr[j]);
		}
	}
	return true; 
}

void T3_PrintIntArr1D(const int* arr, const size_t& size)
{
	for (size_t i{ 0 }; i < size; i++)
	{
		std::cout << arr[i] << "  ";
	}
}	
//End of Task 3 - part 1.======================================================================================================================//	




//Task 4 - part 1.=============================================================================================================================//
struct Employee0 {
	unsigned long Id;
	unsigned short BirthYear;
	int DepartmentId;
	double Salary; 
};

#pragma pack(push, 1)
struct Employee {
	unsigned long Id; 
	unsigned short BirthYear; 
	int DepartmentId; 
	double Salary; 
};
#pragma pop

bool T4_WriteStructEmployeeToTxtFile(const Employee* emp, const string& filename)
{
	if (filename == "" || filename == " ")
		return false; 
	string FullFileName{ filename + ".txt" }; 
	
	if (fs::exists(FullFileName))
		fs::remove(FullFileName); 

	ofstream file(FullFileName); 
	if (file.is_open())
	{
		file << emp->Id << "\n";
		file << emp->BirthYear << "\n";
		file << emp->DepartmentId << "\n";
		file << emp->Salary << "\n";
		file.close();
		return true;
	}
	else
		return false;
}

void T4_PrintTextFile(const string& name)
{
	ifstream file(name + ".txt");
	if (file.is_open())
	{
		string buffer{ " " };
		while (!file.eof())
		{
			getline(file, buffer);
			cout << buffer << "\n";
		}
		file.close();
	}
}
//End of Task 4 - part 1.======================================================================================================================//	




int main()
{
//Task 1 with a namespace (Task 5) - part 2.===================================================================================================//
	cout << "Task 1 with a namespace (Task 5).============================================\n\n"; 
	        
	const size_t T1_ARR_SIZE{ 24 }; 
	float T1_fArr1D[T1_ARR_SIZE]; 
	if (MyLib::T1_InitFloatArr1D(T1_fArr1D, T1_ARR_SIZE))
	{
		cout << "  Float 1D array \"T1_fArr1D[" << T1_ARR_SIZE << "]\" has been initialised with the values:\n"; 
		MyLib::T1_PrintFloatArr1D(T1_fArr1D, T1_ARR_SIZE);  
		cout << "\n\n"; 
		MyLib::NonZeroElements NZE_T1_fArr1D = MyLib::T1_CountNonZeroElementsInFloatArr1D(T1_fArr1D, T1_ARR_SIZE); 
		cout << "  The array \"T1_fArr1D[" << T1_ARR_SIZE << "]\" contains:\n"
			 << "    " << NZE_T1_fArr1D.positives << " positive elements,\n"
			 << "    " << NZE_T1_fArr1D.negatives << " negative elements.\n";
		cout << "\n\n";
	}
	else
	{
		cerr << "  Error: the function \"MyLib::T1_InitFloatArr1D(T1_fArr1D, " << T1_ARR_SIZE << ")\" does not return \"true\"\n\n";
	}
//End of Task 1 with a namespace (Task 5) - part 2.============================================================================================//	

	


//Task 2 - part 2.=============================================================================================================================//
	cout << "Task 2.======================================================================\n\n"; 
	
	cout << "  Enter a number: "; 
	double T2_dNumber{ 0 }; 
	cin >> T2_dNumber; 

	double T2_dLimit{ 173.9 }; 
	cout << "  The set limit value: " << T2_dLimit << "\n";
	
	cout << "  " << T2_dNumber << " belongs to the range from 0 (inclusive) to " << T2_dLimit << " (exclusive): ";
	T2_CHECK_NUMBER(T2_dNumber, T2_dLimit) 
//End of Task 2 - part 2.======================================================================================================================//	




//Task 3 - part 2.=============================================================================================================================//
	cout << "Task 3.======================================================================\n\n"; 

	int T3_iArr1D[T3_ARR_SIZE]; 
	cout << "  Enter " << T3_ARR_SIZE << " integers to initialise the array \"T3_iArr1D[" << T3_ARR_SIZE << "]:\n"; 
	for (size_t i{ 0 }; i < T3_ARR_SIZE; i++)
	{
		cin >> T3_iArr1D[i]; 
	}
	cout << "\n"; 
		
	cout << "  The array \"T3_iArr1D[" << T3_ARR_SIZE << "] before sort:\n";
	T3_PrintIntArr1D(T3_iArr1D, T3_ARR_SIZE); 
	cout << "\n\n";

	if (T3_BubleSortIntArr1D(T3_iArr1D, T3_ARR_SIZE))
	{
		cout << "  The array \"T3_iArr1D[" << T3_ARR_SIZE << "] after sort:\n"; 
		T3_PrintIntArr1D(T3_iArr1D, T3_ARR_SIZE);
		cout << "\n\n\n"; 
	}
	else
	{
		cerr << "  Error: the function \"T3_BubleSortIntArr1D(T3_iArr1D, " << T3_ARR_SIZE << ")\" does not return \"true\"\n\n\n";
	}
//End of Task 3 - part 2.======================================================================================================================//	




//Task 4 - part 2.=============================================================================================================================//
	cout << "Task 4.======================================================================\n\n";

	Employee* pE = new Employee; //struct with #pragma pack
	pE->Id = 1234567; 
	pE->BirthYear = 1984; 
	pE->DepartmentId = 209; 
	pE->Salary = 120'000.00; 
	
	cout << "  The struct \"Employee\" (with #pragma pack) has been dynamically initialised\n"
		 << "  (local Employee pointer pE = " << pE << ") with the next content: \n"
		 << "    Id: " << (*pE).Id << "\n"
		 << "    BirthYear: " << (*pE).BirthYear << "\n"
		 << "    DepartmentId: " << (*pE).DepartmentId << "\n"
		 << "    Salary: " << (*pE).Salary << "\n"; 
	cout << "\n\n";

	cout << "  The size of that struct with #pragma pack is " << sizeof(*pE) << " bytes.\n"
		 << "  (size of the same struct without #pragma pack is " << sizeof(Employee0) << " bytes)\n";  
	cout << "\n\n";

	cout << "  Enter the name for txt-file (without extension) to save the struct: "; 
	string name{ " " }; 
	cin >> name; 
	cout << "\n";

	if (T4_WriteStructEmployeeToTxtFile(pE, name))
	{
		cout << "  The struct has been saved into the file \"" << name << ".txt\" with the next content:\n";
		T4_PrintTextFile(name); 
		cout << "\n\n";
		delete pE; 
		pE = nullptr; 
	}
	else
	{
		cerr << "  Error: the function \"T4_WriteStructEmployeeToTxtFile(pE, " << name << ")\" does not return \"true\"\n\n\n";
	}
//End of Task 4 - part 2.======================================================================================================================//	

    return 0;
}