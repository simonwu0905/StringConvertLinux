#include "character.h"

Character::Character()
{

}

int Character::minDistance(const string& source, const string& target)
{
    int srcLength = source.length();
    int dstLength = target.length();

    //define the distance matrix here
    int **distance = new int *[srcLength + 1];
    for (int i = 0; i != srcLength + 1; i++)
    {
        distance[i] = new int[dstLength + 1];
    }

    //fill the first column with row number,which max value is length of source string
    for (int i = 0; i<srcLength + 1; i++)
    {
        distance[i][0] = i;
    }

    //fill the first row with column number,which max value is length of target string
    for (int j = 0; j<dstLength + 1; j++)
    {
        distance[0][j] = j;
    }

    //fill the distance matrix rather than 1st row and 1st column,
    //if the new added character is same for both source and target,the distance value for matrix(i,j) is same as matrix(i-1,j-1)
    //else it is the minimum value of matrix(i-1,j)+1, matrix(i,j-1)+1, matrix(i-1,j-1)+1
    for (int i = 1; i<srcLength + 1; i++)
    {
        for (int j = 1; j<dstLength + 1; j++)
        {
            if (source.at(i - 1) == target.at(j - 1))
                distance[i][j] = distance[i - 1][j - 1];
            else
                distance[i][j] = 1 + minValue(distance[i - 1][j], distance[i][j - 1], distance[i - 1][j - 1]);
        }
    }

    //save value of matrix(srclength,dstLength)
    int res = distance[srcLength][dstLength];

    //clear the space applied for distance matrix
    for (int i = 0; i<srcLength+1; i++)
    {
        if (distance[i])
        {
            delete[] distance[i];
            distance[i] = 0;
        }
    }
    if (distance)
    {
        delete[] distance;
        distance = 0;
    }

    //return the saved value
    return res;
}

int Character::minValue(int a, int b, int c)
{
    return a>b ? (b>c ? c : b) : (a>c ? c : a);
}

