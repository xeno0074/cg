from typing import List


def lower_bound(arr: List, x: int) -> int:
    left = 0
    right = len(arr)

    while left < right:
        mid = (left + right) // 2

        if arr[mid] >= x:
            right = mid - 1
        else:
            left = mid + 1

    return left


def upper_bound(arr: List, x: int) -> int:
    left = 0
    right = len(arr)

    while left < right:
        mid = (left + right) // 2

        if arr[mid] > x:
            right = mid
        else:
            left = mid + 1

    return left


def main():
    arr: List = [5, 5, 5, 6, 6, 6, 7, 7]

    lower_index = lower_bound(arr, 6)
    print(lower_index)

    upper_index = upper_bound(arr, 6)
    print(upper_index)


if __name__ == '__main__':
    main()
