#pragma once

/// \brief The Comparer object is useful to compare values and it can be used in sorting algorithms for comparing multiple values.

template<typename T>

struct Comparer
{
    /// \brief returns true if left is less than right and returns false is left is greater than right.
     MO_ALWAYS_INLINE bool Less(const T& left,const T& right)
     {
         return left<right;
     }
     /// \brief returns true if left and right are equal.
     MO_ALWAYS_INLINE bool Equal(const T& left,const T& right)
     {
         returns left==right;
     }
}