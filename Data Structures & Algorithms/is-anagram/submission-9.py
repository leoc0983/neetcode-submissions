class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count_s = dict()
        count_t = dict()
        for character in s:
            if character in count_s:
                count_s[character] += 1
            else:
                count_s[character] = 1
        for character in t:
            if character in count_t:
                count_t[character] += 1
            else:
                count_t[character] = 1
        for key in count_s.keys():
            if key not in count_t or count_s[key] != count_t[key]:
                return False
        for key in count_t.keys():
            if key not in count_s or count_s[key] != count_t[key]:
                return False
        return True