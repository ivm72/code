import java.io.*;
import java.net.*;

//Sender

public class UDPClient {
    public static void main(String[] args) {
        DatagramSocket socket = null;
        FileInputStream fileInputStream = null;
        try {
            // Server details
            InetAddress serverAddress = InetAddress.getByName("localhost");
            int serverPort = 9876;

            // Create socket
            socket = new DatagramSocket();

            // Open file to send
            File file = new File("file.txt");
            fileInputStream = new FileInputStream(file);
            byte[] buffer = new byte[1024];
            int bytesRead;

            // Send file name
            String fileName = file.getName();
            socket.send(new DatagramPacket(fileName.getBytes(), fileName.length(), serverAddress, serverPort));

            // Send file content
            while ((bytesRead = fileInputStream.read(buffer)) != -1) {
                socket.send(new DatagramPacket(buffer, bytesRead, serverAddress, serverPort));
            }

            System.out.println("File sent successfully.");
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (fileInputStream != null) fileInputStream.close();
                if (socket != null) socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
