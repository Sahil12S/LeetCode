# Implement Merge Sort

def mergeSort(data):
    if (len(data) > 1):
        mid = len(data) // 2
        leftArr = data[:mid]
        rightArr = data[mid:]

        mergeSort(leftArr)
        mergeSort(rightArr)

        i = 0   # left array
        j = 0   # right array
        k = 0   # result array

        while i < len(leftArr) and j < len(rightArr):
            if leftArr[i] < rightArr[j]:
                data[k] = leftArr[i]
                i += 1
            else:
                data[k] = rightArr[j]
                j += 1
            k += 1

        
        if i < len(leftArr):
            data[k] = leftArr[i]
            i += 1
            k += 1

        if j < len(rightArr):
            data[k] = rightArr[j]
            j += 1
            k += 1


def main():
    list1 = [6, 20, 8, 19, 56, 23, 87, 41, 49, 53]
    mergeSort(list1)
    print("Result: ", list1)


if __name__ == "__main__":
    main()