#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

void insertion_sort(string* array, int n)
{
    int i,j;
    string key;
    for (i=0;i<n;i++)
    {
        key=array[i];
        j=i-1;
        for (j = i-1; j >=0 && _strcmpi(array[j].c_str(), key.c_str()) > 0; j--)
        {
            array[j+1]=array[j];
        }
        array[j+1]=key;
    }
}

int main()
{
    int c = 0, n = 100;
    string numbers[100];
    string line;
    fstream myfile;
    myfile.open("top_passwords.txt");
    while(myfile.good())
    {
        getline(myfile,line);
        numbers[c]=line;
        c++;
    }

    insertion_sort(numbers,n);

    for(c = 0; c<n; c++)
    {
        cout<<numbers[c]<<endl;
    }
    myfile.close();

    return 0;
}
