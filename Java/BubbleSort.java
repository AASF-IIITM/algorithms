import java.util.Arrays;
import java.util.Scanner;

class BubbleSort {
	
	/**
	 * Method to sort the array
	 * 
	 * @param arr Reference to the array
	 */
	
	public void sort(int[] arr) {

		int length = arr.length; // Length of the array

		for (int i = 0; i < length; i++) {

			boolean hasSwapped = false;

			for (int j = 0; j < length - 1 - i; j++) {

				int a = arr[j];
				int b = arr[j + 1];

				if (a > b) {
					swap(arr, j, j + 1);
					hasSwapped = true; // Denoting that the code has swapped 2 numbers
				}
			}
			if (!hasSwapped) // If there was no swapping, that means the array is sorted and there is no need to continue the loop.
				break;
		}
	}
	
	/**
	 * Swaps the two numbers in the array
	 * 
	 * @param arr Reference to the array
	 * @param i Index of the first number to swap
	 * @param j Index of the second number to swap
	 */

	private void swap(int[] arr, int i, int j) {

		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

class Main {

	public static void main(String[] args) {

		int size;
		Scanner scanner = new Scanner(System.in);

		System.out.print("Enter the size of the array: ");
		size = scanner.nextInt();

		int[] arr = new int[size];

		for (int i = 0; i < size; i++) {
			System.out.print("Enter element #" + (i + 1) + ": ");
			arr[i] = scanner.nextInt();
		}

		scanner.close();

		System.out.println("Unsorted Array: " + Arrays.toString(arr)); // Representing the unsorted array

		BubbleSort bs = new BubbleSort(); // Creating the object of the BubbleSort class
		bs.sort(arr); // Calling the sort method

		System.out.println("Sorted Array: " + Arrays.toString(arr)); // Representing the sorted array
	}
}
