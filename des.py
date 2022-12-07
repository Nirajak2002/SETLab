from Crypto.Cipher import DES
from Crypto import Random
iv = Random.get_random_bytes(8)
des1 = DES.new('01234567'.encode('utf8'), DES.MODE_CFB, iv)
des2 = DES.new('01234567'.encode('utf8'), DES.MODE_CFB, iv)
text = input("Enter msg : ")
text=text.encode('utf8')
cipher_text = des1.encrypt(text)
print("Encrpted message ",cipher_text) 
print("Decrypted Original Message: ",(des2.decrypt(cipher_text)))