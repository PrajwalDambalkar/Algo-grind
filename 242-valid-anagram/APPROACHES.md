# Approaches - Valid Anagram (LC 242)

## 1. Sort & Compare (considered, not chosen)
- Time: O(n log n)
- Space: O(log n) to O(n) depending on sort implementation
- Sort both strings and compare character by character (or compare sorted strings directly).
- Correct, but slower than necessary since sorting adds a log n factor.

## 2. Frequency Count Array (chosen - optimal)
- Time: O(n)
- Space: O(1) - fixed 26-slot array, independent of input size
- Single pass: increment cnt[s[i]-'a'] and decrement cnt[t[i]-'a'] together.
- Verify all 26 slots equal zero afterward.
- Faster than sorting since it avoids the log n factor entirely.

## Bugs hit while implementing
- Used <> instead of != for the length check (not a valid C++ operator).
- int cnt[26] = 0; is invalid initialization syntax - needs = {0}.
- Verification loop initially checked i < s.size() instead of i < 26, which silently missed mismatches stored at higher letter indices (e.g. s="mm", t="mn" would incorrectly return true).

## Alternative syntax note
Range-based for loop for the verification step:

for (auto c : cnt) {
  if (c != 0) return false;
}
