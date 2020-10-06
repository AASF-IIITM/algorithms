
var array_length;
function heapLarge(input, i) {
    var left = 2 * i + 1;
    var right = 2 * i + 2;
    var large = i;

    if (left < array_length && input[left] > input[large]) {
        large = left;
    }

    if (right < array_length && input[right] > input[large])     {
        large = right;
    }

    if (large != i) {
        swap(input, i, large);
        heapLarge(input, large);
    }
}

function swap(input, index_A, index_B) {
    var temp = input[index_A];

    input[index_A] = input[index_B];
    input[index_B] = temp;
}

function heapSort(input) {
    
    array_length = input.length;

    for (var i = Math.floor(array_length / 2); i >= 0; i -= 1)      {
        heapLarge(input, i);
      }

    for (i = input.length - 1; i > 0; i--) {
        swap(input, 0, i);
        array_length--;
      
      
        heapLarge(input, 0);
    }
}

var inputList = [-5, 3, 0, 2.5, -1.5, -1, 4, 1];
heapSort(inputList);
console.log(inputList);
