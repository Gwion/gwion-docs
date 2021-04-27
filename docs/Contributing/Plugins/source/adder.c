#include "plugin_dev.h"

// The `SFUN` macro defines a static function
// The `static` here is actually a C keyword, unrelated to Gwion
static SFUN(sfun) {
    // Retrieve the arguments
    // `a` is in memory at offset 0
    const m_int a = *(m_int*)MEM(0);
    // `b` is in memory at offset `SZ_INT`
    // This is because `a` has size `SZ_INT` and `b` is after `a`
    const m_int b = *(m_int*)MEM(SZ_INT);

    // We now set the return value, given as a void pointer with the `RETURN` macro
    // We need to cast it to the pointer type we want to return and then assign the return value
    *(m_int*)RETURN = a + b;
}

GWION_IMPORT(Adder) {
    // Begin our adder class
    DECL_OB(const Type, t_adder, = gwi_class_ini(gwi, "Adder", "Object"));

    // Create a new function named `add` with a return type of `int`
    // gwi_func_ini(gwi, return_type, name);
    GWI_BB(gwi_func_ini(gwi, "int", "add"));

    // Register our two args `a` and `b` of type `int`
    // gwi_func_arg(gwi, arg_type, name);
    GWI_BB(gwi_func_arg(gwi, "int", "a"));
    GWI_BB(gwi_func_arg(gwi, "int", "b"));

    // Mark the function as completely declared
    GWI_BB(gwi_func_end(gwi, adder_add, ae_flag_static));

    // End our adder class
    GWI_BB(gwi_class_end(gwi));

    return GW_OK;
}
