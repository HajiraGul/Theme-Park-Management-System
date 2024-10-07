#pragma once
#include<iostream>
#include<string>
using namespace std;
class Attraction
{
    private:
    string Name;
    float Price_Per_Head;
    int Age;
    string Time_Duration;
    int Seat_Capacity;
    public:
    Attraction(string n,float p,int a,string t,int s)
    {
        Name=n;
        Price_Per_Head=p;
        Age=a;
        Time_Duration=t;
        Seat_Capacity=s;
    }
    virtual void GetInfo()
    {
        int error=0;
        do
        {
            try
            {
                cout<<"Enter Name of Attraction: ";
                getline(cin,Name);
                cout<<"Enter Time Duration: ";
                getline(cin,Time_Duration);
                cout<<"Enter Price of Attraction per head: ";
                cin>>Price_Per_Head;
                cout<<"Enter Age: ";
                cin>>Age;
                cout<<"Enter seat capacity of Attraction: ";
                cin>>Seat_Capacity;
                if (Price_Per_Head<0||Age<0||Seat_Capacity<0)
                {
                    error = 1;
                    throw error;
                }
                else
                {
                    error=0;
                }
            }
            catch (int errorCode)
            {
                if(error==1)
                cout << "Error: Invalid input. Numeric values cannot be negative." << endl;
                else
                cout << "Unknown error." << endl;
                cin.ignore();
                
            }
        }
        while(error==1);
    }
    virtual void ShowInfo()
    {
        cout<<"Name: "<<Name<<endl;
        cout<<"Price per head: "<<"Rs."<<Price_Per_Head<<endl;
        cout<<"Age: "<<Age<<"+"<<endl;
        cout<<"Time Duration: "<<Time_Duration<<endl;
        cout<<"Seat Capacity: "<<Seat_Capacity<<endl;
    }
    string TellName()
    {
        return Name;
    }
    float TellPrice_Per_Head()
    {
        return Price_Per_Head;
    }
    int TellAge()
    {
        return Age;
    }
    string TellTime_Duration()
    {
        return Time_Duration;
    }
    int TellSeat_Capacity()
    {
        return Seat_Capacity;
    }
    int UpdateAndTellSeat_Capacity(int numTickets)
    {
        Seat_Capacity -= numTickets;
        return Seat_Capacity;
    }
    virtual bool IsSafe()=0;
    virtual string TypeOfAttraction()=0;
    virtual float ChildAttribute()=0;
    void operator+(float amount)
    {
        Price_Per_Head=Price_Per_Head+amount;
    }
    void operator-(float amount)
    {
        Price_Per_Head=Price_Per_Head-amount;
    }
    bool operator==( Attraction& a)
    {
        return (Price_Per_Head == a.Price_Per_Head);
    }
};
