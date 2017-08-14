Class Substring(object):

    """
    lengthOfLongestSubstring : Returns the length of longest 
                               unique substring.
                               
    """

    def lengthOfLongestSubstring(self, s):
         """
            :type s: str
            :rtype: int
         """
         hmap = []
         count = []
           
         if not s :
             return 0
         for item in s:
             if item not in hmap :
                 hmap.append(item)     
             else :
                count.append(len(hmap))
                del hmap[0:hmap.index(item) + 1]
                hmap.append(item)
         count.append(len(hmap))
         return max(count)
  
def main():
   
    s = "aaapqbpcdef"
    print "Longest SS is " 
    print lengthOfLongestSubstring(s)

if __name__ == '__main__':
    main()
	
