word = input()

if len(word) == 1 and word.islower():
    print(word.upper())
elif word[0].islower() and word[1:].isupper():
    print(word[0].upper() + word[1:].lower())
elif word.isupper():
    print(word.lower())
else:
    print(word)