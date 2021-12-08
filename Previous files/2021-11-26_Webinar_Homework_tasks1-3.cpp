// 2021-11-26_Webinar_Homework.cpp
// homework (task 1 - 3) - Webinar of November, 26, 2021
// Created by Daniil Nesterov (e-mail: maidanov1991@yandex.ru)

#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

size_t RequestArraySize()
{
    while (true)
    {
        cout << "  Please, enter a number of elements for array: "; 
        size_t number{ 0 }; 
        cin >> number; 
        if (cin.fail() || number < 1)
        {
            cerr << "Error! Please enter a positive integer value!\n"; 
            cin.clear(); 
            cin.ignore(32767, '\n'); 
        }
        else
        {
            cout << "\n";
            return number; 
        }
    }
}

//Task 1 - Part 1.================================================================================================================================//
//Allocate in memory dynamic one-dimensional int array. 
//Request the array's size from the user.  
//Initialise it with the numbers of powers of two: 1, 2, 4, 8, 16, 32, 64, 128, ...
//Display the array. 
//Do not forget to free up the memory. 
//Break the program into functions. 

bool T1_InitIntArray1D(int* arr, const size_t& size)
{
    if (size < 1 || size > 31)
        return false; 
    arr[0] = 1; 
    for (size_t i{ 1 }; i < size; i++)
    {
        arr[i] = arr[i - 1] * 2; 
    }
    return true;
}


int* T1_NewDynIntArray1D(const size_t& size)
{
    int* iArr1D = new (nothrow) int [size];  
    if (T1_InitIntArray1D(iArr1D, size))
        return iArr1D; 
    else
        return nullptr; 
}


int* T1_DelDynIntArray1D(int* arr) 
{
    delete[] arr; 
    arr = nullptr; 
    return arr;  
}


void T1_PrintIntArray1D(const int* arr, const size_t& size)
{
    cout << "     ";
    for (size_t i{ 0 }; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\n";
}
//End of Task 1 - Part 1.=========================================================================================================================//




//Task 2 - Part 1.================================================================================================================================//
//Dynamically allocate an int matrix 4x4. 
//Initialise it with pseudo random numbers by rand function. 
//Display the matrix.  
//Break the program into the functions that are called from main. 

bool T2_InitIntArray2D(int** arr, const size_t& size1, const size_t& size2)
{
    if (size1 < 1 || size1 > 31 || size2 < 1 || size2 > 31)
        return false;
    
    srand(time(nullptr)); 

    for (size_t i{ 0 }; i < size1; i++)
    {
        for (size_t j{ 0 }; j < size2; j++)
        {
            arr[i][j] = rand() % 100;  
        }
    }
    return true;
}


int** T2_NewDynIntArray2D(const size_t& size1, const size_t& size2)
{
    int** iArr2D = new (nothrow) int*[size1]; 
    for (size_t i{ 0 }; i < size1; i++)
    {
        iArr2D[i] = new int[size2]; 
    }
    if (T2_InitIntArray2D(iArr2D, size1, size2))
        return iArr2D;
    else
        return nullptr;
}


int** T2_DelDynIntArray2D(int** arr, const size_t& size1)
{
    for (size_t i{ 0 }; i < size1; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
    return arr;
}


void T2_PrintIntArray2D(int** arr, const size_t& size1, const size_t& size2)
{
    for (size_t i{ 0 }; i < size1; i++)
    {
        cout << "     ";
        for (size_t j{ 0 }; j < size2; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << "\n"; 
    }
    cout << "\n";
}
//End of Task 2 - Part 1.=========================================================================================================================//




//Task 3 - Part 1.================================================================================================================================//
//Write a program which creates two text files (*.txt) with about 50-100 symbols inside each of them (content does not particularly matter). 
//The files' names should be requested from the user. 

bool T3_CreateTextFile(const string& name)
{
    if (name == "")
        return false; 
    
    srand(time(nullptr)); 
    int limit = rand() % 50 + 50; 
    ofstream fout(name + ".txt"); 
    char c1{ '~' }; 
    for (int i{ 0 }; i <= limit; i++)
    {
        fout << (char)(c1 - i); 
    }
    fout.close(); 
  
    return true; 
}


void T3_DisplayTextFileContent(const string& name)
{
    ifstream fin(name + ".txt"); 

    if (fin.is_open())
    {
        string buffer; 
        while (!fin.eof())
        {
            getline(fin, buffer); 
            cout << buffer << "\n"; 
        }
        fin.close(); 
        cout << "\n"; 
    }
}
//End of Task 3 - Part 1.=========================================================================================================================//


int main()
{
//Task 1 - Part 2.================================================================================================================================//
    cout << "Task 1.============================================================\n\n"
         << "  The program allocates in memory\n"
         << "  a dynamic one-dimensional int array of an entered size,\n"
         << "  initialises it with the numbers of powers of two,\n"
         << "  displays the array and then deletes it.\n\n"; 
     
    size_t T1_ReqArrSize = RequestArraySize();  
    const size_t T1_ARR_SIZE{ T1_ReqArrSize }; 
    
    int* T1_ptrDynIntArr1D = T1_NewDynIntArray1D(T1_ARR_SIZE); 
    if (T1_ptrDynIntArr1D != nullptr)
    {
        cout << "  A dynamic int array[" << T1_ARR_SIZE << "] has been allocated.\n"
             << "    (static pointer \"T1_ptrDynIntArr1D\" = " << T1_ptrDynIntArr1D << ")\n\n";

        cout << "  The allocated int array[" << T1_ARR_SIZE << "] has been initialised\n" 
             << "  with the numbers of powers of two:\n";
        
        T1_PrintIntArray1D(T1_ptrDynIntArr1D, T1_ARR_SIZE);

        cout << "\n";

        T1_ptrDynIntArr1D = T1_DelDynIntArray1D(T1_ptrDynIntArr1D); 
        cout << "  The allocated int array[" << T1_ARR_SIZE << "] has been deleted.\n"
             << "    (static pointer \"T1_ptrDynIntArr1D\" = " << T1_ptrDynIntArr1D << ")\n"; 
    }
    else
    {
        cerr << "Error: function \"T1_InitIntArray1D()\" does not return \"true\"\n";
    }
    cout << "\n\n";
//End of Task 1 - Part 2.=========================================================================================================================//




//Task 2 - Part 2.================================================================================================================================//
    cout << "Task 2.============================================================\n\n"; 
   
    const size_t T2_ARR_SIZE_1{ 4 };
    const size_t T2_ARR_SIZE_2{ 4 };

    cout << "  The program allocates in memory a dynamic two-dimensional int array " << T2_ARR_SIZE_1 << "x" << T2_ARR_SIZE_2 << "\n"
         << "  initialises it with pseudo random numbers,\n"
         << "  displays the array and then deletes it.\n\n"; 

    int** T2_ptrDynIntArr2D = T2_NewDynIntArray2D(T2_ARR_SIZE_1, T2_ARR_SIZE_2); 
    if (T2_ptrDynIntArr2D != nullptr)
    {
        cout << "  A dynamic int array[" << T2_ARR_SIZE_1 << "][" << T2_ARR_SIZE_2 <<"] has been allocated.\n"
             << "    (static pointer \"T2_ptrDynIntArr2D\" = " << T2_ptrDynIntArr2D << ")\n\n"; 

        cout << "  The allocated int array[" << T2_ARR_SIZE_1 << "][" << T2_ARR_SIZE_2 << "] has been initialised\n"
             << "  with the pseudo random numbers:\n"; 

        T2_PrintIntArray2D(T2_ptrDynIntArr2D, T2_ARR_SIZE_1, T2_ARR_SIZE_2); 

        cout << "\n";

        T2_ptrDynIntArr2D = T2_DelDynIntArray2D(T2_ptrDynIntArr2D, T2_ARR_SIZE_1); 
        cout << "  The allocated int array[" << T2_ARR_SIZE_1 << "][" << T2_ARR_SIZE_2 << "] has been deleted.\n"
            << "    (static pointer \"T2_ptrDynIntArr2D\" = " << T2_ptrDynIntArr2D << ")\n";
    }
    else
    {
        cerr << "Error: function \"T2_InitIntArray2D()\" does not return \"true\"\n";
    }
    cout << "\n\n";
//End of Task 2 - Part 2.=========================================================================================================================//




//Task 3 - Part 2.================================================================================================================================//
    cout << "Task 3.============================================================\n\n"
        << "  The program creates two txt-files with the names defined by the user\n"
        << "  and with some content about 50-100 symbols inside each of the files. \n"; 

    cout << "  Please, enter two different names for the files (without extension):\n    "; 

    string name1{ " " }, name2{ " " }; 
    cin >> name1 >> name2; 
    
    while (name1 == name2)
    {
        cout << "\n  Please, enter another second name for the file (without extension):\n    "; 
        cin >> name2; 
    }

    cout << "\n\n"; 

    if (T3_CreateTextFile(name1))
    {
        cout << "  File \"" << name1 << ".txt has been created with the content:\n"; 
        T3_DisplayTextFileContent(name1); 

    }
    else
    {
        cerr << "Error: File \"" << name1 << ".txt hasn't been created!\n\n"; 
    }
  
    cout << "\n\n";

    if (T3_CreateTextFile(name2))
    {
        cout << "  File \"" << name2 << ".txt has been created with the content:\n";
        T3_DisplayTextFileContent(name2);
    }
    else
    {
        cerr << "Error: File \"" << name2 << ".txt hasn't been created!\n\n";
    }
    
    cout << "\n\n";
//End of Task 3 - Part 2.=========================================================================================================================//

    return 0; 
}
