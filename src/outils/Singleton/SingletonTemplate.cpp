//
// Created by lucas on 22/12/2025.
//

#include "SingletonTemplate.h"

template <class C>
C* SingletonTemplate<C>::getInstance()
{
    static C instance;
    return &instance;
}