# vector-map-speed
some tests to compare search in different containertypes speed
## rust results
```
/home/fanda/.cargo/bin/cargo run --color=always --release
    Finished release [optimized] target(s) in 0.00s
     Running `target/release/vec-map-speed-test`
=========== string keys of length 32 ============
-------------- container size: 10
Vector seek time elapsed:   49ns
BTreeMap seek time elapsed: 62ns
HashMap seek time elapsed:  43ns
-------------- container size: 100
Vector seek time elapsed:   121ns
BTreeMap seek time elapsed: 53ns
HashMap seek time elapsed:  30ns
-------------- container size: 1000
Vector seek time elapsed:   1.182µs
BTreeMap seek time elapsed: 118ns
HashMap seek time elapsed:  84ns
-------------- container size: 10000
Vector seek time elapsed:   13.511µs
BTreeMap seek time elapsed: 231ns
HashMap seek time elapsed:  194ns
-------------- container size: 100000
Vector seek time elapsed:   139.749µs
BTreeMap seek time elapsed: 211ns
HashMap seek time elapsed:  193ns
```
## c++ results
```
=========== string keys of length 32 ============
------------- container size: 10
Vector:   64[ns]
Tree map: 101[ns]
hash map: 61[ns]
------------- container size: 100
Vector:   268[ns]
Tree map: 74[ns]
hash map: 39[ns]
------------- container size: 1000
Vector:   2508[ns]
Tree map: 76[ns]
hash map: 41[ns]
------------- container size: 10000
Vector:   30611[ns]
Tree map: 204[ns]
hash map: 115[ns]
------------- container size: 100000
Vector:   375694[ns]
Tree map: 270[ns]
hash map: 226[ns]
hit cnt: 333332
=========== u32 keys 32 ============
------------- container size: 10
Vector:   27[ns]
Tree map: 85[ns]
hash map: 48[ns]
------------- container size: 100
Vector:   72[ns]
Tree map: 36[ns]
hash map: 22[ns]
------------- container size: 1000
Vector:   539[ns]
Tree map: 37[ns]
hash map: 17[ns]
------------- container size: 10000
Vector:   5325[ns]
Tree map: 57[ns]
hash map: 26[ns]
------------- container size: 100000
Vector:   56198[ns]
Tree map: 114[ns]
hash map: 51[ns]
```
