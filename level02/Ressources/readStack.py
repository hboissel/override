import struct
import sys

def parse_pointers(pointers_string):
    pointers = pointers_string.split()
    values = []
    for pointer in pointers:
        if pointer != "(nil)":
            # getting the pointer from a string to an integer in hex
            value = int(pointer, 16)
            # apply little-endian to the value
            value_bytes = struct.pack("<Q", value)
            # decode as ascii if it is possible
            try:
                value_str = value_bytes.decode('ascii')
            except UnicodeDecodeError:
                value_str = "Non-ASCII value"
            values.append(value_str)
        else:
            values.append("(nil)")
    return values

pointers_string = sys.argv[1]
values = parse_pointers(pointers_string)
for value in values:
    print(value)