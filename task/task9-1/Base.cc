#include "Base.h"

Base operator+(const Base &lhs, const Base &rhs)
{
    return Base(rhs.data_ - lhs.data_);
}

