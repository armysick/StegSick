
def get_bytes_from_file(filename):
    return open(filename, "rb").read()

# Read bytes from file, store in ba
dentadas = get_bytes_from_file('omegalul.bmp')
ba = bytearray()
ba.extend(dentadas)


# Create an LSB array
bits_array = []
for b in ba:
    bits_array.append(b & 1)
    # 01111001 & 1 = 1
    # 01111000 & 0 = 0


# Write byte by byte from right to left
counter = 0
byte = 0xFF
for bit in bits_array:
    if bit == 1:
        byte |=  1 << counter
        # store 1 in position [7-counter]
    else:
        byte &= ~(1 << counter)
        # store 0 in position [7-counter]

    counter = counter+1  # increment
    if counter == 8:     # next byte / char
        print chr(byte)
        byte = 0xFF
        counter = 0
