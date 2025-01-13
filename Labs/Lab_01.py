def set_to_10():
    global a
    a = 10

def change_array(arr):
    for i in range(len(arr)):
        arr[i] = 'a'

if __name__ == "__main__":
    a = 5
    set_to_10()
    print(a)
    # initialize array of length 100
    arr = [0] * 100
    change_array(arr)
    print(arr)

# Question 2
# Since it is passed by value, python does not have pointers
# Therefore, global a must be used for the local a inside the function to be the same
# as the global a

# Question 3
# Since arrays are passed by reference, no need for global
# Looping the array and changing each of its elements to 'a' will change the original array