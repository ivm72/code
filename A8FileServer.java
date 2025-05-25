import java.io.*;
import java.net.*;

public class FileServer {
    public static void main(String[] args) throws Exception {
        ServerSocket server = new ServerSocket(5000);
        System.out.println("Waiting for client...");

        Socket socket = server.accept();
        System.out.println("Client connected!");

        FileInputStream file = new FileInputStream("file.txt");
        OutputStream out = socket.getOutputStream();

        int ch;
        while ((ch = file.read()) != -1) {
            out.write(ch);
        }

        file.close();
        socket.close();
        server.close();
        System.out.println("File sent.");
    }
}
