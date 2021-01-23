There are 5 implicit ctor functions created by compiler, when user doesn't define any constructor or destructor.
1. default ctro: X::X()
2. copy ctor: X::X(const X &other)
3. copy assignment ctor: X& X::operator=(const X &other)
4. move ctor: X::X(const X &&other)
5. move assignment ctor: X& X::operator=(const X &&other)
And 1 default dtor, which (...) does more than/similar default ctor does.

But if user define any constructor explicitly, then compiler will not create any of above 5 ctors.
If you still need any of them, explicitly add `= default;` at the end of decl.

Tricky enough, assignment, either move or copy only happens when:
X x1;
X x2;
x2 = x1;
But not when:
X x1;
X x2 = x1;
