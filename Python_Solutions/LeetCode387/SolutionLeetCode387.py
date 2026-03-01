def firstUniqChar(str):
    dict = {} # Key: character, Value: count
    for c in str:
        if c in dict:
            dict[c] = dict[c] + 1
        else:
            dict.update({c:1})
    
    for i in range(len(str)):
        if dict[str[i]] == 1:
            return i
        
    return -1 


str1 = "leetcode"
str2 = "loveleetcode"
str3 = "aabb"

print(firstUniqChar(str1)) #0
print(firstUniqChar(str2)) #2
print(firstUniqChar(str3)) #-1
