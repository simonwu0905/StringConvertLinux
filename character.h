#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
using namespace std;
class Character
{
public:
    Character();
public:
    int minDistance(const string& source, const string& target);
private:
    int minValue(int a,int b, int c);
};

#endif // CHARACTER_H

