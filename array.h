#pragma once
#include <istream>
#include <iostream>

using namespace std;

class Array
{
 public:
 int *a, n;
    //Array();
    Array(int N=5);
    Array(int *, int);
    Array(const Array &x);
    Array & operator = (const Array &x);
     ~Array();
    void Scan(int m=5);
    int & operator [] (int i);
    void Print();
    int FindKey(int key);
     Array & operator += (int key);
     Array operator +(int key);
     Array operator + (Array &X);
     Array & operator +=(Array &x);
     Array & operator -=(int key);
     Array operator -(int key);
     Array & DelPosEq(int pos);
     Array & DelPosNew(int pos);
     bool operator == (Array &x);
     bool operator != (Array &x);
    int Max();
    int Min();
    void Sort();
    friend ostream & operator << (ostream &r, Array &x);
    friend istream & operator >> (istream &r, Array &x);

    void ShiftLeft(int pos);
    int getN();
};
