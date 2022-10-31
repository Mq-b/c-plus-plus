
from ctypes import*;

dll = windll.LoadLibrary("./add.dll")

print(dll.add(3,4))

dll2 = windll.LoadLibrary("./class");
print(dll2.get_num())

dll2.set_num(dll.add(5,5))

print(dll2.get_num())