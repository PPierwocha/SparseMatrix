#include <vector>



template <typename T>
struct SparseRow
{
    std::vector<T> values;
    std::vector<int> columns;
};