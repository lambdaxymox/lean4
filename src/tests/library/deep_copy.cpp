/*
Copyright (c) 2013 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura
*/
#include "util/test.h"
#include "kernel/for_each.h"
#include "kernel/abstract.h"
#include "library/deep_copy.h"
using namespace lean;

static void tst1() {
    expr f = Const("f");
    expr a = Const("a");
    expr x = Var(0);
    expr t = Type();
    expr z = Const("z");
    local_context lctx{mk_lift(0, 1), mk_inst(0, a)};
    expr m = mk_metavar("a", lctx);
    expr F = mk_let("z", Type(), Type(level()+1), mk_pi("y", t, mk_lambda("x", t, f(f(f(x, a), Const("10")), Eq(x, m)))));
    expr G = deep_copy(F);
    lean_assert(F == G);
    lean_assert(!is_eqp(F, G));
}

int main() {
    tst1();
    return has_violations() ? 1 : 0;
}
