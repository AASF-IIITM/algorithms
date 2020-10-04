const numbers = [99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0];
     
function insertionSort(arr) {
  let sortedArr = [arr[0]]
  for (let i = 1; i < arr.length; i++) {
    for (let j = 0; j < arr.length; j++) {
      if (sortedArr[j] > arr[sortedArr.length]) {
        sortedArr.splice(j, 0, arr[sortedArr.length])
        break
      }
      if (j == sortedArr.length-1) {
        sortedArr.push(arr[sortedArr.length])
        break
      }
    }
  }
  return sortedArr
}
 
console.log(insertionSort(numbers));