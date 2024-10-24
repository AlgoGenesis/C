## IP Address Class

# Description
This program provides a  neat little tool for diving into the basics of IP handling that primarily deals with reading and processing IP addresses to determine their class based on the first octet of the address. 

# Key Elements

Variables:
-sourceString: Input string for the IP address.
-ipAddress: Array to store the extracted IP address octets.
-len, oct, cnt, cnt1, i, buf: Helper variables for string processing and conversion.

Functions:
-extractIpAddress: Extracts the octets from the IP address string and stores them in the ipAddress array.

Control Structures:
-Loops: To iterate through the IP address string and extract octets.
-Conditionals: To check and classify the IP address based on the first octet.

# Algorithm

Initialize Variables:
-Initialize necessary variables for storing the IP address string, individual octets, and counters.

Read IP Address:
-Prompt the user to enter an IP address.
-Read and store the IP address as a string.

Extract Octets:
-Loop through each character of the IP address string.
-Extract individual octets by detecting dots (.) as separators and convert the segments to integers.

Store Octets:
-Store the extracted octets in an array.

Print IP Address:
-Print the formatted IP address using the octet values stored in the array.

Determine IP Class:
-Use the first octet to determine the class of the IP address (A, B, C, D, E) based on predefined ranges.
-Print the determined class.

# Time Complexity
The time complexity of the program is O(n), due to the single pass through the input string  where n is the length of the input IP address string. 