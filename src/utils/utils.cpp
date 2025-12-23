//
// Created by maxen on 22/12/2025.
//

// INCLUSIONS

#include "utils.h"

// FONCTIONS

int Utils::maxArrayInt(int n, const int* a)
{
    int res = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > res)
            res = a[i];
    }

    return res;
}