namespace Foo

scoped macro "foo!" x:term:max : term => `($x + 1)

#check foo! 10

theorem ex1 : foo! 10 = 11 := rfl

end Foo

#check foo! 10 -- Error

open Foo

#check foo! 10 -- works

theorem ex2 : foo! 10 = 11 := rfl

scoped macro "bla!" x:term:max : term => `($x * 2) -- Error scoped macros must be used inside namespaces

section

local macro "bla!" x:term:max : term => `($x * 2)

theorem ex3 : bla! 10 = 20 := rfl

end

#check bla! 10 -- Error unknown identifier `bla!`

def bla! := 20 -- bla! is still a valid identifier
