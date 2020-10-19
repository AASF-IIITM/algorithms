public class SieveofEratosthenes {
    public static void main(String[] args) {
        int n = 30;
        sieveofEratosthenes(n);
    }

    static void sieveofEratosthenes (int n) {
        boolean[] primes = new boolean[n+1];

        for (int p = 2; p*p <= n; p++) {
            if (primes[p] == false) {
                for (int i = p*p; i <= n; i += p) {
                    primes[i] = true;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (!primes[i]) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
        
    }
}
