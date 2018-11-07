#include "print.h"
#include <vector>

int main()
{
    vector<int> arg{16,17,18};
    SeqPrint::print<vector<int>>(arg);
}
