# Module importieren
import re
import sys

# Input-datei lesen und Unterstriche umwandeln
with open(sys.argv[1], "r", encoding="utf-8") as phrase:
    for line in phrase.readlines():
        word = line.replace('_', '[\S]+')

# Mit dem text vergleichen
with open(r'text.txt', 'r', encoding="utf-8") as file:
    result = re.findall(word, file.read().lower())
    for satz in result:
        print(f"{satz}\n")
