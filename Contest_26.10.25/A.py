from collections import Counter
 
 
def solve():
    s = input()
 
    freq = Counter(s)
    flag = True
 
    for item in freq.values():
 
        if item % 2 != 0 and flag:
            flag = False
        elif item % 2 != 0 and not flag:
            return "no"
 
    return (
        "yes" if (len(s) % 2 == 0 and flag) or (len(s) % 2 != 0 and not flag) else "no"
    )
 

print(solve())