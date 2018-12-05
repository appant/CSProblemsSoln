Word break implementation comparative study: Between iterative and recursive approach.

Have seen this question else where and in leetcode. 

Problem definition based on leetcode. 

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Example:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".


1) How to build?
   g++ wordBreakIterative.cpp wordBreakRecursive.cpp wordBreakTest.cpp -o wordBreakTest
   
2) Run the application. 
   wordBreakTest
   The program uses the input file wordsforproblem.txt that contains a dictionary of words. 

The iterative approach proved approximately 4 times faster than recursive approach for the same input.

Recursive cost: 0.735 secs.
Iterative cost: 0.187 secs.

Recursive cost: 0.797 secs.
Iterative cost: 0.172 secs.

Recursive cost: 0.735 secs.
Iterative cost: 0.188 secs.

Recursive cost: 0.766 secs.
Iterative cost: 0.173 secs.

Recursive cost: 0.813 secs.
Iterative cost: 0.297 secs.

