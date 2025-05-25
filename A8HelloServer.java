import java.io.*;
import java.net.*;

public class HelloServer {
    public static void main(String[] args) throws IOException {
        ServerSocket server = new ServerSocket(12345);
        Socket client = server.accept();
        BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
        PrintWriter out = new PrintWriter(client.getOutputStream(), true);
        out.println("Hello from Server!");
        System.out.println("Received: " + in.readLine());
        client.close();
        server.close();
    }
}
