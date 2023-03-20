# Dynamic Programming

## Categories of DP by ChatGPT:

1. Optimization problems: These are problems where the task is to find the maximum or minimum value of a certain function or parameter. Examples include the **Knapsack problem**, Longest Common Subsequence problem, and Maximum Subarray problem.

2. Combinatorial problems: These are problems where the task is to find the number of ways to combine or arrange a set of objects or elements. Examples include the **Binomial Coefficient problem**, Permutation problem, and Combination problem.

3. Path-finding problems: These are problems where the task is to find the shortest or longest path between two points in a given graph or network. Examples include the **Shortest Path problem**, All-Pairs Shortest Path problem, and Traveling Salesman problem.

4. Sequencing problems: These are problems where the task is to find the optimal order or sequence of performing a set of tasks or operations. Examples include the **Matrix Chain Multiplication problem**, Job Sequencing problem, and Optimal Binary Search Tree problem.

5. Graph algorithms: These are problems that involve graph traversal, such as finding the shortest path between two nodes or determining whether a cycle exists in a graph. Examples include the **Bellman-Ford algorithm**, Dijkstra's algorithm, and Floyd-Warshall algorithm.

6. String algorithms: These are problems that involve manipulating and analyzing strings. Examples include the **Edit Distance problem**, Longest Palindromic Substring problem, and String Matching problem.

> Source: [Top 20 dynamic programming interview questions](https://www.geeksforgeeks.org/top-20-dynamic-programming-interview-questions/)

## 1. Longest Common Subsequence

For two text, `abcde` and `ace`

| \ |NA|a|b|c|d|e|
|---|---|---|---|---|---|---|
|NA|0|0|0|0|0|0|
|a|0|0|0|0|0|0|
|c|0|0|0|0|0|0|
|e|0|0|0|0|0|0|

The key idea is reusing the previous best solution.

There are two cases:

1. Current two items are matching.<br>
`matrix[i][j] = matrix[i-1][j-1] + 1`

2. They are not matching.<br>
`matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j])`

## 2. Longest Increasing Subsequence

For a sequence: `0, 1, 0, 3, 2, 3`<br>
The key is how to avoid the **effect of non-optimal** memo.

For this kind of sequence, we need to compare the value of each local optimal solution to current value. And the purpose of it, is to **determine whether add current value to the tail of that value**. To achieve it, we will use the structure:
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

## 3. Edit Distance