
using namespace std;

template<class T>
SortNode<T>::SortNode(T val)
{
    value = val;
    next = NULL;
    prev = NULL;
}

template<class T>
string SortNode<T>::print()
{
    stringstream ss;
    ss << value;
    return ss.str();
}

template<class T>
T SortNode<T>::getValue()
{
    return value;
}