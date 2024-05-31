import sys

def xor_string(number, input_string):

    xor_result = ''.join(chr(ord(char) ^ number) for char in input_string)
    
    return xor_result

if len(sys.argv) != 3:
    print("Usage: python xor_script.py <string> <result>")
    sys.exit(1)

input_string = sys.argv[1]
result_string = sys.argv[2]

for number in range(256):
    xor_result = xor_string(number, input_string)
    if xor_result == result_string:
        print("The number is:", number)
        sys.exit(0)


