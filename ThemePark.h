#include"Attraction.h" 
#include"Ride.h" 
#include"EntertainmentShow.h" 
#include<string> 
#include<fstream> 
using namespace std; 
const int MAX=10;
class ThemePark
{
   Attraction *A[MAX];
    public:
    void ReadFromFile()
{
        string s1, s2, s3, s4, s5, s6, s7;
        ifstream ifile("Data.txt");
        for (int i = 0; i < MAX; i++) 
{
            getline(ifile, s1, ',');
            getline(ifile, s2, ',');
            getline(ifile, s3, ',');
            getline(ifile, s4, ',');
            getline(ifile, s5, ',');
            getline(ifile, s6, ',');
            getline(ifile, s7);

            if (s1 == "Ride") 
            {
                A[i] = new Ride(s2, stof(s3), stoi(s4), s5, stoi(s6), stof(s7));
            } 
           else 
           {
                A[i] = new EntertainmentShow(s2, stof(s3), stoi(s4), s5, stoi(s6), stof(s7));
            }
        }

        ifile.close();
}

    void DisplayAttractions()
    {
        for(int i=0;i<MAX;i++)
        {
            cout<<endl<<"*ATTRACTION: "<<i+1<<endl;
            A[i]->ShowInfo();
        }
    }
    void FindAttraction()
    {
        string a;
        bool found=false;
        cout<<"Enter The name of Attraction to be found: ";
        cin.ignore();
        getline(cin,a);
        for(int i=0;i<MAX&&found==false;i++)
        {
            if(A[i]->TellName()==a)
            {
                cout<<endl<<"*DESIRED ATTRACTION:"<<endl;
                A[i]->ShowInfo();
                found=true;
            }
        }
        if(found==false)
        cout<<"***No Such Attraction found !"<<endl;
    }
    void CheapAttraction()
    {
        float cheap=A[0]->TellPrice_Per_Head();
        int n=0;
        for(int i=0;i<MAX;i++)
        {
            if(cheap>A[i]->TellPrice_Per_Head())
            {
                cheap=A[i]->TellPrice_Per_Head();
                n=i;
            }
        }
        cout<<endl<<"*CHEAPEST ATTRACTION: "<<endl;
        A[n]->ShowInfo();
    }
    void MaxSeatattraction()
    {
        int max=A[0]->TellSeat_Capacity();
        int k=0;
        for(int i=0;i<MAX;i++)
        {
            if(max<A[i]->TellSeat_Capacity())
            {
                max=A[i]->TellSeat_Capacity();
                k=i;
            }
        }
        cout<<endl<<"*ATTRACTION WITH MAXIMUM SEAT CAPACITY: "<<endl;
        A[k]->ShowInfo();
        cout<<endl<<"Updated Seat Capacity: "<<A[k]->UpdateAndTellSeat_Capacity(0)<<endl;
    }
    void SafeAttraction()
    {
        bool found=false;
        cout<<endl<<"*SAFE ATTRACTIONS: "<<endl;
        for(int i=0;i<MAX;i++)
        {
            if(A[i]->IsSafe()==true)
            {
                
                cout<<endl<<"ATTRACTION: "<<i+1<<endl;
                A[i]->ShowInfo();
                found=true;
            }
        }
        if(found==false)
        cout<<"No Safe Attractions found"<<endl;
    }
    void UpdateInfo()
    {
        string h;
        bool found=false;
        cout<<"Enter name of Attraction whose information you want to update: ";
        cin.ignore();
        getline(cin,h);
        for(int i=0;i<MAX&&found==false;i++)
        {
            if(h==A[i]->TellName())
            {
                cout<<"*CURRENT INFORMATION: "<<endl;
                A[i]->ShowInfo();
                cout<<" "<<endl;
                cout<<"Enter the updated Information:"<<endl;
                A[i]->GetInfo();
                found=true;
                cout<<endl<<"***NOW THE UPDATED INFORMATION IS AS FOLLOWS: "<<endl;
                A[i]->ShowInfo();
                WriteInExistingFile();
            }
        }
        if(found==false)
        cout<<"No Attraction with this name found in Theme Park"<<endl;
    }
    void WriteInExistingFile()
    {
        ofstream ofile("Data.txt"); 
        for (int i = 0; i < MAX; i++)
        {
            ofile << A[i]->TypeOfAttraction() << "," << A[i]->TellName() << ","
              << A[i]->TellPrice_Per_Head() << "," << A[i]->TellAge() << ","
              << A[i]->TellTime_Duration() << "," << A[i]->TellSeat_Capacity() << ",";

        if (A[i]->TypeOfAttraction() == "Ride")
        {
            ofile<<A[i]->ChildAttribute()<<endl;
        }
        else if (A[i]->TypeOfAttraction() == "Entertainment Show")
        {
            ofile<<A[i]->ChildAttribute()<<endl;
        }

        
    }
    ofile.close();
    }
    void TimingSchedule()
    {
        cout<<endl<<"-----------------------------------------"<<endl;
         cout<<"*ATTRACTION*"<<"\t"<<"\t"<<"*TIMING SCHEDULE*"<<endl;
         
        for(int i=0;i<MAX;i++)
        {
            cout<<"|";
            cout<<A[i]->TellName()<<"\t"<<"\t"<<A[i]->TellTime_Duration();
            cout<<"|"<<endl;
        }
        cout<<"-----------------------------------------"<<endl;
    }
    void Availability()
    {
        string AttractionName;
        bool found=false;
        cout<<endl<<"Enter Name of Attraction to check its Availability: ";
        cin.ignore();
        getline(cin,AttractionName);
        for(int i=0;i<MAX;i++)
        {
            if(AttractionName==A[i]->TellName())
            {
                cout<<endl<<"*ATTRACTION IS AVAILABLE IN THE THEME PARK WITH FOLLOWING INFORMATION:"<<endl;
                A[i]->ShowInfo();
                if(A[i]->TellSeat_Capacity()==0)
                {
                    cout<<endl<<"*THIS ATTRACTION IS FULLY OCCUPIED!"<<endl;
                }
                else
                {
                    cout<<endl<<"*YES,THIS ATTRACTION IS AVAILABLE!"<<endl;
                    cout<<"Attraction is Available with Seat Capacity of "<<A[i]->TellSeat_Capacity()<<endl;
                }
                cout<<endl;
                found=true;
            }
        }
        if(found==false)
        cout<<"No Attraction with name found in Theme Park"<<endl;
    }
    void PurchaseTicket()
    {
        string AttractionName;
        int numTickets;
        bool found=false;
        cout<<endl<<"Enter Name of Attraction to check its Availability: ";
        cin.ignore();
        getline(cin,AttractionName);
        for(int i=0;i<MAX;i++)
        {
            if(AttractionName==A[i]->TellName())
            {
                cout<<endl<<"*ATTRACTION IS AVAILABLE IN THE THEME PARK WITH FOLLOWING INFORMATION:"<<endl;
                A[i]->ShowInfo();
                if(A[i]->TellSeat_Capacity()>0)
                {
                    cout<<endl<<"--How Many Tickets you want to purchase: ";
                    cin>>numTickets;
                    if (numTickets<= A[i]->TellSeat_Capacity())
                    {
                      cout<<"______________________________________"<<endl;
                      cout<<endl<<"***ATTRACTION TICKET***"<<endl;
                      cout<<"Number of Ticket Purchased: "<<numTickets<<endl;
                      cout<<"Attraction: "<<AttractionName<<endl;
                      cout<<"Price of One Ticket"<<A[i]->TellPrice_Per_Head()<<endl;
                      cout<<endl<<"*TOTAL AMOUNT OF TICKET: "<<A[i]->TellPrice_Per_Head()*numTickets<<endl;
                      cout<<"***TICKET PURCHASED SUCCESSFULLY!***"<<endl;
                      cout<<"***ENJOY YOUR VISIT!***"<<endl;
                      cout<<"______________________________________"<<endl;
                      int updatedSeatCapacity = A[i]->UpdateAndTellSeat_Capacity(numTickets);
                      cout << endl << "Now the remaining Seats available: " << updatedSeatCapacity << endl;
                      WriteInExistingFile();
                    }
                    else
                    {
                       cout << endl << "Sorry, not enough seats available for the requested number of tickets." << endl;
                    }
                }
                
                else
                {
                    cout<<endl<<"*THIS ATTRACTION IS FULLY OCCUPIED!.....NO SEAT AVAILABLE!"<<endl;
                }
                cout<<endl;
                found=true;
            }
        }
        if(found==false)
        cout<<"No Attraction with name found in Theme Park"<<endl;
        
    }
     void WriteToFile()
    {
        ofstream ofile("ThemeParkAttractions.txt");
        for(int i=0;i<MAX;i++)
        {
            ofile<<endl<<"ATTRACTION:"<<i+1<<endl;
            ofile<<"-"<<A[i]->TypeOfAttraction()<<":"<<endl;
            ofile<<"--"<<A[i]->TellName()<<endl;
            ofile<<"Price per head: "<<"Rs."<<A[i]->TellPrice_Per_Head()<<endl;
            ofile<<"Age: "<<A[i]->TellAge()<<endl;
            ofile<<"Time Duration: "<<A[i]->TellTime_Duration()<<endl;
            ofile<<"Seats Capacity: "<<A[i]->TellSeat_Capacity()<<endl;
            if(A[i]->TypeOfAttraction()=="Ride")
            {
                ofile<<"Speed Of Ride: "<<A[i]->ChildAttribute()<<"m/s"<<endl;
            }
            else if(A[i]->TypeOfAttraction()=="Entertainment Show")
            {
                ofile<<"Safety Rating: "<<A[i]->ChildAttribute()<<"/10"<<endl;
            }
        }
        cout<<"Information Successfully Added!"<<endl;
        ofile.close();
    }
    void UpdatePrice()
   {
        string attractionName;
        float amount;
        char z;
        cout<<"Enter the name of the attraction: ";
        cin.ignore();
        getline(cin, attractionName);
        bool found = false;
        for(int i=0;i<MAX&&found==false;i++)
        {
            if (attractionName==A[i]->TellName()) 
            {
                cout<<endl<<"*Enter a for Addition and s For Subtraction*"<<endl;
                cout<<"Enter choice to increase and decrease Price (a or s): ";
                cin>>z;
                if(z=='a')
                {
                    cout<<"Enter the amount to increase the price: Rs.";
                    cin>>amount;
                    A[i]->operator+(amount);
                    cout<<"PRICE INCREASED."<<endl;
                    cout<<endl<<"Updated information:"<<endl;
                    A[i]->ShowInfo();
                    WriteInExistingFile();
                }
                else if(z=='s')
                {
                    cout<<"Enter the amount to decrease the price: Rs.";
                    cin>>amount;
                    if(amount<=A[i]->TellPrice_Per_Head())
                {
                    A[i]->operator-(amount);
                    cout<<"PRICE DECREASED."<<endl;
                    cout<<endl<<"Updated information:"<<endl;
                    A[i]->ShowInfo();
                    WriteInExistingFile();
                }
                else
                {
                    cout<<"*Invalid Decrement in the Price"<<endl;
                }
                }
                else
                {
                    cout<<"Invalid Command"<<endl;
                }
                found = true;
            }
        }

        if (found==false)
        {
            cout<<"Attraction not found."<<endl;
        }
    }
    
   void DisplayAttractionsWithSamePrice()
 {
     int z;
     bool found = false;
     for(int i=0;i<MAX;i++)
     {
        for(int j=i+1;j<MAX;j++)
        {
            if (A[i]->TellPrice_Per_Head()==A[j]->TellPrice_Per_Head())
            {
                z++;
                cout<<endl<<"Attractions with the same price:"<<endl;
                cout<<"-----------------------------------------"<<endl;
                cout<<endl<<"*ATTRACTION 01: "<<endl;
                A[i]->ShowInfo();
                cout<<endl<<"*ATTRACTION 02: "<<endl;
                A[j]->ShowInfo();
                cout<<"-----------------------------------------"<<endl;
                found=true;
                
            }
            
        }
    }
        cout<<endl<<"=> Set Of Events Occurring On Same Day: "<<z<<endl;
 }
void ViewStatistics()
{
    float totalPrice = 0;
    int Count = 0;

    for (int i = 0; i < MAX; i++)
    {
        totalPrice=totalPrice+A[i]->TellPrice_Per_Head();
        Count++;
    }

    if (Count>0)
    {
        float averagePrice=totalPrice/Count;
       
        cout<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"->Average Price per Attraction: Rs." <<averagePrice<<endl;
        cout<<"-----------------------------------------"<<endl;
    }
    else
    {
        cout<<"No attractions to calculate statistics."<<endl;
    }
}
~ThemePark()
 {
        for(int i=0;i<MAX;i++)
        delete A[i];
  }
};
