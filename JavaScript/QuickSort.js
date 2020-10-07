function quickSort(list) {
	if (list.length <= 1) { 
		return list;
	} else {

		var left = [];
		var right = [];
		var newList = [];
		var pivot = list.pop();
		var length = list.length;

		for (var i = 0; i < length; i++) {
			if (list[i] <= pivot) {
				left.push(list[i]);
			} else {
				right.push(list[i]);
			}
		}

		return newList.concat(quickSort(left), pivot, quickSort(right));
	}
}

var myList = [-1.5, 0, -2, 5, 1, 2.3, 6 ];

console.log("Original list: " + myList);
var sortedList = quickSort(myList);
console.log("Sorted list: " + sortedList);
