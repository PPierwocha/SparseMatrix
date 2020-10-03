#include <vector>



template <typename T>
struct SparseRow
{
    std::vector<T> values;
    std::vector<int> columns;

    SparseRow<T>& operator= (const SparseRow<T>& other)
    {
        values = other.values;
        columns = other.columns;

        return *this;
    }
};