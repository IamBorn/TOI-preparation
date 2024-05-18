# TOI20 Preparation day 1

date: 28/4/2024

## Prefix sum

general problem: given array of size n. Asked q queries l, r.
find $\sum_{n=l}^{r} a_n$

## Fenwick Tree / Binary indexed tree
[Fenwick tree](https://cp-algorithms.com/data_structures/fenwick.html)

store data in binary tree.

Read cummulatived

```c++
int readCummulatived(int idx){
    int ans = 0;
    while(idx > 0){
        ans += T[idx];
        idx -= "value of last 1 in binary";
    }
    return ans;
}
```

Update data

```c++
void update(int idx, int change){
   while(idx < MX)
        T[idx] += change;
        idx += "value of last 1 in binary";
}
```

find value of last 1 in binary

```c++
    x & (-x)
```

new code 

```c++
int readCummulatived(int idx){
    int ans = 0;
    while(idx > 0){
        ans += T[idx];
        idx -= idx & (-idx);
    }
    return ans;
}

void update(int idx, int change){
    while(idx < MX){
        T[idx] += change;
        idx += idx & (-idx);
    }
}
```
