#include <iostream>
#include <bitset>
#include <cmath>
#include <sstream>
using namespace std;

// Function to convert an integer to its binary representation (32-bit)
string intToBinary(unsigned int num) {
    bitset<32> binary(num);
    return binary.to_string();
}

// Function to calculate subnet mask from CIDR
string getSubnetMask(int cidr) {
    string mask = "";
    for (int i = 0; i < 32; ++i) {
        if (i < cidr) {
            mask += "1";
        } else {
            mask += "0";
        }
    }
    return mask;
}

// Function to convert binary string to an IP address (dotted decimal format)
string binaryToIp(const string &binary) {
    stringstream ss;
    for (int i = 0; i < 4; ++i) {
        string byte = binary.substr(i * 8, 8);
        ss << stoi(byte, nullptr, 2);
        if (i != 3) ss << ".";
    }
    return ss.str();
}

// Function to calculate network address
string calculateNetworkAddress(const string &ipBinary, const string &maskBinary) {
    string networkAddressBinary = "";
    for (int i = 0; i < 32; ++i) {
        if (ipBinary[i] == '1' && maskBinary[i] == '1') {
            networkAddressBinary += '1';
        } else {
            networkAddressBinary += '0';
        }
    }
    return networkAddressBinary;
}

int main() {
    // Taking user input for IP and CIDR
    string ip;
    int cidr;
    cout << "Enter an IP address (e.g., 192.168.1.1): ";
    cin >> ip;
    cout << "Enter the CIDR prefix (e.g., 24 for 255.255.255.0): ";
    cin >> cidr;

    // Convert the IP address to binary format
    unsigned int ipInt = 0;
    int octet;
    stringstream ss(ip);
    string token;
    int i = 0;
    while (getline(ss, token, '.')) {
        octet = stoi(token);
        ipInt |= (octet << ((3 - i) * 8)); // Convert each octet to its correct position
        i++;
    }
    string ipBinary = intToBinary(ipInt);
    cout << "\nIP Address in binary: " << ipBinary << endl;

    // Calculate the subnet mask
    string maskBinary = getSubnetMask(cidr);
    cout << "\nSubnet Mask in binary: " << maskBinary << endl;

    // Convert subnet mask binary to dotted decimal notation
    string subnetMaskIp = binaryToIp(maskBinary);
    cout << "\nSubnet Mask in dotted decimal: " << subnetMaskIp << endl;

    // Calculate the network address in binary
    string networkAddressBinary = calculateNetworkAddress(ipBinary, maskBinary);
    cout << "\nNetwork Address in binary: " << networkAddressBinary << endl;

    // Convert network address to dotted decimal format
    string networkAddressIp = binaryToIp(networkAddressBinary);
    cout << "\nNetwork Address in dotted decimal: " << networkAddressIp << endl;

    // Calculate the total number of IP addresses in the subnet
    int totalIpAddresses = pow(2, (32 - cidr));  // 2^(32 - CIDR)
    cout << "\nTotal number of IP addresses: " << totalIpAddresses << endl;

    return 0;
}











