# Approaches - Integer to Roman (LC 12)

## 1. Greedy value-symbol pairs (alternative, not implemented)
- Time: O(1) (bounded number of symbols to check)
- Space: O(1)
- Keep a descending list of value-symbol pairs (1000/M, 900/CM, 500/D, 400/CD, 100/C, 90/XC, 50/L, 40/XL, 10/X, 9/IX, 5/V, 4/IV, 1/I) and repeatedly subtract the largest value that fits, appending its symbol each time.
- Common textbook approach for this problem; discussed but not the one implemented here.

## 2. Digit-decomposition lookup table (chosen)
- Time: O(1)
- Space: O(1)
- Break the number into digits by place value: num/1000, (num/100)%10, (num/10)%10, num%10.
- Each place value (thousands/hundreds/tens/ones) has its own 10-entry lookup table (digits 0-9) handling the subtractive cases (4 and 9) for that place.
- Concatenate the four lookups in order.

## Bugs hit while implementing
- Used (num/100)%100 instead of (num/100)%10 to isolate the hundreds digit. %100 didn't strip the thousands digit still folded in, so for a number like 1994 this produced an out-of-bounds index (19) into a 10-entry table - undefined behavior with vector::operator[].
- Fix: mod by 10, not 100, to isolate a single digit's value (0-9).

## Optimization pass (matches Attempts entries in Notion)
- Pass 1: lookup table declared as a plain (non-static) vector<vector<string>>, rebuilt on every function call - 15ms runtime, beat 5.42%.
- Pass 2: made the table static const so it is constructed once instead of on every call, removing repeated heap allocation across LeetCode's 3999 test cases - 3ms runtime, beat 65.60%.
