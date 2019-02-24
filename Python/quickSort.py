# Implement Quick Sort Algorithm

def quickSort(data, left, right):
    if left < right:
        pivotIdx = partition(data, left, right)

        quickSort(data, left, pivotIdx - 1)
        quickSort(data, pivotIdx + 1, right)


def partition(data, left, right):
    pivotVal = data[left]

    lower = left + 1
    upper = right

    done = False

    while not done:

        while lower <= upper and data[lower] <= pivotVal:
            lower += 1

        while lower <= upper and data[upper] >= pivotVal:
            upper -= 1

        if upper < lower:
            done = True
        else:
            temp = data[lower]
            data[lower] = data[upper]
            data[upper] = temp
        
    temp = data[left]
    data[left] = data[upper]
    data[upper] = temp

    print("Current: ", data)

    return upper


def main():
    list1 = [6, 20, 8, 19, 56, 23, 87, 41, 49, 53]
    print("list: ", list1)
    quickSort(list1, 0, len(list1) - 1)
    print("Result: ", list1)


if __name__ == "__main__":
    main()