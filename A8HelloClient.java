
import java.io.*;
import java.net.*;

public class HelloClient {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket("localhost", 12345);
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        out.println("Hello from Client!");
        System.out.println("Received: " + in.readLine());
        socket.close();
    }
}
