#include"Attraction.h"
#include<iostream>
using namespace std;
class EntertainmentShow:public Attraction
{
    private:
    float Safety_Rating;
    public:
    EntertainmentShow(string n,float p,int a,string t,int s,float sr):Attraction(n,p,a,t,s)
    {
        Safety_Rating=sr;
    }
    void GetInfo()
    {
        Attraction::GetInfo();
        cout<<"Enter Safety Rating: ";
        cin>>Safety_Rating;
    }
    void ShowInfo()
    {
        Attraction::ShowInfo();
        cout<<"Safety Rating: "<<Safety_Rating<<"/10"<<endl;
    }
    bool IsSafe()
    {
        if(Safety_Rating>=5&&Safety_Rating<=10)
        return true;
        else
        return false;
    }
    string TypeOfAttraction()
    {
        return "Entertainment Show";
    }
    float ChildAttribute()
    {
        return Safety_Rating;
    }
};
