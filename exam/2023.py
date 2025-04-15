def compute_OPT (cost: list[int], n: int) -> int:
    OPT = [float('inf')] * (n + 1)
    OPT[0] = 0

    for x in range(1, n + 1):
        for s in [1, 2, 3]:
            if x >= s:
                OPT[x] = min(OPT[x], cost[x-1] + OPT[x - s])
    return OPT

def recover_steps(cost, n):
    OPT = compute_OPT(cost, n)
    # Recover Path
    path = []
    while n > 0:
        for s in [1, 2, 3]:
            if n >= s and OPT[n] == cost[n - 1] + OPT[n - s]:
                path.append(s)
                n -= s
                break
    # Make sure to reverse the path
    return path[::-1]

if __name__ == "__main__":
    cost = [100, 40, 60, 20, 80]
    n = 5
    print(recover_steps(cost, n))

