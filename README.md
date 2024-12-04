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
| s | sin  | 
| c | cos | 
| > | greater than | 
| < | less than | 
| = | equal to | 
| ? | ternary if/else | 


Tips:

- no spaces
- all values are float

## WHYYYY????

- It is VERY small
- It does only what I want it to
- I felt compelled to do it

## build

`gcc eeeeeeeeval.cpp -lstdc++ -std=c++20 -lm -O3 -o eeeeeeeeval`


## benchmarks

```
gcc benchmark.cpp -lstdc++ -std=c++20 -lm -O3 -o benchmark
./benchmark
```



