from hashlib import sha512

text=input("Enter the message : ")

print(sha512(text.encode()).hexdigest())