# Run-Length Encoding (RLE) Algorithm

## About the Algorithm

**Run-Length Encoding (RLE)** is a simple and efficient lossless data compression technique. It works by identifying consecutive repeating characters (or numbers) in a sequence and compressing them into a single character (or number) followed by its frequency. This reduces the overall size of the data, making it more efficient to store or transmit.

### Example

For example, consider the input string:

The Run-Length Encoded output would be:

In this example, the algorithm compresses consecutive identical characters by replacing them with the character followed by the count of occurrences. This method works well for data with a lot of repetition.

## How It Works

1. Start with the input sequence of characters (or numbers).
2. Traverse the sequence from left to right.
3. For each character, count how many times it repeats consecutively.
4. Output the character followed by its frequency.
5. Continue this process until the entire sequence is encoded.

## Algorithm Efficiency

- **Time Complexity**: O(n), where `n` is the length of the input string. The algorithm processes each character in the string exactly once.
- **Space Complexity**: O(1) (ignoring the output), as the encoding is done in-place if you only care about printing the result, but additional space might be required to store the encoded string.

## Use Cases

- **Image Compression**: RLE is commonly used in file formats like BMP, TIFF, and others where the same data (such as pixel values) repeats multiple times.
- **Data Transmission**: RLE is useful when transmitting repetitive data over a network to reduce bandwidth usage.
- **File Storage**: By reducing the size of repetitive data, RLE can help save storage space.