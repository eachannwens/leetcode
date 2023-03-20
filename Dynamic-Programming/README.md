# Dynamic Programming

> Source: [Top 20 dynamic programming interview questions](https://www.geeksforgeeks.org/top-20-dynamic-programming-interview-questions/)

## Longest Common Subsequence

For two text, `abcde` and `ace`

| \ |NA|a|b|c|d|e|
|---|---|---|---|---|---|---|
|NA|0|0|0|0|0|0|
|a|0|0|0|0|0|0|
|c|0|0|0|0|0|0|
|e|0|0|0|0|0|0|

> The key idea is reusing the previous best solution.

There are two cases:

1. Current two items are matching.<br>
`matrix[i][j] = matrix[i-1][j-1] + 1`

2. They are not matching.<br>
`matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j])`

## Longest Increasing Subsequence

For a sequence: `0, 1, 0, 3, 2, 3`<br>
The key is how to avoid the **effect of non-optimal** memo.

For this kind of sequence, we need to compare the value of each local optimal solution to current value. And the purpose of it, is to <u>determine whether add current value to the tail of that value</u>. To achieve it, we will use the structure:
```c++
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        // Operations...
    }
}
```
Let's look the example, `round` means `i`, `-` means that not arrive here. At round `0`, we initialize all to `1`, because the length of itself is `1`. At each round, we only consider `nums[i]` with its ancestors' optimal solution.

round|0|1|0|3|2|3
|---|---|---|---|---|---|---|
0|1|1|1|1|1|1
1|1|2|-|-|-|-
2|1|2|1|-|-|-
3|1|2|1|3|-|-
4|1|2|1|3|3|-
5|1|2|1|3|3|4

Go deeply, looking at the `round-3`, `3` has three ancestors `0, 1, 0` and their optimal solutions `1, 2, 1`. Let's make a new table:<br>
The form: `max(<1>, <2>)` -><br>
`<1>` means do not add itself to this sequence.<br>
`<2>` means add itself to this sequence, so the length of sequence will plus one.<br>
and the result is the optimal solution of current value.

 optimal \ value |0|1|0
---|---|---|---
1|max(1, 1+1)|-|-
2|-|max(2, 2+1)|-
1|-|-|max(3, 1+1)