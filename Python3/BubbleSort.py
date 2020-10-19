numbers = [99, 44, 6, 2, 1, 5, 63, -5, 87, 283, 4, 0]

def bubbleSort(array):
  for i in range(0, len(array)):
    for  j in range(0, len(array)-1):
      if array[j] > array[j+1]:
        temp = array[j+1]
        array[j+1] = array[j]
        array[j] = temp

bubbleSort(numbers)
print(numbers)