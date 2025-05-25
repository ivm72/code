import java.io.*;
import java.net.*;

public class FileClient {
    public static void main(String[] args) throws Exception {
        Socket socket = new Socket("localhost", 5000);
        InputStream in = socket.getInputStream();
        FileOutputStream file = new FileOutputStream("copy.txt");

        int ch;
        while ((ch = in.read()) != -1) {
            file.write(ch);
        }

        file.close();
        socket.close();
        System.out.println("File received.");
    }
}
