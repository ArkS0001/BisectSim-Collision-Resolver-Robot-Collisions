class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        # data = zip(positions, healths)
        # dictionary = dict(data)
        # s = dict(sorted(dictionary.items()))
        # print(s)
        # return
        left = []
        right = []
        for i in range(len(positions)):
            if directions[i]=='L':
                left.append([positions[i],healths[i],i])
            else: 
                right.append([positions[i],healths[i],i])
        #mc
        left.sort()
        right.sort()
        print(left)
        print(right)
        rem = []
        res = []
    # changed usual binary search more concise using bisect
        for leftPos, leftHealth, leftIndex in left:
            idx = bisect.bisect_right(right, leftPos, key = lambda a:a[0]) - 1
            while idx >= 0 and right[idx][1] < leftHealth: 
                right.pop(idx)
                idx-=1
                leftHealth -= 1 
            if idx >= 0: 
                if right[idx][1] == leftHealth: 
                    right.pop(idx)
                else:
                    right[idx][1] -= 1
            else: 
                rem.append([leftIndex,leftHealth]) 
        print(right,rem)
        for p,h,i in right:             #use bisect.insort here for faster processing
            rem.append([i,h])
        rem.sort()
        for i,h in rem:
            res.append(h) 
        return res


