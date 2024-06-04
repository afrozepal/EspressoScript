class Solution(object):
    def longestCommonPrefix(self, strs):
        if (len(strs)<0):
            return ""
        if (len(strs)==1):
            return strs[0]
        pstr=[]
        plength=1000
        for i in range (len(strs)):
            plength =min(plength , len(strs[i]))
        if plength==0:
            return ""
        for stri in range(len(strs)-1):
            if stri>0:
                plength=len(pstr)
                pstr=[]
            for i in range(plength):
                    if (strs[stri][i] == strs[stri+1][i]):
                        pstr.append(strs[stri][i])
                    else:
                        break;
        return ''.join(pstr)