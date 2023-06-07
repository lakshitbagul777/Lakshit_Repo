#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string city[30];
    int adj_matrix[50][50];
    cout << "Enter the number of cities : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of the city " << i + 1 << endl;
        cin >> city[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj_matrix[i][j] = 0;
        }
        
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "Enter the time required to travel the " << city[i] << " to the " << city[j] << endl;
            cin >> adj_matrix[i][j];
            adj_matrix[j][i] = adj_matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\t" << city[i] << "\t";
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\n " << city[i];
        for (int j = 0; j < n; j++)
        {
            cout << "\t" << adj_matrix[i][j] ;
        }
    }

    
    cout<<endl;
}