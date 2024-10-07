#include"Attraction.h"
#include<iostream>
using namespace std;
class Ride:public Attraction
{
    private:
    float Speed_Of_Ride;
    public:
    Ride(string n,float p,int a,string t,int s,float sor):Attraction(n,p,a,t,s)
    {
        Speed_Of_Ride=sor;
    }
    void GetInfo()
    {
        Attraction::GetInfo();
        cout<<"Enter Speed of ride: ";
        cin>>Speed_Of_Ride;
    }
    void ShowInfo()
    {
        Attraction::ShowInfo();
        cout<<"Speed of Ride: "<<Speed_Of_Ride<<"m/s"<<endl;
    }
    bool IsSafe()
    {
        if(Speed_Of_Ride<=100.0)
        return true;
        else
        return false;
    }
    string TypeOfAttraction()
    {
        return "Ride";
    }
    float ChildAttribute()
    {
        return Speed_Of_Ride;
    }
};
