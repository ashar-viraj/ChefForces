#include <bits/stdc++.h>
using namespace std;

bool is_adjacent(char A, char B)
{
    return (abs(A - B) == 1); // 'A' 'B' and 'B' 'A' etc
}


void move_disks(int n, char source, char destination)
{
    if (n == 0 || source == destination)
    {
        return;
    }
    if (is_adjacent(source, destination))
    {
        char auxiliary;
        if ((source == 'A' && destination == 'B') || (source == 'B' && destination == 'A'))
        {
            auxiliary = 'C';
        }
        else
        {
            auxiliary = 'A';
        }
        move_disks(n - 1, source, auxiliary);
        cout << "Move disk " << n << " from " << source << " to " << destination << endl;
        move_disks(n - 1, auxiliary, destination);
    }
    else
    {
        move_disks(n - 1, source, destination);
        cout << "Move disk " << n << " from " << source << " to B" << endl;
        move_disks(n - 1, destination, source);
        cout << "Move disk " << n << " from B to " << destination << endl;
        move_disks(n - 1, source, destination);
    }
}
int main()
{
    int n;
    cin >> n;
    move_disks(n, 'A', 'B');
    return 0;
}

/*
Move disk 1 from A to B
Move disk 1 from B to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to B
Move disk 1 from B to C
Move disk 3 from A to B
Move disk 1 from C to B
Move disk 1 from B to A
Move disk 2 from C to B
Move disk 1 from A to B

Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to B
Move disk 1 from B to C
Move disk 3 from B to A
Move disk 1 from C to B
Move disk 1 from B to A
Move disk 2 from C to B
Move disk 1 from A to B
Move disk 1 from B to C
Move disk 2 from B to A
Move disk 1 from C to B
Move disk 1 from B to A
*/