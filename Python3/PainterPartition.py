class Solution:
    # @param A : integer
    # @param B : integer
    # @param C : list of integers
    # @return an integer
    def paint(self, k, t, ls):

        def possible(time):
            left, count = time, 1
            for l in ls:
                if time < l * t:
                    return False

                left -= l * t
                if left < 0:
                    count += 1
                    left = time - l * t
            return count <= k

        l, h = 0, sum(ls) * t
        while l < h:
            m = (l + h) // 2
            if possible(m):
                h = m 
            else:
                l = m + 1

        return l % 10000003
