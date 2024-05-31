import sys

def string_to_hex_little_endian(input_string):
    input_string += '\x00'
    while len(input_string) % 4 != 0:
        input_string += '\x00'

    hex_chunks = []
    for i in range(0, len(input_string), 4):
        chunk = input_string[i:i+4]
        # convert each character to its ASCII value and then to hex
        hex_chunk = ''.join(f'{ord(c):02x}' for c in chunk[::-1])
        hex_chunks.append(hex_chunk)

    return hex_chunks

input_string = sys.argv[1]
hex_list = string_to_hex_little_endian(input_string)
print("Hex representation for stack push (little endian, 32-bit):")
print(' 0x'.join(hex_list[::-1]))

