import java.io.*;
import java.net.*;

//Receiver

public class UDPServer {
    public static void main(String[] args) {
        DatagramSocket socket = null;
        FileOutputStream fileOutputStream = null;
        try {
            // Server details
            int serverPort = 9876;

            // Create socket
            socket = new DatagramSocket(serverPort);
            byte[] buffer = new byte[1024];

            // Receive file name
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
            socket.receive(packet);
            String fileName = new String(packet.getData(), 0, packet.getLength());

            // Prepare file output stream
            fileOutputStream = new FileOutputStream("received_" + fileName);

            // Receive file content
            while (true) {
                socket.receive(packet);
                byte[] data = packet.getData();
                int length = packet.getLength();
                if (length == 0) break; // End of file
                fileOutputStream.write(data, 0, length);
            }

            System.out.println("File received successfully.");
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (fileOutputStream != null) fileOutputStream.close();
                if (socket != null) socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
