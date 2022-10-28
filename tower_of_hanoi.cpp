#include <bits/stdc++.h>
using namespace std;

class create_TOH
{
    int elem;
    char disks[];

public:
    create_TOH(int x){
        elem = x;
        disks[x];
    }
    void gen_Disks(){
        int counter = 65;
        for (int i = 0; i < elem; i++)
        {
            disks[i] = counter;
            counter++;
        }
        
    }
    void solve_TOH(int elem, int rod_A, int rod_B, int rod_C)
    {
        if (elem == 0)
        {
            cout<<"NO disks for the tower";
        }
        solve_TOH(elem - 1, rod_A, rod_B, rod_C);
        cout << "Moving disk " << elem << " from rod " << rod_A << " to rod " << rod_C << endl;
        solve_TOH(elem - 1, rod_B, rod_C, rod_A);
    }
};

int main()
{
    int n;
    cout<<"Enter the number of disks you want for the tower : ";
    cin>>n;
    create_TOH tower(n);
    tower.solve_TOH();
    return 0;
}
