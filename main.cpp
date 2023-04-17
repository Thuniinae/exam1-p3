// connections of modules using signals
// CHENG-HAN YU
// 2023/04/16

/* NOTES:
1. clock declaration: sc_clock clk("clk", period, SC_NS);
2. clock interface: sc_in_clk clk;
3. clock in sensitive list need positive edge: sensitive << clk.pos
*/

#include <systemc>
#include <iomanip> // for std::setw
#include "sysc/datatypes/fx/fx.h" // for sc_fixed
using namespace std;
using namespace sc_core; // for sc_start(), SC_MODULE, ...
using namespace sc_dt; // for system-c datatypes

#include "testbench.h"
#include "filter.h"
#include "param.h"

int sc_main(int argc, char *argv[])
{
    TESTBENCH testbench("testbench");
    FILTER filter("filter");


    sc_fifo<sc_ufixed_fast<53,10>> a, b, r;
    sc_clock clk("clk", 1, SC_NS);

    testbench.a(a);
    filter.a(a);
    testbench.r(r);
    filter.r(r);
    testbench.b(b);
    filter.b(b);


    testbench.clk(clk);
    filter.clk(clk);
    sc_start(1, SC_SEC);
    return 0;
}