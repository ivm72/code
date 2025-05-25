import java.io.*;
import java.net.*;

public class CalculatorServer {
    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(1234)) {
            System.out.println("Calculator Server is running...");

            while (true) {
                Socket socket = serverSocket.accept();
                System.out.println("Client connected.");

                BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

                String input = in.readLine();
                String[] parts = input.split(" ");
                double result = 0;

                double num1 = Double.parseDouble(parts[0]);
                String op = parts[1];
                double num2 = Double.parseDouble(parts[2]);

                switch (op) {
                    case "+": result = num1 + num2; break;
                    case "-": result = num1 - num2; break;
                    case "*": result = num1 * num2; break;
                    case "/": result = num2 != 0 ? num1 / num2 : Double.NaN; break;
                    default: out.println("Invalid operation"); continue;
                }

                out.println("Result: " + result);
                socket.close();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
