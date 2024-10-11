import java.util.Scanner;

public class algo1788{
    private static final int MOD = 1_000_000_000;
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int input = sc.nextInt();
        int PorN;

        int result;
        if(input > 0){
            result = P_fibonacci(input);
            PorN = 1;
        }
        else if(input == 0){
            result = 0;
            PorN = 0;
        }
        else{
            result = N_fibonacci(input);
            if(input % 2 == 0) PorN = -1;
              else PorN = 1;
        }
        System.out.println(PorN);
        System.out.println(result);

        sc.close();
    }

    public static int P_fibonacci(int n){
        if(n == 0) return 0;
        if(n == 1) return 1;
        int a = 0, b = 1;
        for(int i = 2; i <= n; i++){
            int temp = (a + b) % MOD;
            a = b;
            b = temp;
        }
        return b;
    }

    public static int N_fibonacci(int n){
        n = -n;
        if(n == 0) return 0;
        if(n == 1) return 1;
        int a = 0, b = 1;
        for(int i = 2; i <= n; i++){
            int temp = (a - b) % MOD;
            a = b;
            b = temp;
        }
        return Math.abs(b);
    }
}   

