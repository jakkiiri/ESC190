# Implement Binary Search Deluxe (Question 4)

def binary_search_deluxe_left(L, target):
    # Return the index of the first occurrence of target in L.
    # Assume target is in L
    left = 0
    right = len(L) - 1
    while left <= right:
        mid = (left + right) // 2
        if L[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return left

def binary_search_deluxe_right(L, target):
    # Return the index of the last occurrence of target in L
    # Assume target is in L
    left = 0
    right = len(L) - 1
    while left <= right:
        mid = (left + right) // 2
        if (mid == len(L) - 1 or L[mid + 1] > target) and L[mid] == target:
            return mid
        elif L[mid] > target:
            right = mid - 1
        else:
            left = mid + 1

def binary_search_deluxe(L, target):
    return [binary_search_deluxe_left(L, target), binary_search_deluxe_right(L, target)]


if __name__ == "__main__":
    L = [1,2,3,10,10,10,12,12]
    target = 10
    print(binary_search_deluxe(L, target))
