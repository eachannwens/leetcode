# Dynamic Programming


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