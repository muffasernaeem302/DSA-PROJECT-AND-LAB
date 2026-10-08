#include <iostream>

using namespace std;


// TASK 1 ;

int factorial(int Num )
{
    int sum = 0;
    int Result  = 1 ;

 for (int i = 1 ; i <= Num; i++ )
 {
     Result  = Result * i;
 }
 return Result;

}

// TASK 2 ;

int fibbonacci(int n){
int a1 = 0 ;
int b1 = 1 ;
int Next ;


for ( int i = 0 ; i < n ; i ++)
{
   cout << " a " <<"="<<a1 << endl;
    cout <<endl;

    Next = a1 + b1;
    a1 = b1 ;
    b1 = Next ;
}
return Next;
}


int main()
{
    cout<<" LAB TASKS : " <<endl;
    int TASK ;
    cout <<" ENTER ONE for TASK 1  " << endl;
    cout <<" ENTER TWO for TASK 2  " << endl;
    cout <<" ENTER THREE for TASK 3  " << endl;
    cout <<" ENTER FOUR for TASK 4  " << endl;
    cout <<" ENTER FIFTH for TASK 5  " << endl;
    cout <<" ENTER SIXTH for TASK 6  " << endl;

    cin >> TASK;

  if(TASK == 1) {
cout <<" Here We Will do our FIRST  Task "<< endl;

 int Number ;

cout << " Enter the Number u wanna take the factorial "<< endl;

 cin >> Number ;

int Ans = factorial(Number);

cout << "Number of factorial = " << Ans << endl;

  }


if(TASK==2)
{


   cout <<" FIBBONACCI SEQUENCE "<<endl;

cout <<" Here We Will do our SECOND Task "<< endl;

int n = 10 ;

int Next1 = fibbonacci(n);

cout <<" The fibboNacci sequence of the Numbers are "<< Next1<<endl;
}
}
/*
    if(TASK == 3 )
        {
cout << " GREATEST OF ALL AMONG "<< endl;

cout <<"  Here We Will do our Third Task " << endl;

int num1 ;
cout <<" Enter the Digit :"<< endl;

cin >> num1 ;
int num2 ;
cout <<" Enter the Digit :"<< endl;
cin>> num2 ;
int num3 ;
cout <<" Enter the Digit :"<< endl;
cin >> num3 ;


int result ;

if ( num1 > num2&& num1 > num3 )
{
    result = num1 ;
}
 if( num2 > num1 && num2 > num3 )
{
result = num2 ;

}
if( num3 > num2 && num3 > num1 )
{
    result = num3;
}

cout <<" The Greatest Among ALL IS GIVEN :" << result << endl;

cout <<"GREATEST COMMON DIVISOR "<<endl;
        }

        if (TASK ==4 )
        {

cout <<"  Here We Will do our Fourth Task " << endl;

int a ;
int b ;

cout<< " Enter the Both Digits One by One "<< endl;

cin >> a;
 cout << " Second Digit "<< endl;

cin >> b ;

while ( b != 0 )
{
    int reminder = a % b;
    a = b ;
    b = reminder ;
}
 cout <<" The Greatest common Divisor "<<a  << endl;


        }
        if (TASK == 5)
        {
 cout <<" LEAST COMMON DIVISOR "<<endl;


 cout <<"  Here We Will do our Fifth Task " << endl;

int a2 ;
int b2 ;

cout<< " Enter the Both Digits One by One "<< endl;

cin >> a2;
cout << " Second Digit "<< endl;

cin >> b2 ;

 int LCM ;
 LCM = ( a2 * b2);
while ( b2 != 0 )
{
    int reminder = a2 % b2;
    a2 = b2 ;
    b2 = reminder ;
}
 cout <<" The Greatest common Divisor "<< a2  << endl;

LCM = LCM/ a2 ;

cout <<" The Lcm of the Given NUM is = "<< LCM << endl;

        }


   if (TASK == 6)
   {
    cout <<"  Here We Will do our SIXTH Task " << endl;
      cout <<" FIND THE REEVRSE OF DIGITS "<< endl;
      int Number1 ;
      int Rev = 0 ;
      int count = 0 ;

      cout <<" ENTER THE NUMBER "<<endl;

      cin >> Number1;
/*
      int rev1 = Number1 % 10;

      int rev2 =Number1/10;

      cout <<" The REv of the Num = "<< rev1<<rev2 << endl;

while (Number1 > 0 )
{
    int digit = Number1 % 10 ;

    Rev = Rev * 10 + digit ;

    Number1 = Number1 / 10 ;

    count++;

}
cout <<" The Reverse of the Given Number = " << Rev<< endl;
cout << " THE Total NUMBERS OF DIGITS ARE = "<< count << endl;


   }

}
*/

