# Modul importieren um Kommandozentralen Argumente entgegenzunehmen
import sys

# "müll" Liste erstellen
trashCons = []
# "nicht-müll" Liste erstellen
biggestCon = []

with open(sys.argv[1]) as f:
    for line in f.readlines():
        cont1, cont2 = line.split()

    # zweiten Container zur "trash" Liste hinzufügen
        trashCons.append(cont2)

    # ersten Container zur "trash" Liste hinzufügen
        biggestCon.append(cont1)
        for i in biggestCon:
        # Bei jedem Container in der "nicht-trash" Liste schauen ob dieser in der "trash" Liste vorhanden ist
            if i in trashCons:
            # Falls dies so ist wird dieser aus der "nicht-trash" Liste entfernt
                biggestCon.remove(i)


# Doppelte Werte entfernen indem man die Liste zu einem Set macht
biggestCon = set(biggestCon)


if len(biggestCon) > 1:
    print("Nicht eindeutig welcher Container der schwerste ist.")
    print(f"Liste der schwersten Container: {' '.join(biggestCon)}")

else:
    print(f"Eindeutig welcher der schwerste Container ist und es ist Container {''.join(biggestCon)}.")