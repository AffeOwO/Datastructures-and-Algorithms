# Bibliothek um Kommando-Zeilen Argumente entgegenzunehmen (in diesem Fall die Eingabe Datei)
import sys


# Prüft ob es 9Uhr frühs ist oder 5Uhr nachmittags.
# 9Uhr frühs -> setzt Variable auf True
# 5Uhr nachmittags -> setzt Variable auf False
# alles andere -> setzt die Variable auf den vorigen Wert
# Die Variable sagt ob die gegebene Zeit in der Arbeitszeit liegt.
def is_arbeitszeit(zeit, aktueller_wert):
    if zeit == 540:
        return True
    elif zeit == 1020:
        return False
    elif zeit % 1440 == 540:
        return True
    elif zeit % 1440 == 1020:
        return False
    else:
        return aktueller_wert


# Verfahren 1: Aufträge nach Reihenfolge annehmen und bearbeiten
def Verfahren_1():
    # Lokale Variablen
    bearbeitete_auftraege = []  # leere Liste die später zuende bearbeitete Aufträge beinhalten wird.
    vorliegende_auftraege = []  # leere Liste die später Aufträge beinhalten wird die zu gegeben Zeitpunkt eingetroffen und unbearbeitet sind.
    wartezeiten = []  # leere Liste welche später Wartezeiten der bearbeiteten Aufträge beinhalten wird.
    am_arbeiten = False  # bool Wert False, welcher auf True gesetzt wird falls im Moment ein Auftrag in Bearbeitung ist.
    arbeitszeit = False  # bool Wert False, welcher auf True ist wenn die Uhrzeit zwischen 9-17Uhr ist.
    aktuelle_zeit = 0  # int Wert 0, welcher die aktuelle Minutenanzahl angibt
    aktueller_auftrag = ""  # leerer String welcher später den aktuellen Auftrag angibt(der der zu dem Zeitpunkt bearbeitet wird)

    # while-Schleife welche endet wenn alle Aufträge bearbeitet wurden.
    while len(bearbeitete_auftraege) != len(daten):
        # fügt Aufträge der Liste vorliegende_auftraege hinzu falls die aktuelle Zeit die selbe ist wie der eingangszeitpunkt
        for fahrrad in daten:
            eingangszeitpunkt1, _ = map(int, fahrrad.split())
            if aktuelle_zeit == eingangszeitpunkt1:
                vorliegende_auftraege.append(fahrrad)

        # Falls kein Auftrag bearbeitet wird und es vorliegende Aufträge gibt, fängt Marc den
        # ersten Auftrag in der Liste der vorliegenden Auftröge an. Dieser wird dann aus dieser Liste entfernt.
        if not am_arbeiten and vorliegende_auftraege:
            aktueller_auftrag = vorliegende_auftraege[0]
            vorliegende_auftraege.remove(aktueller_auftrag)
            eingangszeitpunkt2, dauer = map(int, aktueller_auftrag.split())
            # am_arbeiten wird auf True gesetzt -> heißt dass Marc momentan einen Auftrag bearbeitet
            am_arbeiten = True

        # Checkt ob Marc Arbeitsbeginn oder Arbeitsschluss hat.
        arbeitszeit = is_arbeitszeit(aktuelle_zeit, arbeitszeit)
        # +1 Minute
        aktuelle_zeit += 1

        # Falls er an einem Auftrag arbeitet und auf Arbeit ist wird die verbleibende Dauer des aktuell bearbeiteten
        # Auftrages um eine Minute gekürzt, da eine Minute vergangen ist.
        if am_arbeiten and arbeitszeit:
            dauer -= 1

            # Falls die verbleibende Dauer 0 ist (Auftrag fertig), wird die am_arbeiten Variable auf False gesetzt
            # (heißt dass kein Auftrag momentan bearbeitet wird).
            # Außerdem wird die Differenz zwischen der aktuellen Zeit(Fertigstellung) und des Eingangspunktes berechnet,
            # dies ist die Wartezeit für den Auftrag. Diese wird dann in eine Liste mit allen Wartezeiten hinzugefügt.
            if dauer == 0:
                am_arbeiten = False
                wartezeiten.append(aktuelle_zeit - eingangszeitpunkt2)

                # Der Liste bearbeitete_auftraege kann alles hinzugefügt werden wenn ein Auftrag zu Ende ist, da es in
                # dieser while-Schleife nur um die Anzahl von Elementen in dieser Liste geht.
                # "{aktueller_auftrag} fertig" wird hier hinzugefügt um das Programm verständlicher zu machen.
                bearbeitete_auftraege.append(f"{aktueller_auftrag} fertig")

    # Durchschnittliche Wartezeit und maximale Wartezeit wird berechnet und dann returnt.
    durchschnittliche_wartezeit = sum(wartezeiten) / len(wartezeiten)
    maximale_wartezeit = max(wartezeiten)
    return f"   Durchschnittliche Wartezeit: {durchschnittliche_wartezeit}\n" \
           f"   Maximale Wartezeit: {maximale_wartezeit}"


def Verfahren_2():
    # Gleiche Namen wie in Verfahren_1() mit gleichem Nutzen und gleicher Bedeutung.
    bearbeitete_auftraege = []
    vorliegende_auftraege = []
    wartezeiten = []
    am_arbeiten = False
    arbeitszeit = False
    aktuelle_zeit = 0
    aktueller_auftrag = ""

    # Großteil der Sachen ist gleich wie in Verfahren_1(). Nur der Prozess wie ein neuer Auftrag ausgewählt ist anders.
    while len(bearbeitete_auftraege) != len(daten):
        for fahrrad in daten:
            eingangszeitpunkt1, _ = map(int, fahrrad.split())
            if aktuelle_zeit == eingangszeitpunkt1:
                vorliegende_auftraege.append(fahrrad)

        # Falls kein Auftrag bearbeitet wird und es vorliegende Aufträge gibt, fängt Marc den
        # kürzesten verfügbaren Auftrag an.
        if not am_arbeiten and vorliegende_auftraege:
            # temporäre Listen
            eingangspunkte = []
            auftraege_dauer = []

            # Geht durch die Liste mit vorliegenden Aufträgen durch und splittet diese.
            # die eingangspunkte werden zu der Liste "eingangspunkte" hinzugefügt und die dauer der Aufträge der Liste "auftraege_dauer".
            for auftrag in vorliegende_auftraege:
                temp_eingangszeitpunkt, temp_dauer = map(int, auftrag.split())
                eingangspunkte.append(temp_eingangszeitpunkt)
                auftraege_dauer.append(temp_dauer)
            # min_index beinhaltet den Index-Ort des Auftrages mit der kürzesten Dauer in der Liste "auftraege_dauer"
            min_index = auftraege_dauer.index(min(auftraege_dauer))
            # der aktuelle Auftrag beinhaltet nun den aktuell zu bearbeitenden Auftrag.
            # eingangspunkte[min_index] beinhaltet den eingangszeitpunkt des Auftrages mit der kürzesten Dauer.
            # auftraege_dauer[min_index] beinhaltet die kürzeste Dauer
            # \n ist am Ende des Strings, da die meisten Auftraege eine neue Zeile nach ihr haben in der Textdatei,
            # und diese als \n beim lesen der Datei übersetzt wurde und so auch in der "daten" Liste abgespeichert wurden.
            aktueller_auftrag = f"{eingangspunkte[min_index]} {auftraege_dauer[min_index]}\n"

            # dieser Auftrag wird nun versucht aus der Liste mit den vorliegenden Aufträgen zu entfernen.
            try:
                vorliegende_auftraege.remove(aktueller_auftrag)
            # da manchmal der letzte Auftrag aus der Datei keine neue Zeile nach sich hat, kann es zu einem Value error
            # kommen, da die "daten" Liste dann diesen Auftrag ohne \n abspeichert.
            # Für diesen Fall wird die Variable "aktueller_auftrag" auf den selben String wie oben geändert, aber jetzt
            # ohne das \n.
            # Danach wird der Auftrag entgültig aus der Liste mit den vorliegenden Aufträgen entfernt.
            except ValueError:
                aktueller_auftrag = f"{eingangspunkte[min_index]} {auftraege_dauer[min_index]}"
                vorliegende_auftraege.remove(aktueller_auftrag)

            # eingangszeitpunkt2 enthält den Eingangszeitpunkt des aktuellen Auftrages
            # dauer enthält die verbleibende Dauer des aktuellen Auftrages
            eingangszeitpunkt2, dauer = map(int, aktueller_auftrag.split())
            # am_arbeiten wird auf True gesetzt, da Marc jetzt arbeitet.
            am_arbeiten = True

        arbeitszeit = is_arbeitszeit(aktuelle_zeit, arbeitszeit)
        aktuelle_zeit += 1

        if am_arbeiten and arbeitszeit:
            dauer -= 1
            if dauer == 0:
                am_arbeiten = False
                wartezeiten.append(aktuelle_zeit - eingangszeitpunkt2)
                bearbeitete_auftraege.append("fertig")

    durchschnittliche_wartezeit = sum(wartezeiten) / len(wartezeiten)
    maximale_wartezeit = max(wartezeiten)
    return f"   Durchschnittliche Wartezeit: {durchschnittliche_wartezeit}\n" \
           f"   Maximale Wartezeit: {maximale_wartezeit}"


# Datei einlesen und wichtige Daten einer Liste hinzufügen im Format:'Eingangszeitpunkt Dauer' gespeichert.
with open(sys.argv[1], encoding="utf-8") as file:
    # daten ist die Liste mit den Aufträgen aus der Eingabe-Datei
    daten = file.readlines()
    for i in daten[::-1]:
        # unnötige \n werden aus der Liste entfernt
        if len(i) < 3:
            daten.remove(i)

# Ausgabe der Ergebnisse
print("Verfahren 1: ")
print(Verfahren_1())
print()
print("Verfahren 2: ")
print(Verfahren_2())
