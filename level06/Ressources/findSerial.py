#!/usr/bin/python3

import sys

def calculate_serial(login):
    if len(login) <= 5:
        return "Login must be longer than 5 characters"
    
    if any(ord(c) <= 31 for c in login):
        return "Login contains non-printable characters"

    result = (ord(login[3]) ^ 4919) + 6221293
    
    for char in login:
        result += (result ^ ord(char)) % 1337
    
    return result

if len(sys.argv) != 2:
    print(f"Usage: {sys.argv[0]} <login>")
    sys.exit(1)

login = sys.argv[1]
serial = calculate_serial(login)
print(f"Login: {login}")
print(f"Calculated Serial: {serial}")
