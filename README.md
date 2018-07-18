# StegSick


# Stegify

Usage [after standard gcc compilation] :

./stegifier <image_file>.bmp <text_file>.txt

Resulting file with hidden text will be stored in "stegified" file.

Since only the least significative bit is altered, being M the number of bits of the original image, the possible amount of bits being hidden is given by:

Number of hideable bits = <code> M/8 - 50  </code>




# Unstegify

Usage:

./unstegifier <stegified_file> <target_file>

<target_file> is the file where to store the hidden message.

For academic purposes an 'unstegified' file is stored with the original unedited image.


