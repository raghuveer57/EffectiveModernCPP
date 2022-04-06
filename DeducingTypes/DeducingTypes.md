# Deducing Types

### Case 1: Param type is a reference or a pointer but not a universal reference
-   If `expr` type is `ref` then ignore the ref part while determing `T`.
-   Then pattern match `expr's` type against `ParamType` to determine `T`

### Case2: Param type is a universal reference
- If `expr` is `lvalue`, then both `T` and `ParamType` are deduced to be `lvalue references`. This is the only case where `T` is deduced to be a `ref`.
- If expr is `rvalue`, the normal case 1 rules apply.

### Case 3: Param type is neither a reference nor a pointer
-  parameter is passed into the function by value
- reference, const and volatile all are ignored.

### Array Arguments
- Array decays into a pointer when passed in to a function by *value* or function taking a *pointer* param( `funValue()` or `funPointer()`) 
- The actual type is only deduced when the array is passed into a function taking a reference param( i.e., `funReference()`)
- The same is applicable for functions as well.

### Things to remember
- During template type deduction, arguments that are references are treated as non-references, i.e., their reference-ness is ignored.
- When deducing types for universal reference parameters, lvalue arguments get special treatment.
- When deducing types for by-value parameters, const and/or volatile arguments are treated as non-const and non-volatile.
- During template type deduction, arguments that are array or function names decay to pointers, unless they’re used to initialize references.