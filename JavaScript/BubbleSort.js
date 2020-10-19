const numbers = [99, 44, 6, 2, 1, 5, 63, -5, 87, 283, 4, 0];
     
function bubbleSort(array) {
  for (let i = 0; i < array.length; i++) {
    for (let j = 0; j < array.length-i; j++) {
      if (array[j] > array[j+1]) {
        let temp = array[j+1]
        array[j+1] = array[j]
        array[j] = temp
      }
    }
  }
}
 
bubbleSort(numbers);
console.log(numbers);