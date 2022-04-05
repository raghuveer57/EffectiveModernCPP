# Deducing Types

### Case 1: Param type is a reference or a pointer but not a universal reference
-   If `expr` type is `ref` then ignore the ref part while determing `T`.
-   Then pattern match `expr's` type against `ParamType` to determine `T`

### Case2: Param type is a universal reference
- If `expr` is `lvalue`, then both `T` and `ParamType` are deduced to be `lvalue references`. This is the onlt case where `T` is deduced to be a `ref`.
- If expr is `rvalue`, the normal case 1 rules apply.

### Case 3: Param type is neither a reference nor a pointer
-  parameter is passed into the function by value
- reference, const and volatile all are ignored.