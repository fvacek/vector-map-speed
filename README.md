# vector-map-speed
some tests to compare search in different containertypes speed

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
