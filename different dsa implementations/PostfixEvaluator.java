import java.util.Scanner;
import java.util.Stack;

public class PostfixEvaluator {
    public static void main(String[] args) {
        String expression = "23 34 * 45 +";
        System.out.println(postfixEvaluator(expression));
    }

    public static int postfixEvaluator(String expression) {
        Scanner scanner = new Scanner(expression);
        Stack<Integer> stack = new Stack<>();

        while (scanner.hasNext()) {
            if (scanner.hasNextInt()) {
                stack.push(scanner.nextInt());
            } else {
                String token = scanner.next();
                int x = stack.pop();
                int y = stack.pop();
                stack.push(eval(y, x, token.charAt(0)));
            }
        }

        return stack.pop();
    }

    public static int eval(int x, int y, char op) {
        switch (op) {
            case '*':
                return x * y;
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '/':
                return x / y;
            case '^':
                return (int) Math.pow(x, y);
            default:
                throw new IllegalArgumentException("Invalid operator: " + op);
        }
    }
}

