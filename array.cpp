#include "array.h"

Array::Array(int N){
    a = new int[N]; n= N;
}
Array::Array(int *b, int m){
  a = new int[m];
  for(int i = 0; i < m; i++){
     a[i] = b[i];
   }
 n = m;
}
Array::Array(const Array &X){
  n = X.n;
  a = new int[n];
  for(int i = 0; i < n; i++){
    a[i] = X.a[i];
  }
}
Array & Array:: operator = (const Array &X){
   if(this!= &X){
     delete []a;
     n = X.n;
     a = new int [n];
     for(int i = 0; i < n; i++){
        a[i] = X.a[i];
     }
   }
   return *this;
}
Array::~Array(){
  delete []a;
}

void Array:: Scan(int m){
    const string NumbersText = (m>1)?"s":"";
    cout << "Enter " << m << " number"<< NumbersText <<" of the array: ";
    srand(time(0));

    if(n == m){
       for(int i  = 0; i < m; i++){
        cin >> a[i];

         //a[i] = rand()%100;
       }
    }else {
      delete []a;
      a = new int[m];
      for(int i = 0; i < m; i++){
          cin>> a[i];
      }
      n = m;
    }
}

int & Array::operator [] (int i){
  if(i < 0){
    cout<<"Incorrect index! "<< i << " is less than 0" << endl;
    return a[0];
  }else if(i > n) {
    cout <<"Incorrect index! "<< i << " is more than "<< n <<endl;
   return a[n-1];
  }
  return a[i];
}

Array & Array::operator += (int key){
   int *temp = new int [n + 1];
   for(int i =0; i < n; i ++){
     temp[i] = a[i];
   }
   temp[n] = key;
   delete []a;
   a = temp;
   n++;
   return *this;
}

Array Array::operator + (int key){
   Array newObj(n+1);
   for(int i = 0; i < n; i++){
       newObj.a[i] = a[i];
   }
   newObj.a[n] = key;
   return newObj;
}

Array Array::operator + (Array &X){
   Array newObj(n+X.n);
   int j = 0;
   for(int i = 0; i < n+X.n; i++){
        if(i < n){
            newObj.a[i] = a[i];
        }else {
            newObj.a[i] = X.a[j++];
        }
   }
   return newObj;
}

void Array:: Print(){
cout <<endl;// << "*******************" <<endl;
 for(int i = 0; i < n; i++){
  cout<< a[i] << ' ';
 }
cout <<endl; // << "******************************" <<endl;
}

int Array::Max(){
 int max_num = 0;
 for(int i = 0; i < n; i++){
   if(a[i] > a[max_num]){
      max_num = i;
   }
 }
 return max_num;
}

int Array::Min(){
 int min_num = 0;
 for(int i = 0; i < n; i++){
   if(a[i] < a[min_num]){
      min_num = i;
   }
 }
 return min_num;
}

int Array::FindKey (int key){
    for(int i =0; i < n; i++){
        if(a[i] == key)return i;
    }
    return -1;
}

bool Array::operator==(Array &X){
    if(n == X.n){
       for(int i =0; i < n; i++){
        if(a[i] != X.a[i]){return false;}
        }
        return true;
    }else {
        return false;
    }
}
bool Array::operator != (Array &X){
       if(n != X.n){
        return true;
    }else {
       for(int i =0; i < n; i++){
        if(a[i] != X.a[i]){return true;}
        }
        return false;
    }
}

Array & Array::operator -= (int key){
    int i, j = 0, found = 0;
    for(i = 0; i < n; i++){
        if(a[i] != key){
            a[j++] = a[i];
        }else {
            found++;
        }
    }
    if(found == 0){
        cout <<"The number ("<<key<<") does not exist"<<endl;
    }else {
        for(i = found; i > 0; i--){
            a[n - 1] = {};
            n--;
        }
    }
    return *this;
}

Array & Array::operator += (Array &X){
    int i, j = 0;
    int * newArray = new int[n+X.n];
    for(i = 0; i < n + X.n; i++){
        if( i < n ){
            newArray[i] = a[i];
        }else {
            newArray[i] = X.a[j++];
        }
    }
    delete []a;
    n = n+ X.n;
    a = newArray;
    return *this;
}


Array & Array::DelPosEq(int pos){
  int i, j, found = 0;
  for (i =0; i < n; i++){
    if(i == pos){
       for(j = i; j< n-1; j++){
          a[j] = a[j+1];
       }
       found++;
       n--;
       a[n] = {};
       //break;
    }
  }
   if(found == 0){
       cout <<"The number with the index ("<< pos <<") does not exist!"<<endl;
    }else {
       cout <<"The number with the index ("<< pos <<") deleted successfully."<<endl;
    }
    return *this;
}
Array & Array::DelPosNew( int pos){
    int i, j=0, * b;
    if(pos >=0 && pos < n){
        b = new int [n-1];
        for(i = 0; i < n; i++){
            if(pos != i){ b[j++] = a[i];};
        }
    }else{
        b = new int [n];
        for(i = 0; i < n; i++)b[i] = a[i];
       cout <<"The number with the index ("<< pos <<") does not exist!"<<endl;
    }

    return *this;
}
void Array::Sort(){
   for(int i =0; i < n; i++){
       for(int j = i; j < n; j++){
          if(a[j] < a[i]){
             int temp = a[i];
             a[i] = a[j];
             a[j] = temp;
           //  a[i] = a[j] + (a[j]=a[i]) - a[i] ;
          }
       }
   }
}

ostream & operator << (ostream &r, Array &X){
     for(int i = 0; i < X.n; i++){
            cout<< X.a[i] << ' ';
        }
    cout <<"*****************"<<endl;
    return r;
}

istream & operator >> (istream &r, Array &X){
    int m;
    const string NumbersText = (m>1)?"s":"";
    cout << "Enter the number of the array: ";
    cin >> m;
    cout << "Enter " << m << " number"<< NumbersText <<" of the array: ";
    if(X.n == m){
       for(int i  = 0; i < m; i++){
          cin >> X.a[i];
       }
    }else {
      delete []X.a;
      X.a = new int[m];
      for(int i = 0; i < m; i++){
          cin >> X.a[i];
      }
      X.n = m;
    }
    return r;
}
void Array::ShiftLeft(int pos){
    int temp, i, j;
    for(j  = 0; j< pos; j++){
        temp = a[0];
        for(i = 0; i < n; i++){
            a[i] = a[i+1];
        }
        a[n-1] = temp;
    }
}

int Array::getN(){
    return n;
}
