// 2021-11-26_Webinar_Homework_tasks4-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// homework (task 4 - 5, and task 3 as a starting point) - Webinar of November, 26, 2021
// Created by Daniil Nesterov (e-mail: maidanov1991@yandex.ru)

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <filesystem> 

namespace fs = std::filesystem; 
using namespace std; 

//Task 3 - Part 1.================================================================================================================================//
//Write a program which creates two text files (*.txt) with about 50-100 symbols inside each of them (content does not particularly matter). 
//The files' names should be requested from the user. 

bool T3_CreateTextFile01(const string& name)
{
    if (name == "" || name == " ")
        return false; 

    srand(time(nullptr)*2);
    int limit{ rand() % 50 + 40 };
    ofstream file(name + ".txt"); 
    if (file.is_open())
    {
        file << "__FILE_1__"; 
        for (int i{ 0 }; i <= limit; i++)
        {
            file << (char)(rand() % 94 + 32);
        }
        file.close();
        return true; 
    }
    else
        return false;
}

bool T3_CreateTextFile02(const string& name)
{
    if (name == "" || name == " ")
        return false;

    srand(time(nullptr)/2);
    int limit{ rand() % 50 + 40 };
    ofstream file(name + ".txt");
    if (file.is_open())
    {
        file << "__FILE_2__";
        for (int i{ limit }; i >= 0; i--)
        {
            file << (char)(rand() % 94 + 32);
        }
        file.close();
        return true;
    }
    else
        return false;
}

void T3_PrintTextFile(const string& name)
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
//End of Task 3 - Part 1.=========================================================================================================================//




//Task 4 - Part 1.================================================================================================================================//
//Write a function "glueing" two txt-files into a third txt-file. 
//The files' names should be requested from the user. 

bool T4_GlueTwoTextFilesIntoNewOne(const string& name1, const string& name2, const string& name3)
{
    if (name1 == "" || name1 == " " || name2 == "" || name2 == " " || name3 == "" || name3 == " " || name1 == name2 || name2 == name3 || name3 == name1) 
        return false; 
    
    string name01{name1 + ".txt"}, name02{ name2 + ".txt" }, name03{ name3 + ".txt" }; 
    
    if (fs::exists(name01) && fs::exists(name02))
    {
        if (fs::exists(name03))
        {
            fs::remove(name03); 
        }
        fs::copy_file(name01, name03);

        ifstream file1(name01);
        ofstream file3(name03);
        if (file1.is_open() && file3.is_open())
        {
            string buffer{ " " };
            while (!file1.eof())
            {
                getline(file1, buffer);
                file3 << buffer;
            }
            file1.close();

            ifstream file2(name02);
            if (file2.is_open())
            {
                while (!file2.eof())
                {
                    getline(file2, buffer);
                    file3 << buffer;
                }
                file2.close();
            }
            file3.close();
        }
        return true;
    }
    else
        return false;
}
//End of Task 4 - Part 1.=========================================================================================================================//




//Task 5 - Part 1.================================================================================================================================//
//Write a program which checks if there is a word specified by the user during the program launch in the user-specified file  
//(for simplicity work with the Latin alphabet only). 
//Use the function "find" that is in strings std::string.  

short int T5_CheckForSpecifiedWord(const string& word, const string& FileName)
{
    string filename{ FileName + ".txt" };
    ifstream file(filename); 
    if (file.is_open())
    {
        string buffer;
        while (!file.eof())
        {
            getline(file, buffer);
            if (buffer.find(word) != string::npos)
            {
                file.close();
                return 1;
            }
        }
        return 0;
    }
    else
        return -1; 
}
//End of Task 5 - Part 1.=========================================================================================================================//




int main()
{
//Task 3 - Part 2.================================================================================================================================//

    cout << "Task 3.============================================================\n\n"
         << "  The program creates two txt-files with the names defined by the user\n"
         << "  and with some content about 50-100 symbols inside each of the files.\n";

    cout << "  Please, enter two different names for the txt-files (without extension):\n    ";

    string name1{ " " }, name2{ " " }; 
    cin >> name1 >> name2; 

    while (name1 == name2)
    {
        cout << "\n  Please, enter another name for the second file (without extension):\n    ";
        cin >> name2;
    }
    cout << "\n\n";

    if (T3_CreateTextFile01(name1))
    {
        cout << "  File \"" << name1 << ".txt\" has been created with the content:\n    ";
        T3_PrintTextFile(name1); 
    }
    else
        cout << "  Error! The function \"T3_CreateTextFile01(" << name1 << ")\" does not return \"true\"\n"; 

    cout << "\n\n";
    
    if (T3_CreateTextFile02(name2))
    {
        cout << "  File \"" << name2 << ".txt\" has been created with the content:\n    ";
        T3_PrintTextFile(name2);
    }
    else
        cout << "  Error! The function \"T3_CreateTextFile02(" << name2 << ")\" does not return \"true\"\n";

    cout << "\n\n";
//End of Task 3 - Part 2.=========================================================================================================================//




//Task 4 - Part 2.================================================================================================================================//
   
    cout << "Task 4.============================================================\n\n"
         << "  The program inserts content of two existing txt-files into a new txt-file.\n"
         << "  The names of all three files are defined by the user and should be different.\n\n";

    cout << "  Please, enter the names (without extension) of the two existing txt-files\n"
         << "  content of that should be inserted to a new txt-file:\n    ";

    cin >> name1 >> name2;
    while (name1 == name2)
    {
        cout << "\n  Please, enter another name for the second file (without extension):\n    ";
        cin >> name2;
    }
    cout << "\n\n";

    cout << "  Please, enter a name (without extension) of the new txt-file\n"
         << "  in which content of the two choosed existing txt-files should be inserted:\n    ";
        
    string name3{ " " }; 
    cin >> name3; 
    while (name3 == "" || name3 == " " || name3 == name1 || name3 == name2)
    {
        cout << "\n  Please, enter another name for the new file (without extension):\n    ";
        cin >> name3;
    }

    cout << "\n\n";
    
    if (T4_GlueTwoTextFilesIntoNewOne(name1, name2, name3))
    {
        cout << "  File \"" << name3 << ".txt\" has been created with the content:\n    ";
        T3_PrintTextFile(name3);
    }
    else
        cout << "  Error! The function \"T4_GlueTwoTextFilesIntoNewOne(" << name1 << ", " << name2 << ", " << name3 << ")\" does not return \"true\"\n";

    cout << "\n\n";

//End of Task 4 - Part 2.=========================================================================================================================//




//Task 5 - Part 2.================================================================================================================================//

    cout << "Task 5.============================================================\n\n"
         << "  The program checks if there is a word specified by the user.\n"
         << "  in the user specified txt-file.\n\n";

    cout << "  Please, enter the word for checking:\n    "; 

    string word{ " " }, filename{" "}; 
    cin >> word; 
    while (word == "" || word == " ")
    {
        cout << "\n  Please, enter the word for checking:\n    ";
        cin >> word;
    }
    cout << "\n\n";
    
    cout << "  Please, enter the name of an existing txt-file (without extension) to search the word:\n    ";
    cin >> filename; 
    while (filename == "" || filename == " ")
    {
        cout << "\n  Please, enter the name of na existing txt-file (without extension) to search the word:\n    ";
        cin >> filename;
    }
    cout << "\n";

    if (T5_CheckForSpecifiedWord(word, filename) == 1) 
        cout << "\n    The word \"" << word << "\" has been found in the file \"" << filename << ".txt\" :)\n"; 
    else
    { 
        if ((T5_CheckForSpecifiedWord(word, filename) == 0))
        {
            cout << "\n    The word \"" << word << "\" has not been found in the file \"" << filename << ".txt\" :(\n";
        }
        else
            cout << "  Error! The function \"T5_CheckForSpecifiedWord(" << word << ", " << filename << ")\" returns \"-1\"\n"
                 << "  (possibly the file \"" << filename << ".txt\" does not exist or can not be opened)";
    }
    cout << "\n\n";
//End of Task 5 - Part 2.=========================================================================================================================//

    return 0;
}