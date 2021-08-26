//Constant Expressions and Default Parameters
#include <iostream>
#include <vector>

using namespace std;

template<int len, int beg_pos>
class num_sequence
{
public:
    virtual ~num_sequence(){};
    int     elem(int pos) const;
    const char* what_am_i() const;
    static int max_elems()
    {
        return _max_elems;
    }
    ostream& print(ostream &os = cout) const;

protected:
    virtual void gen_elems(int pos) const = 0;
    bool check_integrity(int pos, int size) const;

    num_sequence(vector<int> *pe) : _pelems(pe){}
    static const int _max_elems = 1024;
    vector<int>  *_pelems;

};

template<int len, int beg_pos>
ostream& operator<<(ostream &os, const num_sequence<len, beg_pos> &ns)
{
    return ns.print(os);
}

template<int len, int beg_pos>
int num_sequence<len, beg_pos>::elem(int pos) const
{
    if(!check_integrity(pos, _pelems->size()))
    {
        return 0;
    }
    return (*_pelems)[pos - 1];
}

template<int len, int beg_pos>
const char* num_sequence<len, beg_pos>::what_am_i() const
{
    return typeid(*this).name();
}

template<int len, int beg_pos>
bool num_sequence<len, beg_pos>::check_integrity(int pos, int size) const
{
    if(pos <= 0 || pos >max_elems())
    {
        cerr << "!! invalid position: " << pos << " Cannot honor request\n";
        return false;
    }

    if(pos > size) gen_elems(pos);
    return true;
}

template<int len, int beg_pos>
ostream& num_sequence<len, beg_pos>::print(ostream &os) const
{
    int elem_pos = beg_pos - 1;
    int end_pos = elem_pos + len;

    if(!check_integrity(end_pos, _pelems->size()))
    {
        return os;
    }

    os << "(" << beg_pos << ", " << len << ")";

    while (elem_pos < end_pos)
    {
        os << (*_pelems)[elem_pos++] << ' ';
    }

    return os;
}

//!
template<int len, int beg_pos = 1>
class Fibonacci : public num_sequence<len, beg_pos>
{
public:
    Fibonacci() : num_sequence<len, beg_pos>(&_elems){}

private:
    virtual void gen_elems(int pos) const;
    static vector<int> _elems;
};

template<int len, int beg_pos>
vector<int> Fibonacci<len, beg_pos>::_elems;

template<int len, int beg_pos>
void Fibonacci<len, beg_pos>::gen_elems(int pos)  const
{
    if(pos < 0 || pos > _elems.max_size()) return;

    if(_elems.empty())
    {
        _elems.push_back(1);
        _elems.push_back(1);
    }

    if(_elems.size() <= pos)
    {
        int ix = _elems.size();
        int n_2 = _elems[ix - 1];
        int n_1 = _elems[ix - 2];

        int elem;
        for(; ix <= pos; ++ix)
        {
            elem = n_2 + n_1;
            _elems.push_back(elem);
            n_1 = n_2;
            n_2 = elem;
        }
    }
}


int main()
{
    Fibonacci<8> fib1;
    Fibonacci<8, 8> fib2;
    Fibonacci<12, 8> fib3;

    cout << "fib1: " << fib1 << '\n'
        << "fib2: " << fib2 << '\n'
        << "fib3: " << fib3 << endl;

    return 0;
}
