# Lab 8 
# Question 2

def mincost(t, denominations):
    if t < 0:
        return float('inf')
    if t == 0:
        return 0
    if t in denominations:
        return 1
    current_min = float('inf')
    for d in denominations:
        current_min = min(current_min, 1 + mincost(t - d, denominations))
    return current_min

print(mincost(8, [1, 4, 5, 10]))

# Part a
# OPT(n) = min (1 + OPT(n - d)), where d are the options in denominations

# greedy algorithm
def compute_OPT(denominations, target):
    OPT = [float('inf')] * (target + 1)
    OPT[0] = 0

    for n in range(1, target + 1):
        for coin in denominations:
            if n >= coin:
                OPT[n] = min(OPT[n], OPT[n - coin] + 1)

    return OPT


def get_coins_used(denominations, target):
    OPT = compute_OPT(denominations, target)
    if OPT[target] == float('inf'):
        return []

    coins_used = []
    while target > 0:
        for coin in denominations:
            if target >= coin and OPT[target] == OPT[target - coin] + 1:
                coins_used.append(coin)
                target -= coin
                break

    return coins_used
    
denominations = [1, 4, 5]
target = 8

OPT = compute_OPT(denominations, target)
print(OPT)
print(f"Minimum number of coins to make {target}c: {OPT[target]}")
print(f"Coins used: {get_coins_used(denominations, target)}")

def paint_house_cost_soln2(houses, col, i):
    '''Return the cost of painting houses
    0, 1, 2, ..., i, with the i-th house painted col
    and the total cost minimized, as well as the solution 
    that corresponds to the minimum cost'''
    if i == 0:
        return houses[col][i], [col]

    cur_min = sum(sum(costs) for costs in houses)
    cur_min_col = -1
    for color in [0, 1, 2]:
        if color == col:
            continue
        cost_color_i, cur_soln = paint_house_cost_soln2(houses, color, i - 1)
        # cost of painting houses 0, ...i-1
        # with the i-1-th house painted with
        # color color
        if cost_color_i < cur_min:
            cur_min = cost_color_i
            cur_min_col = color
            cur_min_soln = cur_soln
        # cur_min: the smaller of the total costs
        # up to i-1, with the two colours that are allowed
        # cur_min_col: the colour that gives the smaller
        # total cost
    sol[i][col] = cur_min_col
    return houses[col][i] + cur_min, cur_min_soln + [col]  # I know that the (i-1)-st house
                                    # should be painted cur_min_col
                                    # if I paint the i-th house col

# Question 3
def canBeSegmented(s, wordDict):
    if not s: # handle empty string
        return True
    for i in range(1, len(s) + 1): # iterate through the string from 0 to the first character
        if s[:i] in wordDict and canBeSegmented(s[i:], wordDict):
            return True
    return False

s = "catsandog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
print(canBeSegmented(s, wordDict))
    