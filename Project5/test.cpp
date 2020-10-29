#include <iostream>
#include <vector>
#include "tfsarray.h"

using std::vector;

int main() {
    
    const size_t SIZE = size_t(10);
    TFSArray<int> ti_original(SIZE);
    for (size_t i = 0; i < SIZE; ++i)
    {
        ti_original[i] = 15-int(i)*int(i);
    }

    const size_t SIZE2 = size_t(100000);
    TFSArray<int> ti = ti_original;

    // Create expected data
    vector<int> v(ti_original.begin(), ti_original.end());
    for (size_t i = SIZE+1; i <= SIZE2; ++i)
    {
        v.insert(v.end(), 70000-(int(i)-1));
    }

    // Do inserting
    int realloccount = 0;       // # of times realloc-&-copy done
    bool realloctwice = false;  // Did realloc-&-copy 2x in a row?
    bool realloclast = false;   // Was realloc-&-copy just done?
    for (size_t i = SIZE+1; i <= SIZE2; ++i)
    {
        std::cout << i << std::endl;
        int * savedata = ti.begin();
        auto result = ti.insert(ti.end(), 70000-int(ti.size()));
        std::cout << "Passed Insert" << std::endl;
        bool reallocdone = (ti.begin() != savedata);  // realloc-&-copy?
        if (reallocdone)
        {
            ++realloccount;
            if (realloclast)
                realloctwice = true;
        }
        realloclast = reallocdone;
    }

}
