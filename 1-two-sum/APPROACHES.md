# Approaches - Two Sum (LC 1)

## 1. Brute Force (considered, not implemented)
- Time: O(n^2)
- Space: O(1)
- Two nested loops checking every pair for nums[i] + nums[j] == target.
- Constraints (n <= 10^4) mean this would technically still pass (~10^8 ops), but the follow-up question explicitly asks for sub-O(n^2), signaling it's not the intended solution.

## 2. Single-pass Hashmap (chosen)
- Time: O(n)
- Space: O(n)
- unordered_map<int,int> storing value -> index.
- For each number, compute complement = target - nums[i] and check the map BEFORE inserting the current number - avoids accidentally pairing a number with itself and needs only one pass.
- Result: 0ms runtime (beat 100%), 15MB memory (beat 20.47%).

## Syntax notes
- mp.find(key) != mp.end() and mp.count(key) both check existence; find() also gives the value via ->second in one lookup.
- Avoid using mp[key] as an existence check directly - operator[] silently inserts a default entry for missing keys, corrupting the map as a side effect.

## Constraint-reading takeaway
n <= 10^4 with a follow-up asking for better than O(n^2) is a direct signal to reach for a hashmap instead of brute force - see the LC Tricks & Heuristics page in Notion for the general input-size -> complexity heuristic.
