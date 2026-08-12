# Algo-grind 🧠

Personal DSA grind repo — solutions auto-synced from LeetCode via LeetSync.
Following **Striver's A2Z DSA Sheet** (474 problems). Patterns tracked in Supermemory, progress logged in Notion.

---

## Pattern Cheat Sheet

> Last updated: Aug 11, 2026 · 10 patterns

---

### 1. Classic Binary Search
**Signal:** sorted array, find target in O(log n)

```cpp
int lo = 0, hi = n - 1;
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) lo = mid + 1;
    else hi = mid - 1;
}
return -1;
```
**Bugs:** `lo < hi` misses last element · `lo = mid` infinite loop · `(lo+hi)/2` overflow
**Examples:** LC 704, LC 35

---

### 2. Lower / Upper Bound BS
**Signal:** "first/last occurrence of target"

```cpp
// Lower bound — go LEFT on match
if (nums[mid] == target) { ans = mid; hi = mid - 1; }
// Upper bound — go RIGHT on match
if (nums[mid] == target) { ans = mid; lo = mid + 1; }
```
**Examples:** LC 34 (uses both), LC 2210

---

### 3. Find First True Template (lo < hi)
**Signal:** monotonic predicate false→true, "first bad/valid X"

```cpp
int lo = 1, hi = n;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (condition(mid)) hi = mid;   // keep mid — it could be the answer
    else lo = mid + 1;
}
return lo;  // lo == hi at exit
```
**Key:** `hi=mid` not `mid-1` on match · return `lo`, no `ans` variable needed
**Examples:** LC 278

---

### 4. Binary Search on Answer
**Signal:** "minimum X to achieve Y", search the answer range not the array

```cpp
int lo = 1, hi = max_possible;
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (isValid(mid)) hi = mid - 1;
    else lo = mid + 1;
}
return lo;
```
**Integer ceiling (avoid float):** `(a + b - 1) / b`
**Examples:** LC 875 (Koko Eating Bananas)

---

### 5. Single Element in Sorted Pairs
**Signal:** all elements appear twice except one, array is sorted

```cpp
int lo = 0, hi = n - 1;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (mid % 2 == 1) mid--;            // snap to even
    if (nums[mid] == nums[mid+1]) lo = mid + 2;
    else hi = mid;
}
return nums[lo];
```
**Examples:** LC 540

---

### 6. Kadane's Algorithm (Max Subarray Sum)
**Signal:** "maximum sum contiguous subarray", O(n) expected

```cpp
int curr = 0, ans = INT_MIN;
for (int x : nums) {
    curr = max(x, curr + x);
    ans = max(ans, curr);
}
```
**Bug:** `ans = 0` returns 0 for all-negative arrays → always init `INT_MIN`
**Examples:** LC 53

---

### 7. Prefix + Suffix Product (Max Product Subarray)
**Signal:** "maximum product contiguous subarray", negatives present

```cpp
int maxi = INT_MIN, prod = 1;
// Forward pass
for (int i = 0; i < n; i++) { prod *= nums[i]; maxi = max(maxi, prod); if (!prod) prod = 1; }
prod = 1;
// Backward pass
for (int i = n-1; i >= 0; i--) { prod *= nums[i]; maxi = max(maxi, prod); if (!prod) prod = 1; }
```
**Why 2 passes:** even-neg (forward) · odd-neg left (forward) · odd-neg right (backward)
**Examples:** LC 152

---

### 8. Prefix Sum + Hashmap (Subarray Sum = K)
**Signal:** "count subarrays summing to k", negatives present (rules out sliding window)

```cpp
unordered_map<int,int> mp;
mp[0] = 1;  // critical — handles subarrays from index 0
int sum = 0, count = 0;
for (int x : nums) {
    sum += x;
    count += mp[sum - k];
    mp[sum]++;
}
```
**Key:** `prefixSum[i] - prefixSum[j] = k` → subarray (j+1..i) sums to k
**Examples:** LC 560

---

### 9. Fill / Merge from the Right (In-place Two Pointers)
**Signal:** "merge two sorted arrays in-place", extra space at end of first array

```cpp
int p1 = m-1, p2 = n-1, p = m+n-1;
while (p1 >= 0 && p2 >= 0) {
    if (nums1[p1] >= nums2[p2]) nums1[p--] = nums1[p1--];
    else nums1[p--] = nums2[p2--];
}
while (p2 >= 0) nums1[p--] = nums2[p2--];
```
**Key:** `>=` handles equal case naturally · drain leftover nums2 after loop
**Examples:** LC 88

---

### 10. kSum Pruning (Early Break / Continue)
**Signal:** kSum with nested fixed-pointer loops, sorted array

```cpp
// Apply at every loop level:
if (nums[i] + smallest_remaining_3 > target) break;   // min possible > target
if (nums[i] + largest_remaining_3 < target) continue; // max possible < target
```
**Examples:** LC 18 (4Sum) — pruning at both i and j loop levels → beats 100%

---

## Phrasing → Pattern Quick Map

| What the problem says | Pattern |
|---|---|
| Sorted array + O(log n) | Classic Binary Search |
| "First / last occurrence" | Lower / Upper Bound BS |
| "First X where condition true" | lo<hi template, hi=mid on match |
| "Minimum X satisfying constraint" | Binary Search on Answer |
| Sorted pairs, one unique element | Single Element BS |
| "Max sum subarray" + O(n) | Kadane's, ans=INT_MIN |
| "Max product subarray" | Prefix + Suffix product, 2 passes |
| "Count subarrays sum=k" + negatives | Prefix Sum + Hashmap, mp[0]=1 |
| "Merge sorted in-place, extra space" | Fill from right, 3 pointers |
| kSum + nested loops + sorted | kSum Pruning at each loop level |
| "Subarray" + O(n) + non-negative | Sliding Window |
| Binary search + round-up division | (a+b-1)/b, not ceil() |

---

## LeetSync Folder Quirks
Some folder names don't match LC numbers (internal backend IDs):
- LC 704 → `792-binary-search`
- LC 875 → `907-koko-eating-bananas`
- LC 2149 → `2271-rearrange-array-elements-by-sign`

---

*Updated periodically · Supermemory space: `dsa_lc_patterns`*
