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

### Results

Machine: 16 × 11th Gen Intel® Core™ i7-11800H @ 2.30GHz

| Expression | How many times _slower_ than C++ | 
| -- | -- |
|`+(1,2)` | 6.97 | 
|`+(*(1,2),/(3, 4))` | 8.36 |
|`-(*(/(1,2),+(3,4)),/(^(5,6),*(7,8)))` | 3.01 |
|`+(*(c(1,0),-(2,3)),/(s(4,0),^(5,6)))`| 2.08 |
|`?(>(/(5,3),2),*(+(3,4),-(8,6)),/(-(9,3),+(1,2)))`| 11.97 |


