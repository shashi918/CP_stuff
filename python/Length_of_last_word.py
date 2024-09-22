def lengthOfLastWord(s: str) -> int:
    split_string = s.split(" ")
    split_string = [splits for splits in split_string if splits not in [' ', '']]
    print(split_string)
    return len(split_string[len(split_string)-1])

print(lengthOfLastWord("   fly me   to   the moon  "))
