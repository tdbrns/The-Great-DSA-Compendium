# Well-Ordered Numbers Algorithm Example
## Function and Parameters
    printWellOrderedNumbers(num, x, n)
* *num (integer)*
    * The current well-ordered number that may be printed when *n* = 0.
* *x (integer)*
    * The number of digits that *num* currently has. Note that *0 < x <= n*.
* *n (integer)*
    * The number of remaining digits that a well-ordered number must have to be printed.
## Example
Let *printWellOrderedNumbers()* be *PWON()*.  
*PWON()* when *n* = 2:  

0. num = 0, x = 0, n = 2
1. PWON(0, 0, 2)  -> recur #1
2. PWON(1, 1, 1)  -> recur #2
3. PWON(12, 2, 0) -> recur #3
4. print 12
5. return to PWON(1, 1, 1)
6. PWON(13, 3, 0) -> recur #3
7. print 13
8. return to PWON(1, 1, 1)
9. PWON(14, 4, 0) -> recur #3
10. print 14
11. return to PWON(1, 1, 1)
12. PWON(15, 5, 0) -> recur #3
13. print 15
14. return to PWON(1, 1, 1)
15. PWON(16, 6, 0) -> recur #3
16. print 16
17. return to PWON(1, 1, 1)
18. PWON(17, 7, 0) -> recur #3
19. print 17
20. return to PWON(1, 1, 1)
21. PWON(18, 8, 0) -> recur #3
22. print 18
23. return to PWON(1, 1, 1)
24. PWON(19, 9, 0) -> recur #3
25. print 19
26. return to PWON(1, 1, 1)
27. return to PWON(0, 0, 2)
28. PWON(2, 2, 1)  -> recur #2
29. PWON(23, 3, 0) -> recur #3
30. print 23
31. return to PWON(2, 2, 1)
32. PWON(24, 4, 0) -> recur #3
33. print 24
34. return to PWON(2, 2, 1)...