numbers = [99, 44, 6, 2, 1, 5, 63, -5, 87, 283, 460, 4, 0]

def selectionSort(array):
  length = len(array)
  for i in range(0, length):
    # set current index as minimum
    min = i
    temp = array[i]
    for j in range(i+1, length):
      if array[j] < array[min]:
        # update minimum if current is lower that what we had previously
        min = j
    array[i] = array[min]
    array[min] = temp
  return array

selectionSort(numbers)
print(numbers)