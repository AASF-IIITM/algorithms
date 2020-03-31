class Main {
    //Added Comments
    //main() to check the Algorithm
    public static void main(String args[]) 
    { 
        Algorithms ob = new Algorithms(); 
        int arr[] = { 1, 5, 8, 13, 16, 32, 44, 58, 70, 97, 104 }; //Binary search requires a sorted array
        int n = arr.length; 
        int x = 97; //Item to be searched
        int result = ob.binarySearch(arr, 0, n - 1, x); 
        if (result == -1) 
            System.out.println("Element not present"); 
        else
            System.out.println("Element found at index " + result); 
    } 
}

class Algorithms { 
    
    //Binary Search Algorithm
    //Works on sorted Arrays only
    //Time Complexity - O(log(n))
    
    //arr[] -> Array to be searched
    //l -> Index of the array from which the search will start
    //r -> Index of the array at which the search will end
    //x -> Element that has to be searched
    int binarySearch(int arr[], int l, int r, int x) 
    { 
        if (r >= l) {                                                           //Checks if array is empty or not
            int mid = l + (r - l) / 2;                                          //Gets the mid element of array
            if (arr[mid] == x)                                                  
                return mid;   //Returns index of middle element if it's the required element
            if (arr[mid] > x) 
                return binarySearch(arr, l, mid - 1, x);
                //Does a recursive search on the left part of middle element since x is smaller than that
            return binarySearch(arr, mid + 1, r, x); 
            //Does a recursive search on the right part of middle element since x is greater than that
        } 
        return -1; //Returns -1 ef element is not found
    } 
}
