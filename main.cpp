//This program finds the volume of multiple solids of your choice!
// Edits innclude checking user inputs for errors for effeciency!
//Wrote by Devin Lee Harris on 2/26/19

#include <QCoreApplication>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
double rectangularsolid(double length, double width, double height)
{
   double volume  = length*width*height;
   return volume;
}
double cylinder(double radius, double height)
{
    double volume = 3.14*pow(radius,2)*height;
    return volume;
}
double sphere(double radius)
{
    double volume = (4.0/3.0)*3.14*pow(radius,3);
    return volume;
}
double regulartetrahedron(double length)
{
    double volume = (1.0/6.0*sqrt(2))* pow(length,3);
    return volume;
}
double rightcircularcone(double height, double radius)
{
    double volume = 3.14/3*pow(radius,2)*height;
    return volume;
}
double test(string Tester)
{
    if (Tester.size()==0)
    {
        return(true);
    }
    while (Tester.at(0)=='0')
    {
        Tester.erase(0,1);
        if (Tester.size()== 0)
        {
            return(true);
        }
    }
    for (unsigned int i = 0; i < Tester.size(); i++ )
    {
        if (isdigit(Tester.at(i)) != true)
        {
            return(true);
        }
        if (Tester.at(0)== '0'&& Tester.size()==1)
        {
            return(true);
        }
        if(Tester.at(1) == '.')
        {
            return(true);
        }
    }
    return(false);
}
double stringtodouble(string userinput)
{
    double d;
    std::stringstream iss(userinput);
    iss >> (d);
    return d;
}
bool check(string test, int &helper)
{
    if (test.size() == 0)
    {
        return false;

    }
    for(unsigned int i = 0; i>test.size(); i++)
    {
        if(!isdigit(test.at(i)))
        {
            return false;
        }
    }
    helper = stoi(test);
    return true;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    double  entrylength = 0, entrywidth = 0, entryheight = 0, entryradius = 0;
    int entrysolid = 0, x = 1;
    while (x == 1)
    {


    cout<<"What type of solid do you have?"<<endl;
    cout<<"1 = rectangularsolid, 2 = cylinder, 3 = sphere, 4 = regulartetrahedron, 5 = rightcircularcone"<<endl;
    string temp;
    getline(cin, temp);
    while(!check(temp, entrysolid))
    {
        cout<<"Please enter valid data"<<endl;
        getline(cin, temp);

    }
    while(entrysolid != 6)
    {


    if(entrysolid == 1)
    {
        string userinput;
        cout<<"What is the length?"<<endl;
        getline(cin, userinput);
        while(test(userinput))
        {
            cout<<"Please enter valid data"<<endl;
            getline(cin, userinput);

        }
        entrylength = stringtodouble(userinput);
        userinput.clear();
        cout<<"What is the width?"<<endl;
        getline(cin, userinput);
        while(test(userinput))
        {
            cout<<"Please enter valid data"<<endl;
            getline(cin, userinput);

        }
        entrywidth = stringtodouble(userinput);
        cout<<"What is the height?"<<endl;
        getline(cin, userinput);
        while(test(userinput))
        {
            cout<<"Please enter valid data"<<endl;
            getline(cin, userinput);

        }
        entryheight = stringtodouble(userinput);
        cout<<"*******"<<endl;
        cout<<"Volume ="<< rectangularsolid(entrylength,entrywidth,entryheight) <<endl;
        cout<<"*******"<<endl;
        entrysolid = 6;
    }

   else if (entrysolid == 2)
    {
        string userinput;
        cout<<"What is the radius?"<<endl;
        getline(cin, userinput);
        while(test(userinput))
        {
            cout<<"Please enter valid data"<<endl;
            getline(cin, userinput);

        }
        entryradius = stringtodouble(userinput);
        cout<<"What is the height?"<<endl;
        getline(cin, userinput);
        while(test(userinput))
        {
            cout<<"Please enter valid data"<<endl;
            getline(cin, userinput);

        }
        entryheight = stringtodouble(userinput);
        cout<<"*******"<<endl;
        cout<<"Volume ="<<cylinder(entryradius, entryheight)<<endl;
        cout<<"*******"<<endl;
        entrysolid = 6;
    }

    else  if( entrysolid == 3)
    {
        string userinput;
        cout<<"What is the radius?"<<endl;
        getline(cin, userinput);
        while(test(userinput))
        {
            cout<<"Please enter valid data"<<endl;
            getline(cin, userinput);

        }
        entryradius = stringtodouble(userinput);
        cout<<"*******"<<endl;
        cout<<"Volume ="<<sphere(entryradius)<<endl;
        cout<<"*******"<<endl;
        entrysolid = 6;
    }
    else if(entrysolid == 4)
    {
        string userinput;
        cout<<"What is the length?"<<endl;
        getline(cin, userinput);
        while(test(userinput))
        {
            cout<<"Please enter valid data"<<endl;
            getline(cin, userinput);

        }
        entrylength = stringtodouble(userinput);
        cout<<"*******"<<endl;
        cout<<"Volume ="<<regulartetrahedron(entrylength)<<endl;
        cout<<"*******"<<endl;
        entrysolid = 6;
    }
    else   if (entrysolid == 5)
    {
        string userinput;
        cout<<"What is height?"<<endl;
        getline(cin, userinput);
        cin.ignore();
        while(test(userinput))
        {
            cout<<"Please enter valid data"<<endl;
            getline(cin, userinput);

        }
        entryheight = stringtodouble(userinput);
        cout<<"What is the radius?"<<endl;
        getline(cin, userinput);
        while(test(userinput))
        {
            cout<<"Please enter valid data"<<endl;
            getline(cin, userinput);

        }
        entryradius = stringtodouble(userinput);
        cout<<"*******"<<endl;
        cout<<"Volume ="<<rightcircularcone(entryheight, entryradius)<<endl;
        entrysolid = 6;

    }
    else
    {
        cout<<"Invalid Input"<<endl;
        cout<<"Please enter valid input"<<endl;

    }
    }

cout<<"Would you like to find the volume of another solid?"<<endl;
cout<<"1 = yes, 0 = no"<<endl;
cin>>x;
}
    return a.exec();
}
