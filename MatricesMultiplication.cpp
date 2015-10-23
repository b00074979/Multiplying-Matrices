/*Assignment 3 - Matrices*/

/* ------------------------------------------------------------

Programmer: Aleena Chaudhry

ID: B00074979

Date: 25th April 2015

Purpose: Multiplication of two Matrices from a file

------------------------------------------------------------*/
#include "std_lib_facilities.h"

#include <iostream>

using namespace std;


int main()
{

    ifstream infile("input1.txt");//opening file to read

    int c[10][10];
    int rA, cA, rB, cB,m,i,j;// declaring Variables

    infile >> rA >> cA;//reading columns and rows of Matrix A

    int a[rA][cA];

    for(int i=0; i<rA; i++) //reading the variables of Matrix A from file
        {
            for(int j=0; j<cA; j++)
        {
            infile >> a[i][j];
        }
    }
    cout << endl;

    cout<< "Matrix A:\n" << endl;

    for(int i=0; i<rA; i++)
    {
        for(int j=0; j<cA; j++)
        {
       cout << a[i][j] << ' '; //outputting Variables of Matrix A on screen
        }
        cout << endl;
    }

  infile >> rB >> cB;// Repeating the reading of the file for Matrix B - rows/columns and its contents

    int b[rB][cB];

    for(int i=0; i<rB; i++)
    {
        for(int j=0; j<cB; j++)
        {
            infile >> b[i][j];
        }
    }
    cout << endl;

     cout<< "Matrix B:\n" << endl;

    for(int i=0; i<rB; i++)
    {
        for(int j=0; j<cB; j++)
        {
       cout << b[i][j] << ' ';
        }
        cout << endl;
    }


    //Multiplication Logic

    if (cA== rB){ //Multiplication can only occur if the #columns of matrixA = #rows of Matrix B else enter new values.

    for(i=0;i<rA;i++)
        {
            for(j=0;j<cB;j++)
            {
                c[i][j]=0;

                for(int m=0;m<rB;m++)
                {
                    c[i][j] = c[i][j] + a[i][m] * b[m][j]; // multiplication of the two matrices
                }
            }
        }

        cout <<"\n\n";

        cout <<"\n\nMultiplication of Matrix A and Matrix B :\n\n";

        for(i=0;i<rA;i++)
        {
            for(j=0;j<cB;j++)
            {
                cout<<"\t"<<c[i][j]; // prints out the result of Matrix AB= C
            }
            cout<<"\n\n";
        }
    } // end of if statement


    else
    {
        cout << "\n\nError!!\n Enter new values\n\n";
    }


 // OPENING FILE TO OUTPUT RESULT
   ofstream outfile;
   outfile.open ("outC.txt");
   outfile << "The product of Matrix A and B = C\n\n\n"<<c[i][j]; // outputs result in text file outC
   outfile.close();
    return 0;
}

