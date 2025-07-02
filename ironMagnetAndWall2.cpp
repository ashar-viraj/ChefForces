#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int i, T, size, K, con_sheet, id_i, id_m, P;
    string s;
    cin >> T;
    while (T--)
    {
        P = -1;
        con_sheet = 0;
        cin >> size >> K;
        cin >> s;
        for (i = 0; i < size; i++)
        {
            //   I M I
            //   M _ _ M _ I : M _ _ M I X M _ I
            //   0 1 2 3 4 5 6 7 8 9 101112131415
            if (s[i] == 'I')
            {

                id_i = i;
                if (id_m != -1)
                {
                    P = K + 1 - (i - id_m) - con_sheet;
                }
                id_m = -1;
                id_i = -1;
                con_sheet = 0;
            }
            else if (s[i] == 'M')
            {
                if (i > id_i && id_i != -1)
                {
                    if ((K + 1 - (i - id_i) - con_sheet) > P)
                        P = K + 1 - (i - id_i) - con_sheet;
                    id_i = -1;
                    id_m = -1;
                    con_sheet = 0;
                }
                else
                {
                    con_sheet = 0;
                    id_m = i;
                }
            }
            else if (s[i] == ':')
            {
                con_sheet++;
            }
            else if (s[i] == 'X')
            {
                id_i = -1;
                id_m = -1;
                con_sheet = 0;
                // if (id_i != -1 && id_m != -1)
                // {
                //     S = K + 1 - abs(id_i - id_m) - con_sheet;
                // }
            }
        }
    }
    return 0;
}