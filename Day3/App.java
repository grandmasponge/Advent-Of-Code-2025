
public class App {
    public static void main(String[] args) throws FileNotFoundException {
        File file = new File("./input.txt");
        Scanner scanner = new Scanner(file);
        BigInteger total = BigInteger.ZERO;;

        while (scanner.hasNextLine()) {
            Stack<Integer> stack = new Stack<Integer>();
            String line = scanner.nextLine();

            int drop = line.length() - 12;

            for (int i = 0; i < line.length(); i++) {
                int num = Integer.parseInt(String.valueOf(line.charAt(i)));
                while (drop > 0 && stack.size() > 0 && stack.peek() < num ) {
                    stack.pop();
                    drop--;
                }
                stack.push(num);
            }
            StringBuilder stringBuilder = new StringBuilder();
            for (int i = 0; i < 12; i++) {
                stringBuilder.append(stack.get(i));
            }

            BigInteger value = new BigInteger(stringBuilder.toString());
            System.out.println(value.toString());
            total = total.add(value);
        }

        System.out.println("Total: " + total.toString());
        scanner.close();
    }

}
