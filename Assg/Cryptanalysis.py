import enchant
d = enchant.Dict("en_US")
message = input('Enter Cipher text: ') 
LETTERS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
actualText=''
actualKey=0
no_of_words=len(message.split())
words=[]
for key in range(26):
   sentence = ''
   word=''
   for letter in message:
      if letter in LETTERS:
         num = LETTERS.find(letter)
         num = num - key
         if num < 0:
            num = num + 26
         sentence = sentence + LETTERS[num]
         word=word+LETTERS[num]
      else:
        if d.check(word):
            words.append(word)
        else:
            words.clear()
        word=''
   if d.check(word):
        words.append(word)
   if len(words)==no_of_words:
        actualText=sentence
        actualKey=key
        words.clear()
   print('Plain text with %s: %s' % (key, sentence))
print('Actual plain text is %s with key:%s' % (actualKey,actualText))