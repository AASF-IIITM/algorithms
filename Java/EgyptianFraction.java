class GFG { 

	static void printEgyptian(int nr, int dr) { 
		
		if (dr == 0 || nr == 0) { 
			return; 
		} 

		
		if (dr % nr == 0) { 
			System.out.print("1/" + dr / nr); 
			return; 
		} 

		
		if (nr % dr == 0) { 
			System.out.print(nr / dr); 
			return; 
		} 

		
		if (nr > dr) { 
			System.out.print(nr / dr + " + "); 
			printEgyptian(nr % dr, dr); 
			return; 
		} 

		
		int n = dr / nr + 1; 
		System.out.print("1/" + n + " + "); 

		
		printEgyptian(nr * n - dr, dr * n); 
	} 


	public static void main(String[] args) { 
		int nr = 6, dr = 14; 
		System.out.print("Egyptian Fraction Representation of "
				+ nr + "/" + dr + " is\n "); 
		printEgyptian(nr, dr); 
	} 
} 


