#include <vector>



template<class T>
struct SparseRow
{
    std::vector<T> values;
    std::vector<int> columns;
};