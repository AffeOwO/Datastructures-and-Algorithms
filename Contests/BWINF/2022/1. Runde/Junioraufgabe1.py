import sys

# Liste der Vokale (klein/groß)
vokale = list("aeiouäöüAEIOUÄÖÜ")
# Liste in die später bereits gefundene Wortpaare hinzugefügt werden
gefunden = []


# gibt den Ort der maßgeblichen Vokalgruppe in einem Wort zurück
def massgebliche_vokalgruppe(wort):
    # temp ist eine temporäre Variable die einen String mit den Orten verschiedener Vokalgruppen im angegeben Wort enthält.
    # die verschiedenen Vokalgruppen werden mit einem Leerzeichen getrennt damit man diese später aufteilen kann
    temp = "".join(str(index) if i in vokale else " " for index, i in enumerate(wort))
    # eine Liste mit den verschiedenen Orten der Vokalgruppen wird erstellt
    vokalgruppen = temp.split()
    # Falls nur eine Vokalgruppe im Wort vorhanden ist wird der Ort des ersten Vokales der Vokalgruppe im Wort zurückgegeben
    if len(vokalgruppen) == 1:
        return vokalgruppen[0][0]
    # Falls mehrere Vokalgruppen vorhanden sind wird der Ort des ersten Vokals der vorletzten Vokalgruppe zurückgegeben
    elif len(vokalgruppen) > 1:
        return vokalgruppen[-2][0]
    else:
        # Falls kein Vokal im Wort vorhanden ist wird False zurückgegeben
        return False


def regel_1():
    # Regel 1: Die maßgebliche Vokalgruppe und was ihr folgt muss bei beiden Wörtern gleich sein

    # mass_index1 und mass_index2 sind Lokale Variablen welche den Ort des ersten Buchstabes der maßgeblichen Vokalgruppe enthalten
    mass_index1 = massgebliche_vokalgruppe(wort1)
    mass_index2 = massgebliche_vokalgruppe(wort2)
    # Falls die maßgebliche Vokalgruppe und was ihr folgt das selbe bei beiden Wörtern sind wird True zurückgegben
    # anderen falls wird False zurückgegeben
    if wort1[int(mass_index1):] == wort2[int(mass_index2):]:
        return True
    return False


def regel_2():
    # Regel 2: Die Länge des Wortes nach der maßgeblichen Vokalgruppe ist mindestens halb so lang wie das eigentliche Wort

    # mass_index1 und mass_index2 sind Lokale Variablen welche den Ort des ersten Buchstabes der maßgeblichen Vokalgruppe enthalten
    mass_index1 = massgebliche_vokalgruppe(wort1)
    mass_index2 = massgebliche_vokalgruppe(wort2)
    # Hier wird geprüft ob die hälfte der Länge des Wortes gerundet kleiner oder gleich-groß ist wie die Menge an
    # Buchstaben von der maßgeblichen Vokalgruppe bis zum Ende des Wortes. Die 0.01 wurden addiert da Python in der
    # eingebauten round() Funktion auch bei 0.5 abrundet.
    # Da bei einem Wort von der Länge von 7 Buchstaben aber die maßgebliche Vokalgruppe + was ihr folgt mindestens
    # 3.5 Buchstaben oder mehr sein muss und es keine halben Buchstaben gibt muss dies 4Buchstaben lang sein.
    # Deshalb müssen "halbe" Buchstaben aufgerundet und nicht abgerudnet werden und round() rundet zur nächsten geradeb
    # Zahl auf/ab.
    # 3.51 rundet aber immer auf.
    # Falls dies alles der Fall ist wird True zurückgegeben anderen falls wird False zurückgegeben.
    if round(len(wort1) / 2 + 0.01) <= len(wort1) - int(mass_index1):
        if round(len(wort2) / 2 + 0.01) <= len(wort2) - int(mass_index2):
            return True
    return False


def regel_3():
    # Regel 3: Keines der Wörter darf mit einem anderen Wort enden

    # Falls das erste Wort länger als das zweite Wort ist oder beide gleich lang sind wird nun geprüft ob Regel 3 zutrifft.
    # Falls das zweite Wort länger ist geht es im else Statement weiter.
    if len(wort1) >= len(wort2):
        # Es wird eine Schleife erstellt die so oft geht wie viele Buchstaben in Wort 2 sind
        for i in range(len(wort2)):
            # Es wird nun geprüft ob wort1 mit wort2 endet
            # Dies wird gemacht indem geschaut wird ob der letzte Buchstabe des einen Wortes nicht der gleiche ist wie
            # der des anderen Wortes. Falls beide gleich sind wird ein Buchstabe nach links gegangen usw. . Falls
            # nun alle Buchstaben gleich sind und nie ein Unterschied zu finden war wird False zurückgegeben.
            # Falls es aber mindestens einen unterschiedlichen Buchstaben gab wird True zurückgegeben
            #.lower() wird verwendet um alle Buchstaben klein zu machen beim checken um den Unterschied zwischen u und U zu entfernen usw.
            if wort1[-1 * (i + 1)].lower() != wort2[-1 * (i + 1)].lower():
                return True
    else:
        # Es wird eine Schleife erstellt die so oft geht wie viele Buchstaben in Wort 1 sind
        for i in range(len(wort1)):
            # Es wird nun geprüft ob wort2 mit wort1 endet
            # Dies wird gemacht indem geschaut wird ob der letzte Buchstabe des einen Wortes nicht der gleiche ist wie
            # der des anderen Wortes. Falls beide gleich sind wird ein Buchstabe nach links gegangen usw. . Falls
            # nun alle Buchstaben gleich sind und nie ein Unterschied zu finden war wird False zurückgegeben.
            # Falls es aber mindestens einen unterschiedlichen Buchstaben gab wird True zurückgegeben
            # .lower() wird verwendet um alle Buchstaben klein zu machen beim checken um den Unterschied zwischen u und U zu entfernen usw.
            if wort1[-1 * (i + 1)].lower() != wort2[-1 * (i + 1)].lower():
                return True
    return False


def bereits_gefunden():
    # Prüft ob gegebenes Wortpaar bereits gefunden wurde. Falls nicht dann wird True zurückgegeben, anderen falls False.
    # .lower() wird verwendet um alle Buchstaben klein zu machen.
    if f"|{wort1.lower()}+{wort2.lower()}|" in gefunden or f"|{wort2.lower()}+{wort1.lower()}|" in gefunden:
        return False
    return True


def wortpaar():
    # Prüft ob mindestens eine Vokalgruppe in beiden Wärtern vorhanden ist.
    if massgebliche_vokalgruppe(wort1) and massgebliche_vokalgruppe(wort2):
        # Prüft ob alle Regeln eingehalten wurden und ob das Wortpaar bereits gefunden wurde
        if regel_1() and regel_2() and regel_3() and bereits_gefunden():
            # Falls das Wortpaar noch nciht gefundne wurde wird es nun der Liste mit den gefundenen Wortpaaren hinzugefügt
            # .lower() wird verwendet um alle Buchstaben klein zu machen.
            gefunden.append(f"|{wort1.lower()}+{wort2.lower()}|")
            return True
    return False


# Öffnet die Datei mit den Wörtern. encoding="utf-8" ist verwendet da es sonst zu Problemen mit Sonderzeichen kommen kann
with open(sys.argv[1], encoding="utf-8") as file:
    # Liest Datei
    lines = file.read()
    for wort1 in lines.split("\n"):
        for wort2 in lines.split("\n"):
            if wortpaar():
                # Falls es ein Wortpaar ist wird es nun ausgegeben
                print(f"Wortpaar: {wort1} und {wort2}")