#include <iostream>
#include <vector>

using namespace std;

//link to code that was used to help understand vectors 
// http://cplusplus.com/reference/vector/vector/erase/


int main()
{
    std::vector<int> bag;

    //first test
    for (int marble=1; marble<=15; marble++) bag.push_back(marble);
    
    bag.erase(bag.begin(),bag.begin()+15);

    cout <<"Marbles in bag";
    for (unsigned marble=0; marble<bag.size();marble++)
        cout<<" "<<bag[marble];
        cout<<"\n";


    
    //second test
    for (int marble=1; marble<=15; marble++) bag.push_back(marble);
    bag.erase(bag.begin()+5);

    cout <<"Marbles in bag";
    for (unsigned marble=0; marble<bag.size();marble++)
        cout<<" "<<bag[marble];

    return 0;
}