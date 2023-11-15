# Bibliotheken importieren
from PIL import Image
from sys import argv

# Bild einlesen
img = Image.open(argv[1], "r")
# Breite und Höhe des Bildes
w, h = img.size

# Daten des Bildes in einer matrix speichern
mat = list(img.getdata())
mat = [mat[i:i+w] for i in range(0, len(mat), w)]

# sol = Lösungsstring; cur = Koordinaten vom aktuellen Pixel
sol = ""
cur = [0, 0]

# Buchstaben zum Lösungsstring hinzufügen und zum nächstne Pixel finden bis man wieder am Startpunkt (0, 0) ist
while True:
    sol += chr(mat[cur[0]][cur[1]][0])
    if mat[cur[0]][cur[1]][1] == 0 and mat[cur[0]][cur[1]][2] == 0: break
    cur = [(cur[0] + mat[cur[0]][cur[1]][2])%h, (cur[1] + mat[cur[0]][cur[1]][1])%w]

# Lösung ausgeben
print(sol)