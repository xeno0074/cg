# https://www.interviewbit.com/problems/gas-station/

class Solution:
    # @param A : tuple of integers
    # @param B : tuple of integers
    # @return an integer
    def canCompleteCircuit(self, A, B):
        N = len(A)

        dx0 = [0] * N
        dx0[0] = A[0] - B[0]

        for i in range(1, N):
            dx0[i] = A[i] - B[i] + dx0[i - 1]

        print("dx0=", end="")
        for x in dx0:
            print(x, end=" ")
        print()

        for initialPos in range(N):
            found = True
            print("-----------------------------------------------------------------")
            print(f"initialPos={initialPos}")

            for j in range(initialPos, N + initialPos):
                index = j % N
                print(f"index={index}")

                leftover = dx0[index] - dx0[initialPos] + dx0[0]

                print(f"leftover_gas={leftover}")

                if leftover < 0:
                    found = False
                    break

            if found:
                return initialPos

        return -1


A = [1, 2, 3, 1, 2, 5, 5]
B = [2, 1, 2, 3, 2, 5, 4]
A = [1, 2]
B = [2, 1]
A = [959, 329, 987, 951, 942, 410, 282, 376, 581, 507, 546, 299, 564, 114, 474, 163, 953, 481, 337,
     395, 679, 21, 335, 846, 878, 961, 663, 413, 610, 937, 32, 831, 239, 899, 659, 718, 738, 7, 209]
B = [862, 783, 134, 441, 177, 416, 329, 43, 997, 920, 289, 117, 573, 672, 574, 797, 512, 887, 571,
     657, 420, 686, 411, 817, 185, 326, 891, 122, 496, 905, 910, 810, 226, 462, 759, 637, 517, 237, 884]

solution = Solution()
print(solution.canCompleteCircuit(A, B))
