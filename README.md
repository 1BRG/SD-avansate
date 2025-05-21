
# Data Structure Advanced structures project

| Structure    | find max | delete max | increase-key | insert   | meld     | make-heap |
|--------------|----------|------------|--------------|----------|----------|-----------|
| Binary Heap  | O(1)     | O(log n)   | O(log n)     | O(log n) | O(n)     | O(n)      |
| Leftist Heap | O(1)     | O(log n)   | O(log n)     | O(log n) | O(log(n) | O(n)      |
| RP-Heap      | O(1)     | O(log n)   | O(1) am.     | O(1)     | O(1)     | O(n)      |

## We used 3 types of operations
1) add element x to heap y
2) get and delete min from heap x
3) merge heap x and y

##we have 4 types of tests

1) Insert heavy

| Structure    | 100 heaps,1M op | 100 heaps, 4M op | 100 heaps, 10M op | 500 heaps, 1M op | 500 heaps, 4M op | 500 heaps, 10M op | 
|--------------|-----------------|------------------|-------------------|------------------|------------------|-------------------|
| Leftist heap | 0.093           | 0.409            | 1.240             | 0.140            | 0.881            | 1.578             |
| RP-Heap      | 0.108           | 0.367            | 1.024             | 0.119            | 0.493            | 1.416             |
| Binary heap  | 0.676           | 9.596            | 56.179            | 0.188            | 2.541            | 16.904            |

2) Merge heavy

| Structure    | 100 heaps,1M op | 100 heaps, 4M op | 100 heaps, 10M op | 500 heaps, 1M op | 500 heaps, 4M op | 500 heaps, 10M op |
|--------------|-----------------|------------------|-------------------|------------------|------------------|-------------------|
| Leftist heap | 0.058           | 0.314           | 0.731             | 0.106            | 0.560            | 1.115             |
| RP-Heap      | 0.070           | 0.328           | 0.649            | 0.111            | 0.443            | 0.996             |
| Binary heap  | 2.349           | 51.183            | 256.04           | 0.869            | 12.232            | 70.296            |

3) mixed

| Structure    | 100 heaps,1M op | 100 heaps, 4M op | 100 heaps, 10M op | 500 heaps, 1M op | 500 heaps, 4M op | 500 heaps, 10M op |
|--------------|-----------------|------------------|-------------------|------------------|------------------|-------------------|
| Leftist heap | 0.113           | 0.315            | 1.204             | 0.093            | 0.356            | 0.855             |
| RP-Heap      | 0.108           | 0.352            | 1.074             | 0.097            | 0.366            | 0.822             |
| Binary heap  | 1.812           | 16.920           | 132.877           | 0.308            | 4.568            | 24.874            |

4) Pop heavy

| Structure    | 100 heaps,1M op | 100 heaps, 4M op | 100 heaps, 10M op | 500 heaps, 1M op | 500 heaps, 4M op | 500 heaps, 10M op |
|--------------|-----------------|------------------|-------------------|------------------|------------------|-------------------|
| Leftist heap | 0.053           | 0.228            | 0.534             | 0.071            | 0.322            | 0.635             |
| RP-Heap      | 0.079           | 0.368            | 0.847             | 0.087            | 0.396            | 1.021             |
| Binary heap  | 0.152           | 1.938            | 10.789            | 0.056            | 0.571            | 3.326             |
