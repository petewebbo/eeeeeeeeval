# eeeeeeeeval
Eeeeeeeeh, look! A really stupid expression evaluator.

Has a VERY unforgiving prefix notation syntax, e.g.

`+(4,/(7,3))`

Allowed operations:

| operator | operation | 
| -- | -- |
| +  | add |
| - | subtract | 
| * | multiply | 
| / | divide | 
| ^ | powf | 
| ! | not (what does this do to a float? who cares) |
| s | sin  | 
| c | cos | 


Tips:

- no spaces
- all values are float
- all operations take two args. Add a dummy second variable for sin/cos

## build

`gcc eeeeeeeeval.cpp -lstdc++ -lm -o eeeeeeeeval`




