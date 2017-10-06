#include <QCoreApplication>
#include <QDebug>
#include "character.h"
#include "iostream"
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string source,target;
    Character character;
    while(true)
    {
        cout<<"Kindly Input The Source String:"<<endl;
        getline(std::cin, source);
        cout<<"Kindly Input The Target String:"<<endl;
        getline(std::cin,target);
        cout<<"\n###############################\n"<<endl
           <<"Minimum convertion number is "<<character.minDistance(source,target)<<endl
          <<"\n###############################\n"<<endl;
    }
    return a.exec();
}

